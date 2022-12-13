#include "tests.h"

namespace crypto::benchmark {

    const unsigned char standard_private_key[] = {
    0xE7, 0x6B, 0xF1, 0xFA, 0x95, 0x8B, 0x93, 0xE1,
    0x3D, 0x34, 0x27, 0x8a, 0x9d, 0x72, 0x29, 0x42
    };
    const unsigned char standard_private_key_2[] = {
        0x63, 0x52, 0x66, 0x55, 0x6A, 0x58, 0x6E, 0x32,
        0x72, 0x34, 0x75, 0x37, 0x78, 0x21, 0x41, 0x25
    };

    unsigned char message[] = { "testing-AES-ECB" };
    unsigned char encrypted[crypto::protocol::standard_msg_size];
    unsigned char decrypted[crypto::protocol::standard_msg_size];

    int result=-1;


    void Tests::show_result(const char* name, unsigned char* buff, size_t size) {
        std::cout << name << ":\n";
        std::cout << "bytes: ";
        for (size_t i = 0; i < size; i++) {
            std::cout << int(buff[i]) << " ";
        }
        std::cout << std::endl;
    }

    void Tests::aes_ecb() {

        std::cout << "\nStart process\n";

        mbedtls_aes_context aes_ctx;
        mbedtls_aes_init(&aes_ctx);

        std::cout << "message >>> " << message << std::endl;

        show_result("message", message, crypto::protocol::standard_msg_size);

        result = mbedtls_aes_setkey_enc(&aes_ctx, standard_private_key_2, crypto::protocol::keybits);
        {
            crypto::benchmark::Timer tim;
            result = mbedtls_aes_crypt_ecb(&aes_ctx, MBEDTLS_AES_ENCRYPT, message, encrypted);
        }
        show_result("encrypted", encrypted, crypto::protocol::standard_msg_size);


        result = mbedtls_aes_setkey_dec(&aes_ctx, standard_private_key_2, crypto::protocol::keybits);
        {
            crypto::benchmark::Timer tim;
            result = mbedtls_aes_crypt_ecb(&aes_ctx, MBEDTLS_AES_DECRYPT, encrypted, decrypted);
        }
        show_result("decrypted", decrypted, crypto::protocol::standard_msg_size);

        std::cout << "decrypted message >>> " << decrypted << std::endl;

        mbedtls_aes_free(&aes_ctx);
        std::cout << "End process\n";
    }



}