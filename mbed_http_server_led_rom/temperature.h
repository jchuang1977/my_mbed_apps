#ifndef __TEMPERATURE_H__
#define __TEMPERATURE_H__
#include "mbed.h"

#include "HTTPRequestHandler.h"
class HTTPTempRequestHandler : public HTTPRequestHandler
{
        std::string m_rootPath;
        std::string m_localPath;
    public:
        HTTPTempRequestHandler(const char* rootPath, const char* localPath, HTTPConnection::HTTPMessage& Msg, TCPSocketConnection& Tcp);
        virtual ~HTTPTempRequestHandler();
        static inline HTTPRequestHandler* create(const char* rootPath, const char* localPath, HTTPConnection::HTTPMessage& msg, TCPSocketConnection& tcp)
        {
             return new HTTPTempRequestHandler(rootPath, localPath, msg, tcp);
        }
        virtual int handleGetRequest();
        virtual int handlePutRequest();
        virtual int handlePostRequest();
};

#endif
