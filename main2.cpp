#include "mbed.h"

DigitalOut leds[] = {(LED1),(LED2),(LED3),(LED4)};

Serial pc(USBTX, USBRX); // tx, rx


/* 2. Hacer parpadear un LED, indicado por el usuario, con un intervalo de 250 ms. El LED se indica
 *	  mediante un numero (1 a 4) le´ıdo desde la entrada serial.
 */
int main(){
	pc.printf("\n\r Ejercicio 2\n\r");
	pc.printf("Presione 1,2,3 o 4 para prender el LED correspondiente.\n\r");
	int c;
	int n;

    while(1){
    	c = pc.getc();
    	if(c == '\n'){
    		pc.printf("\n\r");
    	}
    	pc.putc(c);

    	if(c >= '1' && c <= '4'){
    		n =  c - '0';
    		n = n - 1;
    		leds[n] = 1;
    		wait(0.25);
    		leds[n] = 0;
    	}

    }
}


