#include "ft_socket.hpp"
#include <errno.h>

int i_send_message(int newsockFd, std::string message)
{
    return (write(newsockFd, message.c_str(), message.length()));
}

int i_setup_socket(sockaddr_in *sockStructServ, int portNb)
{
    int sockFd;
    sockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockFd < 0)
    {
        std::cout << "error socket fd\n";
        exit(1);
    }
    
    bzero((char *)sockStructServ, sizeof(*(sockStructServ)));
    sockStructServ->sin_family = AF_INET;
    sockStructServ->sin_addr.s_addr = INADDR_ANY;
    sockStructServ->sin_port = htons(portNb);

    /* Initialize socket structure */
    if (bind(sockFd, (struct sockaddr *) sockStructServ, sizeof(*(sockStructServ))) < 0)
    {
        std::cout << "error binding\n";
        perror ("The following error occurred\n");
        exit(1);
    }
    listen(sockFd, 5);
    return (sockFd);
}