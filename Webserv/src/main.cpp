#include "all_includes.hpp"

Server serv;

/* --------------------------------------------------------------------------------
Ctrl+C : close each socket opened (listening or request) and close 
the program properly
-------------------------------------------------------------------------------- */

void sig_handler(int signal)
{
	(void)signal;

	for (size_t i = 0; i < serv.getSocketList().size(); i++)
		close(serv.getSocketList()[i].getServerSocket());
	for (size_t i = 0; i < serv.getClientsList().size(); i++)
		close(serv.getClientsList()[i].getClientSocket());
	exit(0);
}

/* --------------------------------------------------------------------------------
Main function in which webserv runs
Main function of configuration file parsing
Check that the file passed as an argument to the program is valid

data: Configuration structure in which lots of data are stored temporarily
temporarily, before being exported to the global variable

--> Should be able to be deleted for direct integration into serv
-------------------------------------------------------------------------------- */
int main(int ac, char **av, char **envp)
{
	Conf data;

	try
	{
		if (ac != 2)
			throw ArgvErr();

		std::ifstream file(av[1]);
		if (!file)
			throw ArgvErr();

		std::string name = std::string(av[1]);
		if (name.find(".conf") == std::string::npos)
			throw ArgvErr();
		data.read_file(av[1]);
		data.init_file_pos();
		data.stock_data();
		data.check_data();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	serv.init_server(data.get_servers(), envp);
	signal(SIGINT, sig_handler);

	while (1)
	{
		serv.wait_client();
		serv.accept_client();
		serv.handle_request();
	}
}
