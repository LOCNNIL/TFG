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
        static uint32_t decrypt_loop_counts;
        static uint32_t encrypt_loop_counts;
        static double decrypt_time_average;
        static double encrypt_time_average;
        static int64_t decrypt_time_sum;
        static int64_t encrypt_time_sum;

        
        private:
        absolute_time_t m_start_time_point;

        public:
        void start() {
            m_start_time_point = get_absolute_time();
        }

        Timer() {
            start();
        }

        Timer(type operation) : criptograpy_operation(operation){
            if(operation == Timer::type::encryption){
                encrypt_loop_counts++;
            }else{
                decrypt_loop_counts++;
            }
            start();
        }

        ~Timer() { stop(); }

        void stop() {
            auto end_time_point = get_absolute_time();
            int64_t duration = absolute_time_diff_us(m_start_time_point, end_time_point);
            double ms = duration * 0.001;

            if(criptograpy_operation == Timer::type::encryption){
                std::cout << "Encryption time elapsed: " << duration << "us (" << ms << "ms)\n";
                encrypt_time_sum += duration;
                encrypt_time_average = (double)encrypt_time_sum/(double)encrypt_loop_counts;
                double ms = encrypt_time_average * 0.001;
                std::cout << "Encryption average time: " << encrypt_time_average << "us (" << ms << "ms)\n";
            }else{
                std::cout << "Decryption time elapsed: " << duration << "us (" << ms << "ms)\n";
                decrypt_time_sum += duration;
                decrypt_time_average = (double)decrypt_time_sum/(double)decrypt_loop_counts;
                double ms = decrypt_time_average * 0.001;
                std::cout << "Decryption average time: " << decrypt_time_average << "us (" << ms << "ms)\n";
            }
        }
    };
}

#endif