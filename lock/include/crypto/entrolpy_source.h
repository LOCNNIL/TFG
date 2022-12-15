#ifndef CRYPTO_ENTROLPY_SOURCE
#define CRYPTO_ENTROLPY_SOURCE

#include "mbedtls/entropy.h"
#include "hardware/adc.h"

namespace crypto::entrolpy
{

    // class entrolpy_source
    // {
    //     private:
    //     // int m_adc_pin;
    //     // int m_adc_channel;

    //     public:
    //     entrolpy_source(int adc_pin, int channel);
    //     ~entrolpy_source() {}
    // };

    // entrolpy_source::entrolpy_source(int adc_pin=26, int channel=0)
    // {
    //     adc_init();
    //     // Make sure GPIO is high-impedance, no pullups etc
    //     adc_gpio_init(adc_pin);
    //     adc_select_input(channel);
    // }


} // namespace crypto::entrolpy

#endif