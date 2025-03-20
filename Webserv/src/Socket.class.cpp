#include "all_includes.hpp"



/**********************************
 * 
 * 			Constructors
 * 
**********************************/

Socket::Socket(std::string port, std::string ip = "0.0.0.0")
{
	int port_int = stoi(port),
		value = 1;
	struct sockaddr_in address;

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(port_int);

	test_connection((this->_serverSocket = socket(AF_INET, SOCK_STREAM, 0)), "serverSocket: ");
	fcntl(this->_serverSocket, F_SETFL, O_NONBLOCK);
	
	test_connection(setsockopt(this->_serverSocket, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value)), "setsockopt:");
	address.sin_addr.s_addr = inet_addr(ip.c_str());
	
	test_connection((bind(this->_serverSocket, (struct sockaddr *)&address, sizeof(address))), "bind");
	test_connection(listen(this->_serverSocket, 42), "Listening");
	
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::cout << YELLOW << "[" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << "]" << "[" << port << "] listening ..." << RESET_COLOR << std::endl;
}

/**********************************
 * 
 * 			Getters
 * 
**********************************/

int Socket::getServerSocket()	{ return this->_serverSocket; }

/**********************************
 * 
 * 			Functions
 * 
**********************************/

	/**********************************
	 *	setup
	*
	* 	Params : std::string port, std::string ip = "0.0.0.0"
	* 	Return : none
	* 
	* 	Description :
	* 		Setup the server socket
	*		socket -> create the socket 
	*		setsocktopt -> help to handle socket options and prevent errors such as "address already in use"
	*		bind -> binds the socket to the address and port number specified in addr
	*		listen -> it puts the server socket in passive mode, where it waits for the client to approach the server to establish a connection.
	*		accept -> extracts the first pending connection request, creates a new connected socket and returns a new file descriptor referring to this socket
	**********************************/
void Socket::setup(std::string port, std::string ip = "0.0.0.0") {
	int port_int = stoi(port),
		value = 1;
	struct sockaddr_in address;

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(port_int);

	test_connection((this->_serverSocket = socket(AF_INET, SOCK_STREAM, 0)), "serverSocket: ");
	fcntl(this->_serverSocket, F_SETFL, O_NONBLOCK);
	
	test_connection(setsockopt(this->_serverSocket, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value)), "setsockopt:");
	address.sin_addr.s_addr = inet_addr(ip.c_str());
	
	test_connection((bind(this->_serverSocket, (struct sockaddr *)&address, sizeof(address))), "bind");
	test_connection(listen(this->_serverSocket, 42), "Listening");
	
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::cout << YELLOW << "[" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << "]" << "[" << port << "] listening ..." << RESET_COLOR << std::endl;
}
