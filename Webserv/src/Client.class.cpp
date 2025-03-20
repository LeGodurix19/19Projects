#include "all_includes.hpp"

/**********************************
 * 
 * 			Constructors
 * 
**********************************/

Client::Client(int i)
{
	this->last_time = this->requestSize = 0;
	this->_n_server = i;
	bzero(this->request, MAX_REQUEST_SIZE + 1);
}

/**********************************
 * 
 * 			Setters
 * 
**********************************/

/*
Initialize the _clientSocket variable with the return from accept() and set it to non-blocking mode

fcntl(int fd, int cmd, ...  arg ); 
    ->  performs one of the operations determined by cmd on the open file descriptor fd.   
        Set the file status flags to the value specified by arg.
*/ 
void	Client::setSocketClient(int sock)
{
	this->_clientSocket = sock;
	fcntl(this->_clientSocket, F_SETFL, O_NONBLOCK);
}

/**********************************
 * 
 * 			Getters
 * 
**********************************/

int		Client::getClientSocket() const	{ return this->_clientSocket; }
int		Client::getNServer() const		{ return this->_n_server; }