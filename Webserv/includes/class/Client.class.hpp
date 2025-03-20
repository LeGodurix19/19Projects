#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "../all_includes.hpp"

class Client
{
	public:

	/**********************************
	 * 
	 * 			Constructors
	 * 
	**********************************/
		Client(int i);

	/**********************************
	 * 
	 * 			Getters
	 * 
	**********************************/
		void	setSocketClient(int sock);
		int		getClientSocket() const;
		int		getNServer() const;

	/**********************************
	 * 
	 * 			Variables
	 * 
	**********************************/
		int			requestSize;
		char		request[MAX_REQUEST_SIZE + 1];
		size_t		last_time;
		std::string	final_request;

	private:
	/**********************************
	 * 
	 * 			Variables
	 * 
	**********************************/
		int _clientSocket,
			_n_server;
};

#endif