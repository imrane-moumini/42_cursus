
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
    sockFd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockFd < 0)
    {
        std::cout << "error socket fd\n";
        exit(1);
    }
    std::cout << "sock fd is " << sockFd << std::endl;
    bzero((char *)&sockStructServ, sizeof(sockStructServ));
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

    while ((nbCar = read(newsockFd, buff, 10000)) > 0)
    {
        
        std::cout << "nb car is " << nbCar << std::endl;
        std::cout << buff << std::endl;

        //end ofg http request
        if (buff[-1] == '\n')
        {
            std::cout << "IM HERE \n";
            break;
        }
        
        memset(buff, 0, 10000);
        
        /* Write a response to the client */
        nbCar = write(newsockFd,"HTTP/1.0 200 OK \r\n\r\nI got your message",38);
        close(newsockFd);
    }
    std::cout << "YES \n";
}