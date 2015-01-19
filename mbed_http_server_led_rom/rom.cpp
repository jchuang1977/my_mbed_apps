#include"mbed.h"

#include "rom.h"
#include "OneWire.h"
OneWire ow(P1_29);

HTTPRomRequestHandler::HTTPRomRequestHandler(const char* rootPath, const char* localPath, HTTPConnection::HTTPMessage& Msg, TCPSocketConnection& Tcp)
: HTTPRequestHandler(Msg, Tcp)
{
    m_rootPath = rootPath;
    m_localPath = localPath;
    handleRequest();
}

HTTPRomRequestHandler::~HTTPRomRequestHandler()
{
}

int HTTPRomRequestHandler::handleGetRequest()
{
    char outBuf[256] = {};
    bool retval = false;
    int err = 404;
    char romcode[8];             // Array for ROM-Code
    ow.busInit();
    ow.getRomCode(romcode);      // Get ROM-Code
    sprintf(outBuf,"Ds2411 rom is %X.%X.%X.%X.%X.%X.%X.%X \n",romcode[0],romcode[1],romcode[2],romcode[3],romcode[4],romcode[5],romcode[6],romcode[7]);
    startResponse(retval, strlen(outBuf));
    processResponse(strlen(outBuf), outBuf);
    endResponse();
    err = 0;
    return err;
}
int HTTPRomRequestHandler::handlePutRequest()
{
    return 404;
}

int HTTPRomRequestHandler::handlePostRequest()
{
   return 404;
}
