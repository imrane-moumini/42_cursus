#include "ft_socket.hpp"
#include <errno.h>

int i_send_message(int clientSockFd, std::string message)
{
    //return (write(clientSockFd, message.c_str(), message.length()));
    return (send(clientSockFd, message.c_str(), message.length() ,0));
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

void i_handle_first_connexion(int clientSockFd)
{
    char buff[513];
    int nbCar;

    nbCar = read(clientSockFd, buff, 512);
    if (nbCar == 0)
    {
        close(clientSockFd);
        std::cout << "i close the connection for the sock" << clientSockFd << "\n";
    }
    else
    {
        buff[nbCar] = 0;
    
        std::cout << "nb car is " << nbCar << std::endl;
        std::cout << buff << std::endl;

        memset(buff, 0, 513);
        nbCar = i_send_message(clientSockFd,":localhost 421 * LS :Unknown command\r\n");
        nbCar = i_send_message(clientSockFd,":localhost 001 haha :Welcome to the Internet Relay Network haha!imrane@localhost\r\n");
        nbCar = i_send_message(clientSockFd,":localhost 002 haha :Your host is localhost, running version 1.0\r\n");
        nbCar = i_send_message(clientSockFd,":localhost 003 haha :This server was created 01/01/24\r\n");
        nbCar = i_send_message(clientSockFd,":localhost 004 haha localhost 1.0\r\n");
    }
}

void i_handle_request(int clientSockFd)
{
    char buff[513];
    int nbCar;

    nbCar = read(clientSockFd, buff, 512);
    if (nbCar == 0)
    {
        close(clientSockFd);
        std::cout << "i close the connection for the sock" << clientSockFd << "\n";
    }
    else
    {
        std::cout << "IM HERE IN HANDLE REQUEST\n";
        buff[nbCar] = 0;
    
        std::cout << "nb car is " << nbCar << std::endl;
        std::cout << buff << std::endl;

        memset(buff, 0, 513);
    }
    
    // le pong doit ^petre envoyé avant 301 seconds
}

int i_accept_connexion(int serveurSockFd, sockaddr_in *sockStructClient)
{
    socklen_t clientLen;
    int clientSockFd;

    clientLen = sizeof(*(sockStructClient));
    std::cout << "waiting for a request... " << std::endl;
    clientSockFd = accept(serveurSockFd, (struct sockaddr *)sockStructClient, &clientLen);
    std::cout << "i have accepted your request " << std::endl;
    printf("New connection , socket fd is %d , ip is : %s , port : %d\n" , clientSockFd , inet_ntoa(sockStructClient->sin_addr) , ntohs
				(sockStructClient->sin_port));
    
    if(clientSockFd < 0)
    {
        std::cout << "error connect\n";
        exit(1);
    }
    i_handle_first_connexion(clientSockFd);
    return (clientSockFd);
}