#ifndef SERVER_HPP
# define SERVER_HPP

# include "../all_includes.hpp"

// Global variable in which everything will run
class Server
{
	public:

	/**********************************
	 * 
	 * 			Getters
	 * 
	**********************************/
		std::vector<Socket> getSocketList();
		std::vector<Client> getClientsList();

	/**********************************
	 * 
	 * 			Functions
	 * 
	**********************************/
		void	accept_client();
		void	handle_request();
		void	init_server(std::vector<Servers*> servers, char **envp);
		void	wait_client();
		void	postMethod(Client client, std::string url, Requete req);

	/**********************************
	 * 
	 * 			Variables
	 * 
	**********************************/
		std::vector<Servers*> servers;
		char **envp;
		int max_fd;
		fd_set readSet,
				writeSet;
		Location* loc;

	private:

	/**********************************
	 * 
	 * 			Getters
	 * 
	**********************************/
		std::string	getRootPath(std::string url, int i);
		Location*	getLocation(std::string url, int i);

	/**********************************
	 * 
	 * 			Functions
	 * 
	**********************************/
		void		addtowait(int socket, fd_set* set);
		void		selectfd(fd_set* read, fd_set* write);
		void		getMethod(Client& client, std::string url);
		void		deleteMethod(Client& client, std::string url);
		void		showError(int err, Client& client);
		void		showPage(Client client, std::string dir, int code);
		void		rep_listing(int socket, std::string path, std::string fullurl, Client client);
		void		do_redir(Client client, std::string url);
		bool		kill_client(Client client);
		bool		is_allowed(std::vector<std::string> methodlist, std::string methodreq);
		bool		is_cgi(std::string filename);
		bool		writewithpoll(std::string url, Client client, Requete req);
		bool		writewithpoll(std::string url, Client client, std::string str);

	/**********************************
	 * 
	 * 			Variables
	 * 
	**********************************/
		std::vector<Socket> _sockets;
		std::vector<Client> _clients;
		std::map<int, std::string> _errors;
};

#endif