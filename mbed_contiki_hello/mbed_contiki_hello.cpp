// Do not remove the include below
#include "mbed_contiki_hello.h"

#ifdef __cplusplus

extern "C" {

#endif

#include "contiki.h"

#include "dev/leds.h"

#include "dev/button-sensor.h"

#ifdef __cplusplus

}

#endif

static InterruptIn btn(p5);

static DigitalOut led5(P2_6);

PROCESS(leds_blink_process, "LEDs blink process");

AUTOSTART_PROCESSES(&leds_blink_process);

static void led5toggle()

{

    led5=!led5;

}

PROCESS_THREAD(leds_blink_process, ev, data)

{ 

    static struct etimer timer;

    static uint8_t leds_state = 0;

    btn.fall(&led5toggle);

    PROCESS_BEGIN();

    while(1) {

                        etimer_set(&timer, CLOCK_CONF_SECOND*1);

                        PROCESS_WAIT_EVENT_UNTIL(ev == PROCESS_EVENT_TIMER);

                        leds_off(LEDS_ALL);

                        leds_on(leds_state);

                        leds_state += 1;

    }

    PROCESS_END();

}
//  Auto Added by "SMeshLink SMeshStudio"

