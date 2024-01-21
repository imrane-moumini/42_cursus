
#include "ft_socket.hpp"
#include <errno.h>

int main(int argc, char *argv[])
{
    int serveurSockFd;
    int clientSockFd;
    int portNb;
    fd_set current_sockets, ready_sockets;
    (void)argc;
    (void) argv;
    struct sockaddr_in sockStructServ;
    struct sockaddr_in sockStructClient;

    portNb = 6667;
    //initialize my current set of sockets
    

    /* Initialize socket structure */
    serveurSockFd = i_setup_socket(&sockStructServ, portNb);
    FD_ZERO(&current_sockets);
    FD_SET(serveurSockFd, &current_sockets);

    while (true)
    {
        // save current sockets because select is destructive
        std::cout << "BEGINING OF WHILE\n";
        ready_sockets = current_sockets;
        if (select(FD_SETSIZE, &ready_sockets, NULL, NULL, NULL) < 0)
        {
            perror("select error");
            exit(1);
        }
        std::cout << "AFTER SELECT\n";
        for (int i=0; i < FD_SETSIZE; i++)
        {
            if (FD_ISSET(i, &ready_sockets))
            {
                if (i == serveurSockFd){
                    // this is a new connexion
                    // accept connexion
                    clientSockFd = i_accept_connexion(serveurSockFd, &sockStructClient);
                    FD_SET(clientSockFd, &current_sockets);
                } else {
                    //handle connexion
                    std::cout << "SOMEONE IS TALKING\n";
                    i_handle_request(i);
                    //FD_CLR(i, &current_sockets);
                }
            }
        }
    }
}

