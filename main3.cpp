#include "mbed.h"

PwmOut leds[] = {(LED1),(LED2),(LED3),(LED4)};

/*  3. Utilizando la clase PwmOut2 , variar la intensidad del LED 1 desde apagado (0) hasta la m´axima
 *	   intensidad (1). La intensidad debe cambiar cada milisegundo. Configurar el LED 4 para que se
 *	   prenda cuando el LED 1 llegue a su m´axima intensidad, y se apague cuando la intensidad llegue
 *	   nuevamente a cero.
 */

int main() {

    while(1){
    	double i;

    	for(i = 0; i <= 1 ;i = i + 0.1){
    		leds[0] = i;
    		wait(0.25);
    	}
    	leds[3] = 1.0;
    	for(i = 1; i >= 0 ;i = i - 0.1){
    		leds[0] = i;
    	 	wait(0.25);
    	}
    	leds[3] = 0.0;
    }
}
