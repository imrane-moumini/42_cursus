/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:33:59 by mlamarcq          #+#    #+#             */
/*   Updated: 2024/02/02 15:07:42 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.hpp"







// std::string		PASS();
// std::string		NICK();
// std::string		USER();
// std::string		PING();
// std::string		PONG();
// std::string		OPER();








//voir les messages à envoyer quand QUIT fonctionne

// vérifier les comportements de NICk (toutes les erreurs)
//vérifier les comportements de USER
//vérifier les comportement de PASS
//vérifier le comportement de QUIT

//implémenter PING

// après NI C K et ça fonctionne => dans handle command (pas dans first)
// après mdpr de notre choix et port de notre choix

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
//quit quitte direct mon program
// corriger quit et voir si les histoire de handle connexion et first connexion sont parfait
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
	// :imrane 403 lol :leaving :No such channel

	// si le client appartient à un channel appeler la fonction (message :NO such, remplacé par les channels)
	// qui prévient tout le monde qu'il s'est barré
	std::string message = ":localhost 403 ";
	message.append(tempClient->getNickName());
	message.append(":leaving :No such channel\r\n");
	return (message);
}


std::string		command::USER(int fd, Server* serv)
{
	std::vector<std::string> temp;
	std::string arg;
	client* clientTmp;

	clientTmp = serv->findClientBySocket(fd);
	// dejà j'envoi pas l'erreur mauvais args
	// je vois pas le contenu de USER voir pk
	//std::cout << "c1\n";
	std::cout << "c2.4.1.1\n";
	// std::cout << 
	if (serv->M_cmdMap.find("USER") != serv->M_cmdMap.end() || serv->M_cmdMap.find("userhost") != serv->M_cmdMap.end())
	{
		//std::cout << "c2\n";
		std::cout << "c2.4.1.2\n";
		std::map<std::string, std::vector<std::string> > :: iterator it = serv->M_cmdMap.find("USER");
		if (it != serv->M_cmdMap.end())
		{
			//std::cout << "c3\n";
			std::cout << "c2.4.1.3\n";
			temp = serv->M_cmdMap["USER"];
			// char **tabSplit = ft_split(temp.c_str(), ' ');
			// int count = std::count(temp.begin(), temp.end(), ' ');
			if (temp.size() < 4)
			{
				std::string chaine;
  				for (std::vector<std::string>::iterator it = temp.begin(); it != temp.end(); ++it)
					chaine += *it;
				return (ERR_NEEDMOREPARAMS(clientTmp->getNickName(), chaine));
			}
			std::cout << "c2.4.1.4\n";
			//std::cout << "TABSPLIT[0] = " << tabSplit[0] << std::endl;

		    if (serv->findClientByUserName(temp[0]) != NULL)
			{
				std::cout << "USER ALREADY EXIST" << std::endl;
				return (ERR_ALREADYREGISTRED(temp[0]));
			}
			std::cout << "c2.4.1.5\n";
			clientTmp->setUserName(temp[0].append(clientTmp->getNickName()));
			std::cout << "c2.4.1.6\n";
			clientTmp->setMode(temp[1]);
			std::cout << "c2.4.1.7\n";
			clientTmp->setHostName(temp[2]);
			std::cout << "c2.4.1.8\n";
			clientTmp->setRealName(temp[3]);
			

			 std::cout << "c2.4.1.9\n";
			//    if (serv->findClientByUserName(tabSplit[0]) != NULL)
		   //        return (ERR_ALREADYREGISTRED(tabSplit[0]));
			// std::string name = tabSplit[0];
			// name.append(clientTmp->getNickName());
			// clientTmp->setUserName(name);
			// clientTmp->setMode(tabSplit[1]);
			// clientTmp->setHostName(tabSplit[2]);
			// clientTmp->setRealName(tabSplit[3]);
			return ("nothing");
		}
		else
		{
			//std::cout << "c4\n";
			std::cout << "c2.4.1.6\n";
			temp = serv->M_cmdMap["userhost"];
			// char **tabSplit = ft_split(temp.c_str(), ' ');
			// int count = std::count(temp.begin(), temp.end(), ' ');
			if (temp.size() < 4)
			{
				std::string chaine;
				for (std::vector<std::string>::iterator it = temp.begin(); it != temp.end(); ++it)
					chaine += *it;
				return (ERR_NEEDMOREPARAMS(clientTmp->getNickName(), chaine));
			}
			for (size_t i = 0; i < temp.size(); i++)
				std::cout << "temp[" << i << "] = " << temp[i] << std::endl;
			std::cout << "c2.4.1.7\n";
			//if (serv->findClientByUserName(tabSplit[0]) != NULL)
			  //  return (ERR_ALREADYREGISTRED(tabSplit[0]))f;
			std::cout << "c2.4.1.8\n";
			clientTmp->setUserName(temp[0].append(clientTmp->getNickName()));
			clientTmp->setMode(temp[1]);
			clientTmp->setHostName(temp[2]);
			clientTmp->setRealName(temp[3]);
			std::cout << "c2.4.1.9\n";
			return ("nothing");
		}
	}
	return ("BIZZARE");

}


std::string		command::NICK(int fd, Server* serv)
{
	//voit pk loic a pas été changé par toto

	//std::string temp;
	std::vector<std::string> temp;
	std::string arg;
	client* clientTmp;
	temp = serv->M_cmdMap["NICK"];
	//size_t notSpace = temp.find_first_not_of(' ');
	//size_t end = temp.find(' ', notSpace);
	std::cout << "c2.1.1.1\n";
	// 
	//if (end == std::string::npos)
	//{
		std::cout << "c2.1.1.2\n";
		//size_t lastcar = temp.find('\0');
		//arg = temp.substr(notSpace, lastcar - 1);
		//std::cout << "ARG IS " << arg << std::endl;
		arg =  temp[0];
		if (arg.empty())
		{
			std::cout << "NICK EMPTY" << std::endl;
			return (ERR_NONICKNAMEGIVEN(arg));
		}
		std::cout << "c2.1.1.3\n";
		if (serv->findClientByNickName(arg) != NULL)
		{
			std::cout << "NICK ALREADY IN USE" << std::endl;
			return (ERR_NICKNAMEINUSE(arg, arg));
		}
		
		
		std::cout << "c2.1.1.4\n";
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
	//}
	
	//else
	//{
	//	arg = temp.substr(notSpace, end);
	//	if (serv->findClientByNickName(arg) == NULL)
	//		return (ERR_NICKNAMEINUSE(arg, arg));
	//	if (arg.empty())
	//		return (ERR_NONICKNAMEGIVEN(arg));
		/*
		for (unsigned int i = 0; i < arg.length(); ++i)
		{
			if (!std::isalnum(arg[i]) && arg[i] != '-' && arg[i] != '_')
				return(ERR_ERRONEUSNICKNAME(arg, arg));
		}
		*/
	//	clientTmp = serv->findClientBySocket(fd);
	//	clientTmp->setNickName(arg)	
	//	return ("nothing");
	//}
}

std::string		command::PASS(int fd, Server* serv)
{
	std::vector<std::string >temp;
	std::string arg;
	client* clientTmp;
	temp = serv->M_cmdMap["PASS"];
	clientTmp = serv->findClientBySocket(fd);
	if (clientTmp->isWelcomeMessageSent())
	{
		std::cout << "PASS CLIENT ALREADY REGISTERED NO NEED PASS" << std::endl;
		return (ERR_ALREADYREGISTRED(clientTmp->getNickName()));
	}
	if (temp[0].empty())
	{
		std::cout << "PASS EMPTY" << std::endl;
		return (ERR_NEEDMOREPARAMS(clientTmp->getNickName(), "PASS"));
	}
	std::string clientPass = temp[0];
	clientPass = clientPass.substr(0, clientPass.length() - 1);
	if (clientPass != serv->M_pass_wd)
	{
		std::cout << "PASS WRONG PASS" << std::endl;
		return (ERR_PASSWDMISMATCH(clientTmp->getNickName()));
	}
	return ("nothing");
}

std::string		command::JOIN(client *client1, Server *serv)
{
	std::vector<std::string> temp;
	temp = serv->M_cmdMap["JOIN"];
	if (temp.empty())
	{
		std::cout << "To join a channel, please enter it's name" << std::endl;
		//return (ERR_NOSUCHCHANNEL(client1->getNickName(), this->));
	}
	//if (client1->getBan() == true)
	//	return ()
	if (temp.size() > 2)
	{
		std::string chaine;
		for (std::vector<std::string>::iterator it = temp.begin(); it != temp.end(); ++it)
			chaine += *it;
		return (ERR_NEEDMOREPARAMS(client1->getNickName(), chaine));
	}
	if (serv->checkChannel() == false)
	{
		std::cout << "No channel in the list, it will be the first !" << std::endl;
		channel *new_one = new channel;
		//faire une fonction dans client pour delete, utiliser algo for each : delete (it);
		//ou utiliser QUIT
		new_one->setName(temp[0]);
		if (new_one->setPassword() == 0)
		{
			delete new_one;
			std::cout << "ERROR" << std::endl;
			return (" ");
		}
		new_one->setListofClient(client1);
		new_one->setOperators(client1);
		serv->setNewChannel(new_one);
		return (" ");
	}
	// // std::cout << "On passe la" << std::endl;
	// std::list<channel *> listOfChannels = serv->getListOfChannels();
	// std::list<channel *>::iterator it = listOfChannels.begin();
	// std::list<channel *>::iterator ite = listOfChannels.end();
	// bool found = false;
	// while (it != ite)
	// {
	// 	// std::cout << "Parameter = " << parameter << std::endl;
	// 	// std::cout << "Channel name = " << (*it)->getName() << std::endl;
	// 	if ((*it)->getName().compare(parameter) == 0)
	// 	{
	// 		std::cout << "Channel found !" << std::endl;
	// 		found = true;
	// 		break ;
	// 	}
	// 	it++;
	// }
	// if (found == false)
	// {
	// 	std::cout << "Channel doesn't exist, let's create it" << std::endl;
	// 	channel *new_one = new channel;
	// 	//faire une fonction dans client pour delete, utiliser algo for each : delete (it);
	// 	new_one->setName(parameter);
	// 	if (new_one->setPassword() == 0)
	// 	{
	// 		delete new_one;
	// 		// std::cout << "ERROR" << std::endl;
	// 		return (" ");
	// 	}
	// 	new_one->setListofClient(client1);
	// 	new_one->setOperators(client1);
	// 	serv->setNewChannel(new_one);
	// 	return (" ");
	// }
	// serv->addClientToChannel(client1, parameter);
	// // std::cout << "Parameter in JOIN = " << parameter << std::endl;
	// // std::cout << "Client1 nickname in JOIN : " << client1->getNickName() << std::endl;
	// // std::cout << "Client1 FD in JOIN : " << client1->getsocketFd() << std::endl;
	(void)client1;
	(void)serv;
	// (void) found;
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
