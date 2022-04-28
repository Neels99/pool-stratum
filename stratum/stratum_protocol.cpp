#include "stratum_protocol.h"

#include <iostream>
#include <string>

std::string StratumProtocol::Send(const std::string &request)
{
    return std::__cxx11::string();
}

StratumProtocol::StratumProtocol(boost::asio::io_context& context) : acceptor(context), resolver(context)
{

}

void StratumProtocol::listen()
{
    acceptor.async_accept([this](const boost::system::error_code& ec, ip::tcp::socket _socket){
        if (!ec)
        {
            socket = std::make_shared<ip::tcp::socket>(std::move(_socket));
        } else
        {
            std::cout << "ACCEPTOR ERROR" << std::endl;
        }
        listen();
    });
}

void StratumProtocol::read()
{
    boost::asio::async_read_until(*socket, buffer, '\n', [&](const boost::system::error_code& ec, std::size_t len)
    {
        if (!ec)
        {
            std::string data(buffer_cast<const char *>(buffer.data()), buffer.size());
            server.HandleRequest(data);
            read();
        } else
        {
            
        }
    });
}
