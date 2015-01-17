// Do not remove the include below
#include "mbed_rtos_ISR.h"

DigitalOut led1(LED1);

DigitalOut led2(LED2);

InterruptIn btn(P2_8);

Serial pc(USBTX,USBRX);

void btnflip()

{

    led1=!led1;

    wait(10);

    led1=!led1;

}

void uartflip()

{



    led2=!led2;

    pc.getc();

    wait(10);

    led2=!led2;

}

int main() {

    __disable_irq();

    wait(5);

    __enable_irq();

    btn.fall(&btnflip);

    pc.attach(&uartflip);

    NVIC_SetPriority(UART0_IRQn, 5);

    NVIC_SetPriority(EINT3_IRQn, 255);

    while (1)

                        ;

}
