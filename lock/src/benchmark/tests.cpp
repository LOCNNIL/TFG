#include "tests.h"

#include "mbedtls/md.h"
#include "mbedtls/aes.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/cipher.h"

// #include "define"
#include "crypto/entrolpy_source.h"
#include "uart.h"
#include "benchmark/timing.h"
#include "protocol/protocol.h"
#include "protocol/secrets.h"


namespace crypto::benchmark {

    const unsigned char key[] = {
    0xE7, 0x6B, 0xF1, 0xFA, 0x95, 0x8B, 0x93, 0xE1,
    0x3D, 0x34, 0x27, 0x8a, 0x9d, 0x72, 0x29, 0x42
    };
    const unsigned char standard_private_key[] = {
        0x63, 0x52, 0x66, 0x55, 0x6A, 0x58, 0x6E, 0x32,
        0x72, 0x34, 0x75, 0x37, 0x78, 0x21, 0x41, 0x25
    };
    unsigned char standard_iv[] = {
        0x29, 0x4A, 0x40, 0x4E, 0x63, 0x52, 0x66, 0x55,
        0x6A, 0x58, 0x6E, 0x5A, 0x72, 0x34, 0x75, 0x37
    };
    unsigned char standard_iv1[] = {
    0x29, 0x4A, 0x40, 0x4E, 0x63, 0x52, 0x66, 0x55,
    0x6A, 0x58, 0x6E, 0x5A, 0x72, 0x34, 0x75, 0x37
    };

    unsigned char encrypted[crypto::protocol::standard_msg_size];
    unsigned char decrypted[crypto::protocol::standard_msg_size];

    unsigned char data_unit_enc[crypto::protocol::standard_msg_size] = { 0 };
    unsigned char data_unit_dec[crypto::protocol::standard_msg_size] = { 0 };

    int result = -1;


    void Tests::show_result(const char* name, unsigned char* buff, size_t size) {
        std::cout << name << ":\n";
        std::cout << "bytes: ";
        for (size_t i = 0; i < size; i++) {
            std::cout << int(buff[i]) << " ";
        }
        std::cout << std::endl;
    }

    void Tests::aes_ecb() {
        unsigned char message[] = { "testing-AES-ECB" };

        std::cout << "\nStart process\n";

        mbedtls_aes_context aes_ctx;
        mbedtls_aes_init(&aes_ctx);

        std::cout << "message >>> " << message << std::endl;

        show_result("message", message, crypto::protocol::standard_msg_size);

        result = mbedtls_aes_setkey_enc(&aes_ctx, standard_private_key, crypto::protocol::keybits);
        {
            crypto::benchmark::Timer tim;
            result = mbedtls_aes_crypt_ecb(&aes_ctx, MBEDTLS_AES_ENCRYPT, message, encrypted);
        }
        show_result("encrypted", encrypted, crypto::protocol::standard_msg_size);


        result = mbedtls_aes_setkey_dec(&aes_ctx, standard_private_key, crypto::protocol::keybits);
        {
            crypto::benchmark::Timer tim;
            result = mbedtls_aes_crypt_ecb(&aes_ctx, MBEDTLS_AES_DECRYPT, encrypted, decrypted);
        }
        show_result("decrypted", decrypted, crypto::protocol::standard_msg_size);

        std::cout << "decrypted message >>> " << decrypted << std::endl;

        mbedtls_aes_free(&aes_ctx);
        std::cout << "End process\n";
    }

    void Tests::aes_cbc() {
        unsigned char message[] = { "testing-AES-CBC" };
        unsigned char standard_iv[] = {
            0x29, 0x4A, 0x40, 0x4E, 0x63, 0x52, 0x66, 0x55,
            0x6A, 0x58, 0x6E, 0x5A, 0x72, 0x34, 0x75, 0x37
        };
        unsigned char standard_iv1[] = {
            0x29, 0x4A, 0x40, 0x4E, 0x63, 0x52, 0x66, 0x55,
            0x6A, 0x58, 0x6E, 0x5A, 0x72, 0x34, 0x75, 0x37
        };
        std::cout << "\nStart process\n";

        mbedtls_aes_context aes_ctx;
        mbedtls_aes_init(&aes_ctx);

        std::cout << "message >>> " << message << std::endl;

        show_result("message", message, crypto::protocol::standard_msg_size);

        result = mbedtls_aes_setkey_enc(&aes_ctx, standard_private_key, crypto::protocol::keybits);
        {
            crypto::benchmark::Timer tim;
            result = mbedtls_aes_crypt_cbc(&aes_ctx, MBEDTLS_AES_ENCRYPT,
                crypto::protocol::standard_msg_size, standard_iv, message, encrypted);
        }
        show_result("encrypted", encrypted, crypto::protocol::standard_msg_size);


        result = mbedtls_aes_setkey_dec(&aes_ctx, standard_private_key, crypto::protocol::keybits);
        {
            crypto::benchmark::Timer tim;
            result = mbedtls_aes_crypt_cbc(&aes_ctx, MBEDTLS_AES_DECRYPT,
                crypto::protocol::standard_msg_size, standard_iv1, encrypted, decrypted);
        }
        show_result("decrypted", decrypted, crypto::protocol::standard_msg_size);

        std::cout << "decrypted message >>> " << decrypted << std::endl;

        mbedtls_aes_free(&aes_ctx);
        std::cout << "End process\n";
    }

    void  Tests::aes_xts() {
        unsigned char message[] = { "testing-AES-XTS" };

        std::cout << "\nStart process\n";

        mbedtls_aes_xts_context ctx_xts;
        mbedtls_aes_xts_init(&ctx_xts);

        std::cout << "message >>> " << message << std::endl;

        show_result("message", message, crypto::protocol::standard_msg_size);

        result = mbedtls_aes_xts_setkey_enc(&ctx_xts, standard_private_key, crypto::protocol::keybits);
        {
            crypto::benchmark::Timer tim;
            result = mbedtls_aes_crypt_xts(&ctx_xts, MBEDTLS_AES_ENCRYPT,
                crypto::protocol::standard_msg_size, data_unit_enc,
                message, encrypted);
        }
        show_result("encrypted", encrypted, crypto::protocol::standard_msg_size);


        result = mbedtls_aes_xts_setkey_dec(&ctx_xts, standard_private_key, crypto::protocol::keybits);
        {
            crypto::benchmark::Timer tim;
            result = mbedtls_aes_crypt_xts(&ctx_xts, MBEDTLS_AES_DECRYPT,
                crypto::protocol::standard_msg_size, data_unit_dec,
                encrypted, decrypted);
        }
        show_result("decrypted", decrypted, crypto::protocol::standard_msg_size);

        std::cout << "decrypted message >>> " << decrypted << std::endl;

        mbedtls_aes_xts_free(&ctx_xts);
        std::cout << "End process\n";
    }
}