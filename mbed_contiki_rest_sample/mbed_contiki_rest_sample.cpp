#ifdef __cplusplus
extern "C" {
#endif
#include "contiki.h"
#include "contiki-net.h"
#include "rest.h"
#include "dev/leds.h"
//#include "dev/adc-sensors.h"
#include "dev/ds2401.h"
#include <stdio.h>
#ifdef __cplusplus
}
#endif

/*---------------------------------------------------------------------------*/

PROCESS(rest_example, "Sensors Web");
AUTOSTART_PROCESSES(&rest_example);

char temp[100];

RESOURCE(sensors, METHOD_GET, "sensors");
void sensors_handler(REQUEST* request, RESPONSE* response)
{
    int index = 0, ii;
    index += sprintf(temp + index, "ds2411:");
    for (ii = 0; ii < 8; ii++)
		index += sprintf(temp + index, " %02x", ds2401_id[ii]);

    rest_set_header_content_type(response, TEXT_PLAIN);
    rest_set_response_payload(response, (uint8_t*)temp, strlen(temp));

}

RESOURCE(led, (method_t)(METHOD_GET|METHOD_POST | METHOD_PUT), "led");
void led_handler(REQUEST* request, RESPONSE* response)
{
    char color[10];
    char mode[10];
    uint8_t led = 0;
    int success = 1;
    if (rest_get_query_variable(request, "color", color, 10)) 
    {
		if (!strcmp(color,"red")) 
			led = LEDS_RED;
        else if(!strcmp(color,"green"))
            led = LEDS_GREEN;
        else if ( !strcmp(color,"blue") )
            led = LEDS_BLUE;
        else if ( !strcmp(color,"yellow") )
            led = LEDS_YELLOW;
        else
            success = 0;
    } 
    else
		success = 0;

    if (success && rest_get_query_variable(request, "mode", mode, 10)) 
    {
		if (!strcmp(mode, "on")) 
			leds_on(led);                        
		else if (!strcmp(mode, "off"))
			leds_off(led);
		else
			success = 0;                        
    }
    else
         success = 0;

    int index = 0;
    index += sprintf(temp + index, "led is %s,mode is %s \n", color,mode);
    rest_set_header_content_type(response, TEXT_PLAIN);
    rest_set_response_payload(response, (uint8_t*)temp, strlen(temp));
}

PROCESS_THREAD(rest_example, ev, data)
{
    PROCESS_BEGIN();
    rest_init(); 
    rest_activate_resource(&resource_sensors);
    rest_activate_resource(&resource_led);
    PROCESS_END();
}
