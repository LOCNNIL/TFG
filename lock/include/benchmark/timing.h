#ifndef CRYPTO_TIMING_H
#define CRYPTO_TIMING_H

#include "pch.h"
#include <iostream>
#include <chrono>

namespace crypto::benchmark {

class Timer {
   private:
    std::chrono::time_point<std::chrono::high_resolution_clock>
        m_start_time_point;

   public:
    Timer() {
        m_start_time_point = std::chrono::high_resolution_clock::now();
    }
    ~Timer() { stop(); }

    void stop() {
        auto end_time_point = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(
                         m_start_time_point)
                         .time_since_epoch()
                         .count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(
                       end_time_point)
                       .time_since_epoch()
                       .count();

        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout << "Time Elapsed: " << duration << "us (" << ms << "ms)\n";
    }
};

}

#endif