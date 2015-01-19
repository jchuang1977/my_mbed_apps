#ifndef __LEDHANDLER_H__
#define __LEDHANDLER_H__
#include "mbed.h"
#include "HTTPRequestHandler.h"
class HTTPLedRequestHandler : public HTTPRequestHandler
{
        std::string m_rootPath;
        std::string m_localPath;
    public:
        HTTPLedRequestHandler(const char* rootPath, const char* localPath, HTTPConnection::HTTPMessage& Msg, TCPSocketConnection& Tcp);
        virtual ~HTTPLedRequestHandler();
        static inline HTTPRequestHandler* create(const char* rootPath, const char* localPath, HTTPConnection::HTTPMessage& msg, TCPSocketConnection& tcp)
        {
             return new HTTPLedRequestHandler(rootPath, localPath, msg, tcp);
        }
        virtual int handleGetRequest();
        virtual int handlePutRequest();
        virtual int handlePostRequest();
};

#endif //   __LEDHANDLER_H__
