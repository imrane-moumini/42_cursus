
#include "ft_socket.hpp"
#include <errno.h>

int main(int argc, char *argv[])
{
    int sockFd;
    int newsockFd;
    int portNb;
    socklen_t clientLen;
    int nbCar;
    char buff[10000];
    (void)argc;
    (void) argv;
    struct sockaddr_in sockStructServ;
    struct sockaddr_in sockStructClient;

    portNb = 18000;

    /* Initialize socket structure */
    sockFd = socket (AF_INET, SOCK_STREAM, 0);

    if (sockFd < 0)
    {
        std::cout << "error socket fd\n";
        exit(1);
    }
    std::cout << "sock fd is " << sockFd << std::endl;
    bzero((char *)&sockFd, sizeof(sockFd));
    sockStructServ.sin_family = AF_INET;
    sockStructServ.sin_addr.s_addr = INADDR_ANY;
    sockStructServ.sin_port = htons(portNb);

    /* Initialize socket structure */
    if (bind(sockFd, (struct sockaddr *) &sockStructServ, sizeof(sockStructServ)) < 0)
    {
        std::cout << "error binding\n";
        perror ("The following error occurred\n");
        exit(1);
    }

    listen(sockFd, 5);
    clientLen = sizeof(sockStructClient);
    newsockFd = accept(sockFd, (struct sockaddr *)&sockStructClient, &clientLen);

    if(newsockFd < 0)
    {
        std::cout << "error connect\n";
        exit(1);
    }

    while (1)
    {
        nbCar = read(newsockFd, buff, 10000);
        if (nbCar)
        {
            std::cout << "nothing to read anymore\n";
            exit(1);
        }
        /* Write a response to the client */
        nbCar = write(newsockFd,"HTTP/1.0 200 OK \r\n\r\nI got your message",38);
        close(newsockFd);
    }
}