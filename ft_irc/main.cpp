
#include "ft_socket.hpp"
#include <errno.h>

int main(int argc, char *argv[])
{
    int sockFd;
    int newsockFd;
    int portNb;
    
    (void)argc;
    (void) argv;
    struct sockaddr_in sockStructServ;
    struct sockaddr_in sockStructClient;

    portNb = 6697;
    
    /* Initialize socket structure */
    sockFd = i_setup_socket(&sockStructServ, portNb);
    
    while (true)
    {
        
        // accept connexion
        newsockFd = i_accept_connexion(sockFd, &sockStructClient);
        
        //handle connexion
       i_handle_connexion(newsockFd);
    }
    std::cout << "YES \n";
}

// trouver comment faire que irssi se connecte a un autre port que le 6697
// accepter plusieurs requêtes
