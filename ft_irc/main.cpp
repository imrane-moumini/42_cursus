
#include "ft_socket.hpp"
#include <errno.h>

int main(int argc, char *argv[])
{
    int sockFd;
    int newsockFd;
    int portNb;
    socklen_t clientLen;
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
        clientLen = sizeof(sockStructClient);
        std::cout << "waiting for a request... " << std::endl;
        newsockFd = accept(sockFd, (struct sockaddr *)&sockStructClient, &clientLen);
        std::cout << "i have accepted your request " << std::endl;

        if(newsockFd < 0)
        {
            std::cout << "error connect\n";
            exit(1);
        }
        
        //handle connexion
       i_handle_connexion(newsockFd);
    }
    std::cout << "YES \n";
}

// trouver comment faire que irssi se connecte a un autre port que le 6697
// accepter plusieurs requêtes
