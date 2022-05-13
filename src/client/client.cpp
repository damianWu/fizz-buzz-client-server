// Copyright [2022] <@damianWu>

#include "client/client.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>

#include "asio.hpp"
#include "asio/connect.hpp"
#include "asio/io_context.hpp"
#include "asio/registered_buffer.hpp"

namespace {

constexpr int start_interval{1};
constexpr int end_interval{99};

}  // namespace

namespace client {

void run_client(std::string_view host, asio::ip::port_type port) {
    using atcp = asio::ip::tcp;
    try {
        asio::io_context context;
        atcp::socket tcp_socket{context};
        atcp::resolver resolver{context};

        auto end_points{resolver.resolve(host.data(), std::to_string(port))};
        asio::connect(tcp_socket, end_points);

        communicate(&tcp_socket);
    } catch (const std::exception& e) {
        std::cerr << "client::run_client() function throws exception: "
                  << e.what() << "\n";
    }
}

void communicate(asio::ip::tcp::socket* const tcp_socket) {
    while (true) {
        std::cout << "Enter number [" << start_interval << ", " << end_interval
                  << "]: ";

        const int number{read_number()};
        send_number(number, tcp_socket);

        const auto reply_message{receive_reply(tcp_socket)};
        std::cout << "Reply message: " << reply_message << '\n' << std::endl;
    }
}

std::string receive_reply(asio::ip::tcp::socket* const tcp_socket) {
    std::array<char, 1024> reply{};
    // bytes received
    auto bytes_read{tcp_socket->read_some((asio::buffer(reply, reply.size())))};
    return std::string(reply.data(), bytes_read);
}

void send_number(const int number, asio::ip::tcp::socket* const tcp_socket) {
    auto request{std::to_string(number)};
    tcp_socket->write_some(asio::buffer(request, request.length()));
}

int read_number() {
    int number{};
    std::cin >> number;

    verify_number(number);

    return number;
}

void verify_number(const int number) {
    if (std::cin.fail() || number < start_interval || number > end_interval) {
        throw std::runtime_error("client::verify_number() throws exception");
    }
}

}  // namespace client
