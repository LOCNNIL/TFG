#include "uart.h"
// #include <cstdint>

namespace crypto::serial
{
    uint8_t Uart::num=0;

        // Uart::Uart(uart_inst_t *uart_id, uint8_t TX, uint8_t RX, uint16_t baud=115200)

        Uart::Uart([[maybe_unused]] int *uart_id=0, uint8_t TX=6, uint8_t RX=7, [[maybe_unused]]  int baud=115200) :
        tx(TX), rx(RX)
    {
        // static_assert(uart_id!=NULL, "Error uart channel");
        // static_assert((ch >= 0 && ch <= 1), "Wrong uart channel value\n");
        // static_assert(bauds_array.end() != std::find(bauds_array.begin(), bauds_array.end(), baud), "Bad baud-rate value\n");
        // static_assert((tx_pins.end() != std::find(tx_pins.begin(), tx_pins.end(), TX)), "Invalid TX pin\n");
        // static_assert((rx_pins.end() != std::find(rx_pins.begin(), rx_pins.end(), RX)), "Invalid RX pin\n");
        // channel = uart_id;
        // uart_init(uart_id, baud);
        // gpio_set_function(tx, GPIO_FUNC_UART);
        // gpio_set_function(rx, GPIO_FUNC_UART);  
    }

    Uart::~Uart()
    {
    }
} // namespace dev
