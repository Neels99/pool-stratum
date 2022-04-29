#pragma once

#include <iostream>
#include "stratum_protocol.h"


class Stratum : public StratumProtocol
{
public:
    Stratum(boost::asio::io_context& context);

    boost::asio::deadline_timer _t_send_work;

public:
    // Server:
    json mining_subscribe(const std::string &miner_info)
    {
        std::cout << "mining.subscribe called: " << miner_info << std::endl;

        json res;
        //res = {{"mining.notify", "ae6812eb4cd7735a302a8a9dd95cf71f"}, "", 8};

        _t_send_work.expires_from_now(boost::posix_time::seconds(0));
        _t_send_work.async_wait([&](const boost::system::error_code &ec){
            mining_set_difficulty();
        });

        res = {{{"mining.notify", "ae6812eb4cd7735a302a8a9dd95cf71f"},{}}, "", 8};
//        read();
        return res;
    }

    json mining_subscribe(const std::string &miner_info, std::string job_id)
    {
        return mining_subscribe(miner_info);
    }

//    json mining_subscribe(const std::string &miner_info, std::string job_id)
public:
    // Client:
    json mining_set_difficulty()
    {
        client.CallNotification("set_difficulty", {"123"});
        std::cout << "called mining_set_difficulty" << std::endl;
    }

    json mining_notify()
    {

    }
    
};