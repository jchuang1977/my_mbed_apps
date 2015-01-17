#include "mbed.h"

#include "temperature.h"
#include "PCF8591.h"
I2C i2c(p28,p27);
//static int addr = 0x90;  // 0x48 << 1

PCF8591 adc_dac(&i2c);
PCF8591_AnalogOut anaOut(&i2c);
PCF8591_AnalogIn anaIn(&i2c, PCF8591_ADC2);

HTTPTempRequestHandler::HTTPTempRequestHandler(const char* rootPath, const char* localPath, HTTPConnection::HTTPMessage& Msg, TCPSocketConnection& Tcp)
: HTTPRequestHandler(Msg, Tcp)
{
    m_rootPath = rootPath;
    m_localPath = localPath;
    handleRequest();
}

HTTPTempRequestHandler::~HTTPTempRequestHandler()
{
}

int HTTPTempRequestHandler::handleGetRequest()
{
    char outBuf[256] = {};
    bool retval = false;
    int err = 404;
    float ana;
    ana=anaIn;
    //printf("%2.2f ", ana);
    sprintf(outBuf,"temperature is %2.2f\n",ana);
    startResponse(retval, strlen(outBuf));
    processResponse(strlen(outBuf), outBuf);
    endResponse();
    err = 0;
    return err;
}
int HTTPTempRequestHandler::handlePutRequest()
{
    return 404;
}

int HTTPTempRequestHandler::handlePostRequest()
{
   return 404;
}
