#include "mbed_802154.h"
#include "MxRadio.h"
cMxRadio MxRadio(P0_18, P0_17, P0_15, P0_20, P2_11,P2_12, P2_13);
Serial pc(USBTX,USBRX);
const uint16_t  localaddress=2;
const uint16_t  destaddress=1;
const channel_t curchannel=11;
uint8_t lastSendData[110];
uint8_t lastSendDataLen;
uint8_t bufIndex=0;
DigitalOut led(LED1);

void onXmitDone(radio_tx_done_t x)
{
    led!=led;
    if (x!=TX_OK)
    {
			wait_ms(1);
			MxRadio.beginTransmission(destaddress);
			MxRadio.write(lastSendData,bufIndex);
			MxRadio.endTransmission();
    }
}

int main()
{
    MxRadio.begin(curchannel,0xffff,localaddress,true,true,true);
    MxRadio.attachTxDone(onXmitDone);
    while (1)
    {
		   if (pc.readable())
			{
					bufIndex=0;
					while (pc.readable())
					{
								 lastSendData[bufIndex]=(uint8_t)pc.getc();
								 bufIndex++;
								 if (bufIndex>110)
										break;
					}
								MxRadio.beginTransmission(destaddress);
								MxRadio.write(lastSendData,bufIndex);
								MxRadio.endTransmission();
            }

			if (MxRadio.available())
			{
					while(MxRadio.available())
						pc.putc(MxRadio.read());
			}
    }
}
