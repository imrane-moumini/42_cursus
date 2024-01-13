#ifndef SOCK
#define SOCK

#include <stdio.h>
#include <stdlib.h>

#include <string.h>


#include <iostream>
#include <string>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

// socket function
int i_send_message(int newsockFd, std::string message);
void i_init_and_bind_socket(int sockFd, sockaddr_in *sockStructServ, int portNb);
#endif