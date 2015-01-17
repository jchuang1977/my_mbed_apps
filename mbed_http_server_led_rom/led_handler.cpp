#include"mbed.h"

#include"led_handler.h"

DigitalOut led(LED2);

HTTPLedRequestHandler::HTTPLedRequestHandler(const char* rootPath, const char* localPath, HTTPConnection::HTTPMessage& Msg, TCPSocketConnection& Tcp)
: HTTPRequestHandler(Msg, Tcp)
{
    m_rootPath = rootPath;
    m_localPath = localPath;
    handleRequest();
}

HTTPLedRequestHandler::~HTTPLedRequestHandler()
{
}

int HTTPLedRequestHandler::handleGetRequest()
{
    char outBuf[256] ="OK!\n";;
    bool retval = false;
    int err = 404;
    led=!led;
    startResponse(retval, strlen(outBuf));
    processResponse(strlen(outBuf), outBuf);
    endResponse();
    err = 0;
    return err;
}

int HTTPLedRequestHandler::handlePutRequest()
{
    return 404;
}

int HTTPLedRequestHandler::handlePostRequest()
{
   return 404;
}
