// Copyright [2022] <@damianWu>

#include <sys/types.h>

#include <clocale>
#include <cstdint>
#include <iostream>

#include "client/client.hpp"
#include "server/server.hpp"
#include "server/server/server.hpp"

int main() {
    try {
        uint16_t port{11234};
        server::run_server(port);

        // setlocale(LC_ALL, "polish");
        client::run_client("localhost", port);
    } catch (const std::exception& e) {
        std::cerr << "Exception catch in main function with message: "
                  << e.what() << '\n';
    } catch (...) {
        std::cerr << "Unknown type of exception catch in main function" << '\n';
    }
    std::cout << "main() end reached" << '\n';
    return 0;
}
