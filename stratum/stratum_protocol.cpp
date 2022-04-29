#include "stratum_protocol.h"

#include <iostream>
#include <string>

std::string StratumProtocol::Send(const std::string &request)
{
    return std::__cxx11::string();
}

StratumProtocol::StratumProtocol(boost::asio::io_context& context) : acceptor(context), resolver(context)
{
    ip::tcp::endpoint listen_ep(ip::tcp::v4(), 1131);

    acceptor.open(listen_ep.protocol());
    acceptor.set_option(io::socket_base::reuse_address(true));
    acceptor.bind(listen_ep);
    acceptor.listen();
}

void StratumProtocol::listen()
{
    acceptor.async_accept([this](const boost::system::error_code& ec, ip::tcp::socket _socket){
        if (!ec)
        {
            socket = std::make_shared<ip::tcp::socket>(std::move(_socket));
            std::cout << "Connected!" << std::endl;
            read();
            listen();
        } else
        {
            std::cout << ec.message() << std::endl;
        }

    });
}

void StratumProtocol::read()
{
    boost::asio::async_read_until(*socket, buffer, '\n', [&](const boost::system::error_code& ec, std::size_t len)
    {
        if (!ec)
        {
            std::string data(boost::asio::buffer_cast<const char *>(buffer.data()), buffer.size());
            std::cout << "Message data: " << data << std::endl;
            json request = json::parse(data);
            request["jsonrpc"] = "2.0";
            std::cout << server.HandleRequest(request.dump()) << std::endl;
//            read();
        } else
        {
            
        }
    });
}
