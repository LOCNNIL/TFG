#ifndef CRYPTO_TESTS
#define CRYPTO_TESTS

#include "pch.h"
#include <iostream>

#include "pico/sync.h"
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/timer.h"
#include "hardware/irq.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

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

    class Tests
    {
        public:
        Tests(/* args */) {}
        ~Tests() {}

        void show_result(const char* name, unsigned char* buff, size_t size);

        void aes_ecb();

        void aes_cbc();

        void aes_xts();

    };


} // namespace crypto::bench


#endif