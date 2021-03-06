#pragma once

#include <client.hpp>
#include <server.hpp>
#include <boost/asio.hpp>
#include <boost/asio/buffer.hpp>

#include <memory>
using namespace jsonrpccxx;

namespace io = boost::asio;
namespace ip = io::ip;

class StratumProtocol : public jsonrpccxx::IClientConnector
{
public:
    StratumProtocol();
    StratumProtocol(boost::asio::io_context& context);

    void listen();
    void read();

    std::string Send(const std::string &request) override;

protected:
    JsonRpc2Server server;
    JsonRpcClient client;

    ip::tcp::acceptor acceptor;
    ip::tcp::resolver resolver;

    std::shared_ptr<ip::tcp::socket> socket;

private:
    io::streambuf buffer;

//    io::steady_timer listen_timer

};
