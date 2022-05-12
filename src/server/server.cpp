// Copyright [2022] <@damianWu>

#include "server/server.hpp"

#include "asio/ip/tcp.hpp"

namespace server {

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
