#include "stratum.h"

Stratum::Stratum(boost::asio::io_context &context) : StratumProtocol(context)
{
    std::cout << server.Add("mining.subscribe", GetHandle(&Stratum::MiningSubscribe, *this)) << std::endl;
    std::cout << "Added methods to server" << std::endl;
}
