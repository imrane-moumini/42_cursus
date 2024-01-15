#include "ft_socket.hpp"
#include <errno.h>

int i_send_message(int clientSockFd, std::string message)
{
    return (write(clientSockFd, message.c_str(), message.length()));
}

int i_setup_socket(sockaddr_in *sockStructServ, int portNb)
{
    int serveurSockFd;
    serveurSockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serveurSockFd < 0)
    {
        std::cout << "error socket fd\n";
        exit(1);
    }
    
    bzero((char *)sockStructServ, sizeof(*(sockStructServ)));
    sockStructServ->sin_family = AF_INET;
    sockStructServ->sin_addr.s_addr = INADDR_ANY;
    sockStructServ->sin_port = htons(portNb);

    /* Initialize socket structure */
    if (bind(serveurSockFd, (struct sockaddr *) sockStructServ, sizeof(*(sockStructServ))) < 0)
    {
        std::cout << "error binding\n";
        perror ("The following error occurred\n");
        exit(1);
    }
    if (listen(serveurSockFd, 100) < 0)
    {
        perror("listen error");
        exit(1);
    }
    return (serveurSockFd);
}

void i_handle_connexion(int clientSockFd)
{
    char buff[10000];
    int nbCar;

    nbCar = read(clientSockFd, buff, 10000);
    std::cout << "nb car is " << nbCar << std::endl;
    std::cout << buff << std::endl;
    
    memset(buff, 0, 10000);
    /* Write a response to the client */
    nbCar = i_send_message(clientSockFd,"HTTP/1.0 200 OK \r\n\r\nI got your message");
    
    close(clientSockFd);
}

int i_accept_connexion(int serveurSockFd, sockaddr_in *sockStructClient)
{
    socklen_t clientLen;
    int clientSockFd;

    clientLen = sizeof(*(sockStructClient));
    std::cout << "waiting for a request... " << std::endl;
    clientSockFd = accept(serveurSockFd, (struct sockaddr *)sockStructClient, &clientLen);
    std::cout << "i have accepted your request " << std::endl;
    if(clientSockFd < 0)
    {
        std::cout << "error connect\n";
        exit(1);
    }
    return (clientSockFd);
}