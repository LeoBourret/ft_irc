#include "utils.hpp"
#include "Network.hpp"
#include "IRCServer.hpp"
#include <vector>
#include <iostream>

void	IRCServer::privmsg(User *sender, std::vector<std::string> params) {
	if (!sender->isRegistered()) {
		sender->send(serverMessageBuilder(*this, commandMessageBuilder(CODE_ERR_NOTREGISTERED, sender)));
		return;
	}
	User	*target;
	Channel	*chan;

	if (params.size() < 2) {
		sender->send(serverMessageBuilder(*this, commandMessageBuilder(CODE_ERR_NEEDMOREPARAMS, sender, "PRIVMSG")));
		return ;
	}
	chan = network().getChannelByName(params[0]);
	if (chan != u_nullptr) { 
		if (chan->isModeSet(ChannelMode::Mode::MODERATED) == false 
			|| chan->isStatusSet(sender, MemberStatus::Status::VOICE) == true
			|| chan->isStatusSet(sender, MemberStatus::Status::OPERATOR) == true) {
			chan->send(serverMessageBuilder(*sender, "PRIVMSG " + paramsToString(params, 2)), sender);
		}
		return ;
	}
	target = network().getUserByName(params[0]);
	if (target != u_nullptr) {
		if (target->isModeSet('a'))
			sender->send(serverMessageBuilder(*this, commandMessageBuilder(CODE_RPL_AWAY, target, target->awayMessage())));
		target->send(serverMessageBuilder(*sender, params[1]));
	}
	else
		sender->send(serverMessageBuilder(*this, commandMessageBuilder(CODE_ERR_NOSUCHNICK, sender, params[0])));
}
