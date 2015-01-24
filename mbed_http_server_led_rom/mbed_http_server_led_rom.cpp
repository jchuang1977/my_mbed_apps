// Do not remove the include below
#include "mbed_http_server_led_rom.h"

#include"EthernetInterface.h"
#include"SDFileSystem.h"
#include"HTTPServer.h"
#include"FsHandler.h"
#include"led_handler.h"
#include"rom.h"
#include "temperature.h"

DigitalOut myled(LED1);
EthernetInterface eth;
HTTPServer  svr;
//SDFileSystem sd(P0_18, P0_17, P0_15, P0_19, "sd");
SDFileSystem sd(p5, p6, p7, p8, "sd");
int main() {
    eth.init("192.168.1.13", "255.255.255.0", "192.168.1.1"); //Use DHCP
    eth.connect();
    HTTPFsRequestHandler::mount("/sd/", "/");
    svr.addHandler<HTTPFsRequestHandler>("/");   // look for index.html at default

    svr.addHandler<HTTPLedRequestHandler>("/led");
    svr.addHandler<HTTPRomRequestHandler>("/rom");
    svr.addHandler<HTTPTempRequestHandler>("/temp");

    if (!svr.start(80,&eth)) {
                        error("Server not starting !");
                        exit(0);
    }
    while(1) {
                        svr.poll();
                        myled = 1;
                        wait(0.2);
                        myled = 0;
                        wait(0.2);
    }
}
