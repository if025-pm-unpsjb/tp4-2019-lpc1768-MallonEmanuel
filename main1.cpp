#include "mbed.h"

Serial pc(USBTX, USBRX); // tx, rx

/* 1. Leer un car´acter desde la entrada serial1. Si es la letra “h”, enviar un saludo (“¡hola!”) a trav´es
 *    de la salida serial
 */
int main() {
	// /dev/ttyACM0
	pc.printf("Presione 'h' \n\r");

	while(1) {
		if(pc.getc() == 'h'){
			pc.printf("Hola!\n\r");
		}
	}
}
