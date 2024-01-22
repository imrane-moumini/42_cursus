#include "client.hpp"

client::client() : nickName(""), realName(""),userName(""),
                    hostName(""),isOperator(false),welcomeMessageSent(false),
                    numberChannelJoined(0) 
{

}

client::client(std::string hostNameParam, int fd) : nickName(""), realName(""),userName(""),
                    hostName(hostNameParam),isOperator(false),welcomeMessageSent(false),
                    socketFd(fd), numberChannelJoined(0)  
{

}

client::client(const client& copy) : nickName(copy.nickName), realName(copy.realName),userName(copy.realName),
                    hostName(copy.hostName),isOperator(copy.isOperator),welcomeMessageSent(copy.welcomeMessageSent),
                    socketFd(copy.socketFd), port(copy.port), ip(copy.ip),numberChannelJoined(copy.numberChannelJoined)  
{

}

client& client::operator=(const client& copy)
{
    (void)copy;
    return (*this);
}

client::~client()
{

}

std::string client::getNickName()
{
    return (this->nickName);
}
std::string client::getRealName()
{
    return (this->realName);
}
std::string client::getUserName()
{
    return (this->userName);
}
std::string client::getHostName()
{
    return (this->hostName);
}
bool        client::getOperatorStatus()
{
    return (this->isOperator);
}
bool        client::isWelcomeMessageSent()
{
    return (this->welcomeMessageSent);
}
int         client::getsocketFd()
{
    return (this->socketFd);
}
int         client::getPort()
{
    return (this->port);
}
char *         client::getIp()
{
    return (this->ip);
}
int         client::getNumberOfChannelJoined()
{
    return (numberChannelJoined);
}

std::string client::getMode()
{
    return (this->mode);
}
//setterclient::
void        client::setNickName(std::string str)
{
    this->nickName = str;
}
void        client::setRealName(std::string str)
{
    this->realName = str;
}
void        client::setUserName(std::string str)
{
    this->userName = str;
}
void        client::setHostName(std::string str)
{
    this->hostName = str;
}
void        client::setOperatorStatus(bool status)
{
    this->isOperator = status;
}
void        client::setWelcomeMessageSent(bool status)
{
    this->welcomeMessageSent = status;
}
void        client::setsocketFd(int fd)
{
    this->socketFd = fd;
}
void        client::setPort(int port)
{
    this->port = port;
}
void        client::setIp(char *ip)
{
    this->ip = ip;
}
void        client::setNumberOfChannelJoined(int nb)
{
    this->numberChannelJoined = nb;
}

void client::setMode(std::string mode)
{
    this->mode = mode;
}

// utils

std::string client::fillStrParam(std::string str, client* clientPtr)
{
    char **tabSplit;
    tabSplit = ft_split(str.c_str(), ' ');
    std::cout << "FILL StrParam\n";
    int i = 0;
    while(tabSplit[i])
    {
        std::cout << tabSplit[i] << std::endl;
        i++;
    }
    (void)clientPtr;
    /*pos = str.find("NICK");
    if (pos != std::string::npos)
    {
        pos++;
        pos++;
        while ((str.c_str() + pos + i) && *((str.c_str()) + pos + i) != ' ')
        {
            i++;
        }
        return (str.substr(pos, i));
    }*/
    return (" ");

}