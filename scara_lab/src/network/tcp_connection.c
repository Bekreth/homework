#include <arpa/inet.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "tcp_connection.h"

#define MAX_MESSAGE_SIZE 256
#define SERVER_PORT 1270

int socket_file_descriptor = 0;

void create_connection() {
	struct sockaddr_in server_sockaddr_in;

	server_sockaddr_in.sin_family = AF_INET;
	server_sockaddr_in.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_sockaddr_in.sin_port = htons(SERVER_PORT);

	socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
	connect(socket_file_descriptor, (struct sockaddr *)&server_sockaddr_in, sizeof(server_sockaddr_in));
}

#include <stdio.h>
void send_commands(Command commands[], int length) {
	for (int i = 0; i < length; i++) {
		//TODO: Who cares about errors anyway!
		printf(commands[i].text);
		int error_code = write(socket_file_descriptor, commands[i].text, commands[i].length);
	}
}

void destroy_connection() {
	shutdown(socket_file_descriptor, SHUT_WR);
}
