// Copyright [2022] <https://github.com/damianWu>

#ifndef SRC_CLIENT_CLIENT_CLIENT_HPP_
#define SRC_CLIENT_CLIENT_CLIENT_HPP_

#include <string>
#include <string_view>

#include "asio.hpp"
#include "asio/ip/basic_endpoint.hpp"

namespace client {

void run_client(std::string_view host, asio::ip::port_type port);

void communicate(asio::ip::tcp::socket* tcp_socket);

void send_number(int number, asio::ip::tcp::socket* tcp_socket);

std::string receive_reply(asio::ip::tcp::socket* tcp_socket);

int read_number();

void verify_number(int number);

}  // namespace client

#endif  // SRC_CLIENT_CLIENT_CLIENT_HPP_
