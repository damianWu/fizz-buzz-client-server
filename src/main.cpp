// Copyright [2022] <@damianWu>

#include <clocale>
#include <cstdint>
#include <iostream>

#include "client/client.hpp"
#include "server/server.hpp"

int main() {
    try {
        auto port{9970u};
        server::run_server(port);
        // client::run_client("localhost", port);
    } catch (const std::exception& e) {
        std::cerr << "Exception catch in main function with message: "
                  << e.what() << '\n';
    } catch (...) {
        std::cerr << "Unknown type of exception catch in main function" << '\n';
    }
    std::cout << "main() end reached" << '\n';
    return 0;
}
