#include <iostream>
#include <cstdint>
#include <stdio.h>

#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "pico/sync.h"
#include "hardware/uart.h"
#include "hardware/irq.h"

// #include "define"
#include "uart.h"


// #define GATE 1U
namespace crypto::target {

#ifdef GATE
    inline constexpr bool is_compile_target_lock = false;
#else
    inline constexpr bool is_compile_target_lock = true;
#endif

} //namespace target


int main() {
	stdio_init_all();

	gpio_init(25);
	gpio_set_dir(25, GPIO_OUT);

	int count = 0;

	std::cout << "cpp version: " << __cplusplus << count++ << std::endl;

	// dev::Uart conn(uart1, 11, 12);

	uart_init(uart1, 115200);
	gpio_set_function(11, GPIO_FUNC_UART);
	gpio_set_function(12, GPIO_FUNC_UART);

	std::string msg="";

	if constexpr (crypto::target::is_compile_target_lock) {
		msg.append("\nHello uart! Testing from lock\n");
	}
	else {
		msg.append("\nHello uart! Testing from gate\n");
	}

	size_t len = msg.size() + 1;

	std::uint8_t receive[len];

	while (1) {

		
		std::cout << "Testing print! " << count++ << std::endl;
		std::cout << "cpp version: " << __cplusplus << count++ << std::endl;

		uart_puts(uart1, msg.c_str());
		// uart_default_tx_wait_blocking();

		uart_read_blocking(uart1, receive, len);
		std::cout << "received: \n" << receive << std::endl;

		sleep_ms(1000);
	}
}
