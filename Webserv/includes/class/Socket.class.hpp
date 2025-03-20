#ifndef SOCKET_HPP
# define SOCKET_HPP

# include "../all_includes.hpp"

class Socket
{
// faire un constructeur qui setup le socket au lieu d'avoir une fonction setup qui n'est appelee qu'une fois 

	public:

	/**********************************
	 * 
	 * 			Constructors
	 * 
	**********************************/
		Socket(std::string port, std::string ip);

	/**********************************
	 * 
	 * 			Functions
	 * 
	**********************************/
		void setup(std::string port, std::string ip); // setup the server and client socket
		int getServerSocket();

	/**********************************
	 * 
	 * 			Variables
	 * 
	**********************************/
		timeval time_start;

	private:

	/**********************************
	 * 
	 * 			Variables
	 * 
	**********************************/
		int _serverSocket;
};

#endif