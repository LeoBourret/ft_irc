#include "Client.hpp"

Client::Client(int sd)
	: _socket(new DataSocket(sd)) {
	struct sockaddr_in client_addr = {};
	socklen_t	len = sizeof(sockaddr_in);
// Ask getsockname to fill in this socket's local address
	getsockname(sd, reinterpret_cast<struct sockaddr*>(&client_addr), &len);
	_hostname = inet_ntoa(client_addr.sin_addr);
}

Client::~Client() {
	delete _socket;
}

int	Client::sd() const {
	return _socket->getsd();
}

std::string	Client::hostname() const {
	return _hostname;
}

void	Client::setHostname(std::string hostname) {
	_hostname = hostname;
}

void	Client::receive(std::string data) {
	_stock += data;
}

void	Client::send(std::string data) const {
	_socket->send(data.c_str(), data.size());
}

bool	Client::crlf() const {
	if (_stock.find("\r\n") != std::string::npos)
		return true;
	else
		return false;
}

std::string	Client::line() const {
	if (!crlf())
		return std::string("\r\n");
	size_t	pos = _stock.find("\r\n");
	return _stock.substr(0, pos + 2);
}

void	Client::clearLine() {
	if (!crlf())
		return ;
	size_t	pos = _stock.find("\r\n");
	_stock.erase(0, pos + 2);
}
