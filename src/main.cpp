// Copyright [2022] <@damianWu>

#include <iostream>

#include "server/server.hpp"

int main() {
    try {
        server::run_server(11234);
    } catch (const std::exception& e) {
        std::cerr << "Exception catch in main function with message: "
                  << e.what() << '\n';
    } catch (...) {
        std::cerr << "Unknown type of exception catch in main function" << '\n';
    }
    std::cout << "main() end reached" << '\n';
    return 0;
}
