// Copyright [2022] <@damianWu>

#include "server/server.hpp"

#include <iostream>
// #include <ostream>
#include <system_error>

#include "asio/ip/tcp.hpp"

namespace server {

void Session::read() {
    auto self{get_ptr()};

    tcp_socket_.async_read_some(
        asio::buffer(data_, data_.size()),
        [this, self](const std::error_code ec,
                     const std::size_t bytes_transferred) {
            if (!ec) {
                auto number{std::string(data_.data(), bytes_transferred)};
                auto result{fizz_buzz(std::atoi(number.c_str()))};
                std::cout << "number: " << result << std::endl;
                write(result);
            }
        });
}

void Session::write(const std::string_view response) {
    auto self{get_ptr()};

    tcp_socket_.async_write_some(
        asio::buffer(response.data(), response.length()),
        [this, self](const std::error_code ec,
                     const std::size_t bytes_transferred) {
            if (!ec) {
                read();
            }
        });
}

void Session::start() { read(); }

Session::Session(asio::ip::tcp::socket tcp_socket_)
    : tcp_socket_{std::move(tcp_socket_)} {}

std::shared_ptr<Session> Session::get_ptr() { return shared_from_this(); }

[[nodiscard]] std::shared_ptr<Session> Session::create(
    asio::ip::tcp::socket tcp_socket) {
    return std::shared_ptr<Session>(new Session(std::move(tcp_socket)));
}

/* ========================================================================== */

std::string fizz_buzz(const int number) {
    if (number != 0) {
        int mod3{number % 3};
        int mod5{number % 5};

        if (mod3 == 0 && mod5 == 0) {
            return "fizz-buzz";
        }
        if (mod3 == 0) {
            return "fizz";
        }
        if (mod5 == 0) {
            return "buzz";
        }
    }
    return std::to_string(number);
}

}  // namespace server
