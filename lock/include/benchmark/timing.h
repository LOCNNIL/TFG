#ifndef CRYPTO_TIMING_H
#define CRYPTO_TIMING_H

#include "pch.h"
#include "hardware/timer.h"
#include "hardware/irq.h"
#include <iostream>

namespace crypto::benchmark {

class Timer {
   private:
    absolute_time_t m_start_time_point;

   public:
    void start(){
        m_start_time_point = get_absolute_time();
    }
    Timer() {
        m_start_time_point = get_absolute_time();
    }
    ~Timer() {stop();}

    void stop() {
        int64_t duration;
        auto end_time_point = get_absolute_time();
        duration = absolute_time_diff_us(m_start_time_point, end_time_point);
        double ms = duration * 0.001;
        std::cout << "Time elapsed: " << duration << "us (" << ms << "ms)\n";
    }
};

}

#endif