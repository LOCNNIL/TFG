#ifndef UART_H
#define UART_H

#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/irq.h"
#include <stdint.h>
#include <string>
#include <vector>
#include <array>


namespace dev
{
    std::array<int, 5> bauds_array = {
        9600,
        19200,
        38400,
        57600,
        115200
    };

    std::array<int, 5> tx_pins={
        1,
        6,
        11,
        16,
        21      
    };

    std::array<int, 5> rx_pins={
        2,
        7,
        12,
        17,
        22
    };

    class Uart
    {
        private:
        static uint8_t num;
        uint8_t tx;
        uint8_t rx;
        // uart_inst_t channel;
        uint16_t baud_rate;
        public:
        Uart(uart_inst_t *uart_id, uint8_t TX, uint8_t RX, uint16_t baud);
        ~Uart();
    };

    Uart::Uart(uart_inst_t *uart_id, uint8_t TX, uint8_t RX, uint16_t baud=115200)
    {
        // static_assert(uart_id!=NULL, "Error uart channel");
        // static_assert((ch >= 0 && ch <= 1), "Wrong uart channel value\n");
        // static_assert(bauds_array.end() != std::find(bauds_array.begin(), bauds_array.end(), baud), "Bad baud-rate value\n");
        // static_assert((tx_pins.end() != std::find(tx_pins.begin(), tx_pins.end(), TX)), "Invalid TX pin\n");
        // static_assert((rx_pins.end() != std::find(rx_pins.begin(), rx_pins.end(), RX)), "Invalid RX pin\n");
        // channel = uart_id;
        tx = TX;
        rx = RX;
        uart_init(uart_id, baud);
        gpio_set_function(tx, GPIO_FUNC_UART);
        gpio_set_function(rx, GPIO_FUNC_UART);  
    }

    Uart::~Uart()
    {
    }
} // namespace dev


#endif