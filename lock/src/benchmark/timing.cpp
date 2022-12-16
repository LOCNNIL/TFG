#include "benchmark/timing.h"

double crypto::benchmark::Timer::decrypt_time_average=0;
double crypto::benchmark::Timer::encrypt_time_average=0;
int64_t crypto::benchmark::Timer::decrypt_time_sum = 0;
int64_t crypto::benchmark::Timer::encrypt_time_sum = 0;
uint32_t crypto::benchmark::Timer::decrypt_loop_counts=0;
uint32_t crypto::benchmark::Timer::encrypt_loop_counts=0;


