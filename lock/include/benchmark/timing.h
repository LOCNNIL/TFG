#ifndef CRYPTO_TIMING_H
#define CRYPTO_TIMING_H

#include "pch.h"
#include "hardware/timer.h"
#include "hardware/irq.h"
#include <iostream>

namespace crypto::benchmark {

class Timer {
   private:
    static absolute_time_t m_start_time_point;

   public:
    Timer() {
        m_start_time_point = get_absolute_time();
    }
    ~Timer() { stop(); }

    void stop() {
        int64_t duration;
        auto end_time_point = get_absolute_time();
        duration = absolute_time_diff_us(m_start_time_point, end_time_point);
        double ms = duration * 0.001;
        std::cout << "Time elapsed: " << duration << "us (" << ms << "ms)\n";
    }
};

/// \tag::get_time[]
// Simplest form of getting 64 bit time from the timer.
// It isn't safe when called from 2 cores because of the latching
// so isn't implemented this way in the sdk
static uint64_t get_time(void) {
    // Reading low latches the high value
    uint32_t lo = timer_hw->timelr;
    uint32_t hi = timer_hw->timehr;
    return ((uint64_t) hi << 32u) | lo;
}

}

#endif