#ifndef __ROMHANDLER_H__
#define __ROMHANDLER_H__
#include "mbed.h"

#include "HTTPRequestHandler.h"
class HTTPRomRequestHandler : public HTTPRequestHandler
{
        std::string m_rootPath;
        std::string m_localPath;
    public:
        HTTPRomRequestHandler(const char* rootPath, const char* localPath, HTTPConnection::HTTPMessage& Msg, TCPSocketConnection& Tcp);
        virtual ~HTTPRomRequestHandler();
        static inline HTTPRequestHandler* create(const char* rootPath, const char* localPath, HTTPConnection::HTTPMessage& msg, TCPSocketConnection& tcp)
        {
             return new HTTPRomRequestHandler(rootPath, localPath, msg, tcp);
        }
        virtual int handleGetRequest();
        virtual int handlePutRequest();
        virtual int handlePostRequest();
};

#endif //   __LEDHANDLER_H__
