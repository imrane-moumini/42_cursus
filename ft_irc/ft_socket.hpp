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
#include <sys/select.h>
#include <sys/time.h> 
#include <sys/types.h>  
#include <unistd.h>

// socket function
int i_send_message(int newsockFd, std::string message);
int i_setup_socket(sockaddr_in *sockStructServ, int portNb);
void i_handle_connexion(int newsockFd);
int i_accept_connexion(int sockFd,sockaddr_in *sockStructClient);
#endif