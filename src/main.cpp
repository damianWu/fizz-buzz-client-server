// Copyright [2022] <@damianWu>

#include <clocale>
#include <iostream>

// #include "server/server.hpp"
#include "client/client.hpp"

int main() {
    try {
        setlocale(LC_ALL, "polish");
        client::run_client("localhost", 11234);
    } catch (const std::exception& e) {
        std::cerr << "Exception catch in main function with message: "
                  << e.what() << '\n';
    } catch (...) {
        std::cerr << "Unknown type of exception catch in main function" << '\n';
    }
    std::cout << "main() end reached" << '\n';
    return 0;
}
