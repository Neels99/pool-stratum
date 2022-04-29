#pragma once

#include <iostream>
#include "stratum_protocol.h"


class Stratum : public StratumProtocol
{
public:
    Stratum(boost::asio::io_context& context);

    json MiningSubscribe(const std::string &miner_info)
    {
        std::cout << "mining.subscribe called: " << miner_info << std::endl;
        json res;
        return res;
    }
};