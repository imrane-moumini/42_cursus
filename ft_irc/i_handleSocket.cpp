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

void i_handle_connexion(int newsockFd)
{
    char buff[10000];
    int nbCar;

    nbCar = read(newsockFd, buff, 10000);
    std::cout << "nb car is " << nbCar << std::endl;
    std::cout << buff << std::endl;
    
    memset(buff, 0, 10000);
    /* Write a response to the client */
    nbCar = i_send_message(newsockFd,"HTTP/1.0 200 OK \r\n\r\nI got your message");
    
    close(newsockFd);
}

int i_accept_connexion(int sockFd, sockaddr_in *sockStructClient)
{
    socklen_t clientLen;
    int newsockFd;

    clientLen = sizeof(*(sockStructClient));
    std::cout << "waiting for a request... " << std::endl;
    newsockFd = accept(sockFd, (struct sockaddr *)sockStructClient, &clientLen);
    std::cout << "i have accepted your request " << std::endl;
    if(newsockFd < 0)
    {
        std::cout << "error connect\n";
        exit(1);
    }
    return (newsockFd);
}