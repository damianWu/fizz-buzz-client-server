// Copyright [2022] <@damianWu>

#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>

#include "asio.hpp"
#include "asio/buffered_write_stream.hpp"
#include "asio/connect.hpp"
#include "asio/io_context.hpp"
#include "asio/registered_buffer.hpp"

namespace client {

void run_client(std::string_view host, uint16_t port) {
    try {
        asio::io_context context;
        asio::ip::tcp::socket tcp_socket{context};
        asio::ip::tcp::resolver resolver{context};
        asio::connect(tcp_socket,
                      resolver.resolve({host.data(), std::to_string(port)}));
        while (true) {
            std::cout << "Enter number [1-99]: ";

            int number{};
            std::cin >> number;
            if (std::cin.fail() || number < 1 || number > 99) {
                break;
            }

            auto request{std::to_string(number)};
            // TODO(@damianWu)  z czym związany jest socket? Skąd wie z kim się
            // komunikować?
            tcp_socket.write_some(asio::buffer(request, request.length()));

            std::array<char, 1024> reply;
            // reply length in bytes
            auto reply_length{
                tcp_socket.read_some((asio::buffer(reply, reply.size())))};
            std::cout << "answer: " << '\n';
            auto reply_msg{std::string(reply.data(), reply_length)};
            std::cout << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}
}  // namespace client
