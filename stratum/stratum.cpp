#include "stratum.h"

Stratum::Stratum(boost::asio::io_context &context) : StratumProtocol(context), _t_send_work(context)
{
    std::cout << server.Add("mining.subscribe", GetUncheckedHandle(&Stratum::mining_subscribe, *this)) << std::endl;
    std::cout << "Added methods to server" << std::endl;
}
