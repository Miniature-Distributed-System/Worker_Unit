#ifndef RECV_PORT_H_
#define RECV_PORT_H_
#include <iostream>
#include "../sender_proc/sender.hpp"

int init_receiver(std::unique_ptr<nlohmann::json>);
#endif
