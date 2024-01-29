/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:33:59 by mlamarcq          #+#    #+#             */
/*   Updated: 2024/01/25 16:02:44 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.hpp"

command::command()
{

}
command::command(const command& copy)
{
    (void)copy;
}
command& command::operator=(const command& copy)
{
    (void) copy;
    return (*this);
}
command::~command()
{

}
// std::string		PASS();
std::string		command::NICK(int fd, Server* serv)
{

    //voit pk loic a pas été changé par toto
    std::string temp;
    std::string arg;
    client* clientTmp;
    temp = serv->M_cmdMap["NICK"];
    size_t notSpace = temp.find_first_not_of(' ');
    size_t end = temp.find(' ', notSpace);
    if (end == std::string::npos)
    {
        size_t lastcar = temp.find('\0');
        arg = temp.substr(notSpace, lastcar - 1);
        //std::cout << "ARG IS " << arg << std::endl;
        if (serv->findClientByNickName(arg) != NULL)
            return (ERR_NICKNAMEINUSE(arg, arg));
        if (arg.empty())
            return (ERR_NONICKNAMEGIVEN(arg));
        /*
        for (unsigned int i = 0; i < arg.length(); ++i)
		{
            if (!std::isalnum(arg[i]) && arg[i] != '-' && arg[i] != '_')
			    return(ERR_ERRONEUSNICKNAME(arg, arg));
        }
        */
        clientTmp = serv->findClientBySocket(fd);
        clientTmp->setNickName(arg);
        return ("nothing");
    }
    else
    {
        arg = temp.substr(notSpace, end);
        if (serv->findClientByNickName(arg) == NULL)
            return (ERR_NICKNAMEINUSE(arg, arg));
        if (arg.empty())
            return (ERR_NONICKNAMEGIVEN(arg));
        /*
        for (unsigned int i = 0; i < arg.length(); ++i)
		{
            if (!std::isalnum(arg[i]) && arg[i] != '-' && arg[i] != '_')
			    return(ERR_ERRONEUSNICKNAME(arg, arg));
        }
        */
        clientTmp = serv->findClientBySocket(fd);
        clientTmp->setNickName(arg);
        
        return ("nothing");
    }

}
// std::string		USER();
// std::string		PING();
// std::string		PONG();
// std::string		OPER();



std::string		command::QUIT(int fd, Server* serv)
{

	client * tempClient;
	close(fd);
	FD_CLR(fd, &(serv->M_struct->current_sockets));
	tempClient = serv->findClientBySocket(fd);
    //std::cout << "IN QUIT NICK IS " << tempClient->getNickName() << std::endl;
	if (tempClient != NULL)
		tempClient->goodBy();
	if (tempClient != NULL)
		serv->eraseClientFromList(tempClient->getNickName());

    // si le client appartient à un channel appeler la fonction
    // qui prévient tout le monde qu'il s'est barré
    return (" ");
}
// std::string		JOIN();
// std::string		PART();
// std::string		TOPIC();
// std::string		KICK();
// std::string		MODE();
// std::string		PRIVMSG();
// std::string		NOTICE();
// std::string		KILL();
// std::string		WALLOPS();
// std::string		bot();
