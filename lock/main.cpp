#include <stdio.h>
#include <iostream>
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "uart.h"

int main() {
	stdio_init_all();

	gpio_init(25);
	gpio_set_dir(25, GPIO_OUT);

	int count=0;
	
	std::cout << "cpp version: " << __cplusplus <<  count++ << std::endl;

	dev::Uart conn(uart1, 11, 12);

	while (1) {
		std::cout << "Testing print! " <<  count++ << std::endl;
		std::cout << "cpp version: " << __cplusplus <<  count++ << std::endl;
		sleep_ms(1000);
		gpio_put(25, 1);
		printf("LED switched on!\n");
		sleep_ms(1000);
		gpio_put(25, 0);
		printf("LED switched off!\n");
	}
}
