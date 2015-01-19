// Do not remove the include below
#include "mbed_rtos_IPC.h"

DigitalOut led(LED1); 
int main() 
{ 
	while(1) 
	{ 
		led=!led;
		wait(1);
	} 
}
//  Auto Added by "SMeshLink SMeshStudio"

