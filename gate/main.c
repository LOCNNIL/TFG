#include <stdio.h>
#include "pico/stdio.h"
#include "pico/stdlib.h"

int main(){
	stdio_init_all();

	gpio_init(25);
	gpio_set_dir(25, GPIO_OUT);

	char userInput;

	while(1){
		printf("Command 1 = on or 0 = off \n");
		userInput = getchar();
		if(userInput == '1'){
			gpio_put(25, 1);
			printf("LED switched on!\n");
		}else if(userInput == '0'){
			gpio_put(25, 0);
			printf("LED switched off!\n");
		}else{
			printf("Invalid Input \n");
		}
	}
}

