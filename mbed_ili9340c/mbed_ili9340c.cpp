// Do not remove the include below
#include "mbed_ili9340c.h"

//This code is not ported :)

#include "ILI9340_Driver.h"


#define PIN_MOSI        P0_5
#define PIN_MISO        P0_6
#define PIN_SCK         P0_7

//(mosi,miso,sck,cs,rst,d/c) Create Display Object.
//ILI9340_Display tft = ILI9340_Display(P0_18, P0_17, P0_15, p24, p25, p26);
//ILI9340_Display tft = ILI9340_Display(p5, p6, p7, p8, p25, p26);
ILI9340_Display tft = ILI9340_Display(p11, p12, p13, p14, p25, p26);
//USB Serial - Onboard USB (Requires USB Serial Driver): https://mbed.org/media/downloads/drivers/mbedWinSerial_16466.exe
Serial serial(USBTX, USBRX);
DigitalOut led(LED1);
//Serial String Command Parser
#define NFIELDS (11) //Max Commands
char buf[100]; //change this if you are sending a larger string to the mbed via serial.
char str[16]="hello world";

char* pFields[NFIELDS];
void ParseCommands(char* Buffer, char** pFields, uint32_t numFields, char* delimiter)
{
    char* pString = Buffer;
    char* pField;

    for (uint32_t i=0; i<numFields; i++) {
        pField = strtok(pString, delimiter);
        if (pField != NULL) {
            pFields[i] = pField;
        } else {
            pFields[i] = "";
        }
        pString = NULL; //parse next
    }
    if (strcmp("init", pFields[0]) == 0) {
        //ILI9340_Display tft = ILI9340_Display(p5, p6, p7, p24, p25, p26);
    	ILI9340_Display tft = ILI9340_Display(p5, p6, p7, p8, p25, p26);
        tft.DispInit();
        tft.FillScreen(ILI9340_WHITE);
    }
    if (strcmp("rect", pFields[0]) == 0) {
        //X,Y,X,Y,R,G,B
        tft.DrawRect(atoi(pFields[1]),atoi(pFields[2]),atoi(pFields[3]),atoi(pFields[4]),uint16_t(tft.Colour565(atoi(pFields[5]), atoi(pFields[6]), atoi(pFields[7]))));
    }
    if (strcmp("frect", pFields[0]) == 0) {
        //X,Y,X,Y,R,G,B
        tft.FillRect(atoi(pFields[1]), atoi(pFields[2]), atoi(pFields[3]), atoi(pFields[4]), uint16_t(tft.Colour565(atoi(pFields[5]), atoi(pFields[6]), atoi(pFields[7]))));
    }
    if (strcmp("dline", pFields[0]) == 0) {
        //X,Y,X,Y,R,G,B
        tft.DrawLine(atoi(pFields[1]), atoi(pFields[2]), atoi(pFields[3]), atoi(pFields[4]), uint16_t(tft.Colour565(atoi(pFields[5]), atoi(pFields[6]), atoi(pFields[7]))));
    }
    if (strcmp("circle", pFields[0]) == 0) {
        //X,Y,SIZE,R,G,B
        tft.DrawCircle(atoi(pFields[1]), atoi(pFields[2]), atoi(pFields[3]), uint16_t(tft.Colour565(atoi(pFields[4]), atoi(pFields[5]), atoi(pFields[6]))));
    }
    if (strcmp("px", pFields[0]) == 0) {
        //X,Y,R,G,B
        tft.DrawPixel(atoi(pFields[1]),atoi(pFields[2]),uint16_t(tft.Colour565(atoi(pFields[3]), atoi(pFields[4]), atoi(pFields[5]))));
    }
    if (strcmp("fill", pFields[0]) == 0) {
        //R,G,B
        tft.FillScreen(uint16_t(tft.Colour565(atoi(pFields[1]), atoi(pFields[2]), atoi(pFields[3]))));
    }
    if (strcmp("text", pFields[0]) == 0) {
        //text,String,X,Y,Size,Color
        int i = 0;
        while(pFields[1][i] != 0) {
            if(pFields[1][i] == '_') {
                pFields[1][i] = ' ';   //Replace Char In String (For Spaces)
            }
            i++;
        }
        tft.DrawString(pFields[1], atoi(pFields[2]), atoi(pFields[3]), atoi(pFields[4]), uint16_t(tft.Colour565(atoi(pFields[5]), atoi(pFields[6]), atoi(pFields[7]))));
    }
    if (strcmp("rot", pFields[0]) == 0) {
        tft.SetRotation(atoi(pFields[1]));
    }
}

void echouart()
{
	 //serial.putc(serial.getc());
   // serial.scanf("%s", buf);
    //serial.printf("%s\n",buf);


}

int main(int argc, char* argv[])
{
    //Init display on reset/power up
	//ILI9340_Display tft = ILI9340_Display(p5, p6, p7, p8, p25, p26);
	ILI9340_Display tft = ILI9340_Display(p11, p12, p13, p14, p25, p26);
    tft.DispInit();
    tft.FillScreen(ILI9340_GREEN);
    ////////////////////////////////////////////////////////////////////////////////
    //Serial String Parse Commands Example
    //
    //                    command  txt           vector   font_size  R   G   B
    //Set Text On Screen: "text",  "hello world",20,10,   2,         255,255,255
    //
    //                            command  vector_start  vector_end  R   G   B
    //Creating Rectangle Example: "rect",  20,40,        30,70,      255,255,255
    //
    //These commands are sent from serial to the MBED
    //You can easily work out the other commands by looking above and reading
    //the ones i showed examples for above
    //Note: When command (text), make sure you seperate each word with a _ character
    /////////////////////////////////////////////////////////////////////////////////
    //serial.baud(921600);
    serial.baud(9600);


    //serial.attach(&echouart,SerialBase::RxIrq);
    memset(buf,0,100);
    while (1) {


    	//ParseCommands(buf, pFields, NFIELDS, ",");
    	 tft.DrawString(str,20,10,2,uint16_t(tft.Colour565(255, 255, 255)));
        led=0;
        wait(0.1);
        led=1;
        wait(0.1);

    }
    ////////////////////////////////////////////////////////
}
