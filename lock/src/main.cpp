#include <iostream>
#include <cstdint>
#include <stdio.h>

#include "pico/sync.h"
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/timer.h"
#include "hardware/irq.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

#include "mbedtls/md.h"
#include "mbedtls/aes.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/cipher.h"

// #include "define"
#include "benchmark/timing.h"
#include "benchmark/tests.h"
#include "crypto/entrolpy_source.h"
#include "protocol/protocol.h"
#include "protocol/secrets.h"
#include "state_machine/state_machine.h"
#include "uart/uart.h"

// Symetric Functions to try:
// [x] AES
// [ ] ARC4 
// [ ] Blowfish
// [ ] Camellia
// [ ] DES/3DES
// [ ] GCM (AES-GCM and CAMELLIA-GCM)
// [ ] XTEA


#define LOCK 1U
namespace crypto::target {
#ifdef LOCK
	inline constexpr bool is_compile_target_lock = false;
#else
	inline constexpr bool is_compile_target_lock = true;
#endif

} //namespace target

#define ON 1
#define OFF 0
#define LED_PIN 25


int main() {
	stdio_init_all();

	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);

	// mbedtls_entropy_context entropy;
	// mbedtls_entropy_add_source(&entropy, );
	// mbedtls_entropy_init(&entropy);

	// dev::Uart conn(uart1, 11, 12);

	uart_init(uart1, 115200);
	gpio_set_function(11, GPIO_FUNC_UART);
	gpio_set_function(12, GPIO_FUNC_UART);

	std::string msg = "";

	if constexpr (crypto::target::is_compile_target_lock) {
		msg.append("\nHello uart! Testing from lock\n");
	}
	else {
		msg.append("\nHello uart! Testing from gate\n");
	}

	size_t len = msg.size() + 1;

	std::uint8_t receive[len];

	crypto::benchmark::Tests unity;

	while (1) {
		gpio_put(LED_PIN, ON);
		sleep_ms(5);

		// unity.aes_ecb();
		// unity.aes_cbc();
		// unity.aes_xts();
		// unity.camellia_ecb();
		// unity.camellia_cbc();
		// unity.des_ecb();
		// unity.des_cbc();

		gpio_put(LED_PIN, OFF);
		sleep_ms(5);
	}
}
