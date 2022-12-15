#ifndef CRYPTO_TIMING_H
#define CRYPTO_TIMING_H

#include "pch.h"
#include "hardware/timer.h"
#include "hardware/irq.h"
#include <iostream>

namespace crypto::benchmark {

    class Timer {
        public:

        enum class type{
            encryption,
            decryption
        };

        type criptograpy_operation;
        static uint32_t loop_counts;
        static double decrypt_time_average;
        static double encrypt_time_average;

        
        private:
        absolute_time_t m_start_time_point;

        public:
        void start() {
            m_start_time_point = get_absolute_time();
        }
        Timer() {
            m_start_time_point = get_absolute_time();
        }
        Timer(type operation) : criptograpy_operation(operation){
            loop_counts++;
            m_start_time_point = get_absolute_time();
        }

        
        ~Timer() { stop(); }

        void stop() {
            auto end_time_point = get_absolute_time();
            int64_t duration = absolute_time_diff_us(m_start_time_point, end_time_point);
            double ms = duration * 0.001;
            std::cout << "Time elapsed: " << duration << "us (" << ms << "ms)\n";

            if(criptograpy_operation == Timer::type::encryption){
                encrypt_time_average = (encrypt_time_average + (double)duration)/loop_counts;
                double ms = encrypt_time_average * 0.001;
                std::cout << "Encryption average time: " << encrypt_time_average << "us (" << ms << "ms)\n";
            }else{
                decrypt_time_average = (decrypt_time_average + (double)duration)/loop_counts;
                double ms = decrypt_time_average * 0.001;
                std::cout << "Decryption average time: " << decrypt_time_average << "us (" << ms << "ms)\n";
            }
        }
    };
}

#endif