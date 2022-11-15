#ifndef CRYPTO_TOKEN_UART_H
#define CRYPTO_TOKEN_UART_H

#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/irq.h"
#include <stdint.h>
#include <string>
#include <vector>
#include <array>


namespace crypto::serial
{
    // std::array<int, 5> bauds_array = {
    //     9600,
    //     19200,
    //     38400,
    //     57600,
    //     115200
    // };

    // std::array<int, 5> tx_pins = {
    //     1,
    //     6,
    //     11,
    //     16,
    //     21
    // };

    // std::array<int, 5> rx_pins = {
    //     2,
    //     7,
    //     12,
    //     17,
    //     22
    // };

    class Uart
    {
        private:
        static uint8_t num;
        uint8_t tx;
        uint8_t rx;
        // uart_inst_t channel;
        uint16_t baud_rate;
        public:
        Uart(int* uart_id/*=0*/, uint8_t TX/*=6*/, uint8_t RX/*=7*/, int baud);
        // Uart(uart_inst_t *uart_id, uint8_t TX, uint8_t RX, uint16_t baud);
        ~Uart();
    };

} // namespace dev


#endif