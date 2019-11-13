#include "mbed.h"
#include <string.h>

/*
 * 4. Implementar un contador binario de 0 a 15, utilizando los cuatro LEDs de la placa. El intervalo de
 *    incremento es leıdo desde la interface serial (expresado en milisegundos). Debe ser posible cambiar
 *    el intervalo en tiempo de ejecucion.
 */

DigitalOut leds[] = {(LED4),(LED3),(LED2),(LED1)};

Serial pc(USBTX, USBRX); // tx, rx

const int LENGHT = 16;
int v[LENGHT][4] = { {0,0,0,0}, {0,0,0,1}, {0,0,1,0}, {0,0,1,1},
				     {0,1,0,0}, {0,1,0,1}, {0,1,1,0}, {0,1,1,1},
				     {1,0,0,0}, {1,0,0,1}, {1,0,1,0}, {1,0,1,1},
				     {1,1,0,0}, {1,1,0,1}, {1,1,1,0}, {1,1,1,1},
			   };


int main(){
	int c;

	int delay = 1000;
	int t = 0;
	char str[80];
	printf("\n\n\r");
	pc.printf("Ingrese un intervalo en milisegundos y luego presione ';' \n\r");
	while(1){

		for(int i = 0; i <= LENGHT; i++){
			while (pc.readable() == 1){
				c = pc.getc();
				if(c >= '0' && c <= '9'){
					t = c - '0' + t * 10;
					pc.putc(c);
				}
				if(c == ';'){
					if(t > 3000){
						t = 3000;
						printf("\n\r%d ; 	# No sea idiota, el delay maximo es 3000\n\r",t);
					}else{
						printf("\n\r%d ; 	# Cambiando delay\n\r",t);
					}
					delay = t;
					t = 0;
				}
			}

			leds[0] = v[i][0];
			leds[1] = v[i][1];
			leds[2] = v[i][2];
			leds[3] = v[i][3];
			wait_ms(delay);
		}
	}
}
