// Copyright [2022] <@damianWu>
#ifndef SRC_SERVER_SERVER_SERVER_HPP_
#define SRC_SERVER_SERVER_SERVER_HPP_

#include <memory>
#include <string>
#include <vector>

#include "asio.hpp"

namespace server {

class Session : public std::enable_shared_from_this<Session> {
    // TODO(@damianWu) dodaj const?
    void start();

    std::shared_ptr<Session> get_ptr();

    [[nodiscard]] static std::shared_ptr<Session> create(asio::ip::tcp::socket);

 private:
    explicit Session(asio::ip::tcp::socket);
    void read();
    void write(std::string_view response);

    std::array<char, 1024> data_;
    asio::ip::tcp::socket tcp_socket_;
};

std::string fizz_buzz(int number);

}  // namespace server

#endif  // SRC_SERVER_SERVER_SERVER_HPP_
