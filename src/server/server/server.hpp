// Copyright [2022] <@damianWu>
#ifndef SRC_SERVER_SERVER_SERVER_HPP_
#define SRC_SERVER_SERVER_SERVER_HPP_

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "asio.hpp"
#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"

namespace server {

class Server {
 public:
    // TODO(@damianWu) make context const?
    Server(asio::io_context& context, asio::ip::port_type port);

 private:
    void accept();

    asio::ip::tcp::acceptor tcp_acceptor_;
    asio::ip::tcp::socket tcp_socket_;
};

class Session : public std::enable_shared_from_this<Session> {
 public:
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

void run_server(asio::ip::port_type port);

std::string fizz_buzz(int number);

}  // namespace server

#endif  // SRC_SERVER_SERVER_SERVER_HPP_
