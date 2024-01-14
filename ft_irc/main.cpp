
#include "ft_socket.hpp"
#include <errno.h>

int main(int argc, char *argv[])
{
    int sockFd;
    int newsockFd;
    int portNb;
    fd_set current_sockets, ready_sockets;
    (void)argc;
    (void) argv;
    struct sockaddr_in sockStructServ;
    struct sockaddr_in sockStructClient;

    portNb = 6697;
    //initialize my current set of sockets
    
    /* Initialize socket structure */
    sockFd = i_setup_socket(&sockStructServ, portNb);
    FD_ZERO(&current_sockets);
    FD_SET(sockFd, &current_sockets);

    while (true)
    {
        // save current sockets because select is destructive
        ready_sockets = current_sockets;
        if (select(FD_SETSIZE, &ready_sockets, NULL, NULL, NULL) < 0)
        {
            perror("select error");
            exit(1);
        }

        for (int i=0; i < FD_SETSIZE; i++)
        {
            if (FD_ISSET(i, &ready_sockets))
            {
                if (i == sockFd){
                    // this is a new connexion
                    // accept connexion
                    newsockFd = i_accept_connexion(sockFd, &sockStructClient);
                    FD_SET(newsockFd, &current_sockets);
                } else {
                    //handle connexion
                    i_handle_connexion(newsockFd);
                    FD_CLR(i, &current_sockets);
                }
            }
        }
        
        
        
        
    }
    std::cout << "YES \n";
}

// trouver comment faire que irssi se connecte a un autre port que le 6697
// accepter plusieurs requêtes
