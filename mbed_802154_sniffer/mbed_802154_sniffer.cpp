#include "MxRadio.h"
#include "Queue.h"
DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
Serial pc(USBTX,USBRX);
cMxRadio MxRadio(P0_18, P0_17, P0_15, P0_20, P2_11,P2_12, P2_13);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);
#define CURRENTCHAN 11
#define BAUDRATE 38400
static QUEUE rxqueue=QUEUE();
static char sniffercount=0;
uint8_t i;
uint8_t currentchan;
Timer mytimer;
char usrcmd='p';
char usrcmd2='p';
void setLed(char value)
{
    led1=!led1;
    led2=sniffercount % 2;
    led3=(sniffercount / 2) % 2;
    led4=(sniffercount / 4) % 2;
}

uint8_t* recievehandler(uint8_t len, uint8_t* frm, uint8_t lqi, int8_t ed,uint8_t crc_fail)
{
    setLed(sniffercount++);
    uint8_t packetindex=rxqueue.inqueue();
    if (packetindex==RFQUENEMAX) //maybe full
       return frm;
    rxqueue.RfData[packetindex].length=len;
    memcpy(rxqueue.RfData[packetindex].rbuf,frm,len);
    return frm;
}
void serialhandler()
{
    led1=!led1;
    usrcmd=pc.getc();
    if(usrcmd=='p')//parms
    {
      MxRadio.setState(STATE_OFF,true);
      pc.printf("channel:%d\n",currentchan);
      wait_ms(500);
      MxRadio.begin(currentchan);
    }
    else//-chan
    {
      if (usrcmd2!='p')
      {
        MxRadio.setState(STATE_OFF,true);
		currentchan=usrcmd-'0'+(usrcmd2-'0')*10; //toiny
		pc.printf("channel:%d\n",currentchan);
		wait_ms(500);
		MxRadio.begin(currentchan);
		usrcmd2='p';
		return;
      }

    }
    usrcmd2=usrcmd;
}
int  main()
{
    currentchan=CURRENTCHAN;
    pc.baud(BAUDRATE);
    pc.attach(&serialhandler);
    rxqueue.init_queue();
    pc.printf("MxSniffer 1.0 for 802.15.4\n");
    MxRadio.begin(currentchan);
    MxRadio.attachReceiveFrame(recievehandler);
    led2=led3=led4=1;
    while (1)
    {
		uint8_t packdataindex_tx=rxqueue.dequeue();
		if (packdataindex_tx==RFQUENEMAX) // empty queue
			continue ;
		pc.putc(0x01);
		pc.putc(rxqueue.RfData[packdataindex_tx].length+8);
		unsignedlong passedsecond=mytimer.read_ms()/1000;
		unsignedlong passedmillis=mytimer.read_ms()%1000;
		pc.putc(passedsecond&0xff);
		pc.putc((passedsecond>>8)&0xff);
		pc.putc((passedsecond>>16)&0xff);
		pc.putc((passedsecond>>24)&0xff);
		pc.putc(passedmillis&0xff);
		pc.putc((passedmillis>>8)&0xff);
		pc.putc((passedmillis>>16)&0xff);
		pc.putc((passedmillis>>24)&0xff);
		for (int i=0;i<rxqueue.RfData[packdataindex_tx].length;i++)
			pc.putc(rxqueue.RfData[packdataindex_tx].rbuf[i]);
		pc.putc(0x04);
    }
}
