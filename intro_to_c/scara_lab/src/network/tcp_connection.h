#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H

#include "commands.h"

void create_connection();
void destroy_connection();

void send_commands(Commands);

#endif

