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

namespace crypto::benchmark {

    class Tests
    {
        public:
        Tests(/* args */) {}
        ~Tests() {}

        void show_result(const char* name, unsigned char* buff, size_t size);

        void print_loop_number();

        void aes_ecb();

        void aes_cbc();

        void aes_xts();

        void camellia_ecb();

        void camellia_cbc();

        void des_ecb();

        void des_cbc();

        void des3_ecb();

        void des3_cbc();

    };


} // namespace crypto::bench


#endif