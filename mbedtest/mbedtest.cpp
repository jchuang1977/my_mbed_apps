// Do not remove the include below
#include "mbedtest.h"
#include "PCF8591.h"

I2C i2c(p28,p27);

DigitalOut led(LED2);
static int count=0;
static int addr = 0x90;  // 0x48 << 1

//PCF8591 adc_dac(&i2c_bus, PCF8591_SA0);
PCF8591 adc_dac(&i2c);

PCF8591_AnalogOut anaOut(&i2c);

PCF8591_AnalogIn anaIn(&i2c, PCF8591_ADC3);

int main() 
{ 
	char data[2];
	char value;
	char ch3 = 0x3;
	data[0] = 0x41;
	data[1] = 0xff;
	float ana;


	while(1) 
	{ 
		led=!led;
		if(0)
		{
			if(count%2)
			{
				data[1] = 0xff;
				i2c.write(addr,data,2);
			}
			else
			{
				data[1] = 0x0;
				i2c.write(addr,data,2);
			}
			printf("hello world, id=%d\n",count++);
		}
		else
		{
			    ana=anaIn;                                                    // read A/D value for Channel 1 (potmeter)
			    printf("%2.2f ", ana);

			    anaOut = ana;                                               // write back A/D value to D/A Channel

		}
		wait(1);
	} 
}
//  Auto Added by "SMeshLink SMeshStudio"

