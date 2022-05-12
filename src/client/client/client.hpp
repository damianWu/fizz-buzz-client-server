// Copyright [2022] <@damianWu>

#ifndef SRC_CLIENT_CLIENT_CLIENT_HPP_
#define SRC_CLIENT_CLIENT_CLIENT_HPP_

#include <cstdint>
#include <string_view>

namespace client {

void run_client(std::string_view host, const uint16_t port);

}  // namespace client

#endif  // SRC_CLIENT_CLIENT_CLIENT_HPP_
