#include <iostream>
//#include "include/jsonrpccxx/client.hpp"
//#include "client.hpp"
//#include "stratum_protocol.h"
#include "stratum.h"
using std::cout, std::endl;

int main()
{
    cout << 1 << endl;

    boost::asio::io_context context;

    Stratum stratum(context);
    stratum.listen();

    context.run();
}