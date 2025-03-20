#include "all_includes.hpp"

/**********************************
 * 
 * 			Constructors
 * 
**********************************/

Conf::Conf()
{
	this->_directives.push_back("server");
	this->_directives.push_back("listen");
	this->_directives.push_back("server_name");
	this->_directives.push_back("allowed_methods");
	this->_directives.push_back("root");
	this->_directives.push_back("error_page");
	this->_directives.push_back("index");
	this->_directives.push_back("client_max_body_size");
	this->_directives.push_back("location");
	this->_directives.push_back("dir_listing");
	this->_directives.push_back("redir");
}

/**********************************
 * 
 * 			Destructors
 * 
**********************************/

Conf::~Conf()
{
	for (size_t i = 0; i < this->_servers.size(); i++)
		delete this->_servers[i];
	this->_servers.clear();
	this->_file.clear();
	this->_file_pos.clear();
	this->_directives.clear();
}

/**********************************
 * 
 * 			Getters
 * 
**********************************/

std::vector<Servers*>		Conf::get_servers() const	{ return this->_servers; }

/**********************************
 * 
 * 			Setters
 * 
**********************************/

void						Conf::set_servers()			{ this->_servers.push_back(new Servers()); }

/**********************************
 * 
 * 			Functions
 * 
**********************************/

	/**********************************
	*	check_data
	*
	* 	Params : none
	* 	Return : none
	* 
	* 	Description :
	* 		- Check that all data stored in the Conf class are correct
	**********************************/
void Conf::check_data()
{
	for (size_t i = 0; i < this->_servers.size(); i++)
	{
		if (this->_servers[i]->getName().empty() || this->_servers[i]->getListen().empty() || this->_servers[i]->getRoot().empty()
			|| this->_servers[i]->getIndex().empty() || this->_servers[i]->getMethod().empty()  || this->_servers[i]->getBody().empty()
			|| this->_servers[i]->getListing().empty())
			throw DirMissing();
		if (!this->_servers[i]->check_locations())
			throw DirMissing();
		if (this->_servers[i]->getListen().size() > 4 || !my_atoi(this->_servers[i]->getListen()) || !my_atoi(this->_servers[i]->getBody()))
			throw NotINT();
		if (!this->_servers[i]->check_error_page())
			throw ErrorPage();
		if (!this->_servers[i]->check_method())
			throw MethWrong();
		if (!this->_servers[i]->check_root())
			throw RootErr();
		if (!this->_servers[i]->check_index())
			throw IndexLoc();
		if (!this->_servers[i]->check_listing())
			throw ListingErr();
		if (!this->_servers[i]->check_client_size())
			throw SizeErr();
	}
}

	/**********************************
	*	init_file_pos
	*
	* 	Params : none
	* 	Return : none
	* 
	* 	Description :
	* 		- Initiate the _file_pos vector, which specifies the position of the directive, whether it's a rental or a server.
	*		0 = server; 1 = location;
	**********************************/
void Conf::init_file_pos()
{
	size_t len =this->_file.size(), pos = 0;
	std::string word;

	for (size_t i = 0; i < len; i++)
	{
		word = ft_first_word(this->_file[i]);
		if (i == 0 && word != "server")
			throw DirMissing();
		if (word == "server")
			pos = 0;
		else if (word == "location")
			pos = 1;
		this->_file_pos.push_back(pos);
		this->is_directive(this->_file[i], i);
	}
}

	/**********************************
	*	is_directive
	*
	* 	Params : std::string line, int pos
	* 	Return : none
	* 
	* 	Description :
	* 		- Determine whether the line passed as an argument is a directive or not and whether it is correctly formatted
	*		0 == server, 1 == location
	**********************************/
void Conf::is_directive(std::string line, int pos)
{
	std::size_t count = count_words(line), len = this->_directives.size();
	std::string word = ft_first_word(line);

	for (size_t i = 0; i < len; i++)
	{
		if (word == this->_directives[i] || word == "{" || word == "}" || word == "["|| word == "]")
		{
			if ((count == 1 && word != "server" && word != "{" && word != "}" && word != "[" && word != "]") || (count == 2 && word == "error_page"))
				throw MissingArgv();
			else if (count >= 3 && word != "error_page")
				throw TooMuchArgv();
			else if ((this->_file_pos[pos] == 1 && (word == "listen" || word == "client_max_body_size" || word == "server_name")) || (this->_file_pos[pos] == 0 && (word == "redir")))
				throw DirWrongPlace();
			return;
		}
	}
	throw DirWrong();
}

	/**********************************
	*	read_file
	*
	* 	Params : std::string name
	* 	Return : none
	* 
	* 	Description :
	* 		- Read the file passed as an argument and pass each line to an entry in the _file vector
	**********************************/
void Conf::read_file(std::string name)
{
	std::ifstream file(name);
	std::string output;
	std::size_t len;

	while (std::getline(file, output))
	{
		len = output.length();
		for (std::size_t i = 0; i < len; i++)
		{
			if (!isspace(output[i]))
			{
				this->_file.push_back(output);
				break;
			}
		}
	}
	if (this->_file.empty())
		throw DirMissing();
}

	/**********************************
	*	stock_data
	*
	* 	Params : none
	* 	Return : none
	* 
	* 	Description :
	* 		- Store all configuration file information in the appropriate variables
	**********************************/
void Conf::stock_data()
{
	int len = this->_file.size(), 
		nb_server = -1, nb_locations = -1,
		status = 0, status1 = 0,
		open, close, new_open,
		open1, close1, new_open1;

	for (int i = 0; i < len; i++)
	{
		if (this->_file_pos[i] == 0)
		{
			if (ft_first_word(this->_file[i]) == "server")
			{
				open = find_char(this->_file, '{',i),
				close = find_char(this->_file, '}', open),
				new_open = find_char(this->_file, '{', open + 1);
				if (open == -1 || close == -1 || open != i + 1 || (new_open != -1 && new_open < close))
					throw DirMissing();
				this->set_servers();
				nb_server++;
				nb_locations = -1;
				status = 0;
			}
			else if (ft_first_word(this->_file[i]) == "}")
				status = 1;
			else if (!status)
				this->stock_server(this->_file[i], this->_servers[nb_server]);
		}
		else
		{
			if (ft_first_word(this->_file[i]) == "location")
			{
				open1 = find_char(this->_file, '[',i),
				close1 = find_char(this->_file, ']', open1),
				new_open1 = find_char(this->_file, '[', open1 + 1);
				if (open1 == -1 || close1 == -1)
					throw DirMissing();
				else if (open1 != i + 1)
					throw DirMissing();
				else if (new_open1 != -1 && new_open1 < close1)
					throw DirMissing();
				this->_servers[nb_server]->setLocation();
				nb_locations++;
				status1 = 0;
			}
			if (ft_first_word(this->_file[i]) == "]")
				status1 = 1;
			else if (!status1)
				this->_servers[nb_server]->stock_location(this->_file[i], nb_locations);
		}
	}
}

	/**********************************
	*	stock_server
	*
	* 	Params : std::string line, Servers* server
	* 	Return : none
	* 
	* 	Description :
	* 		- Store the "line" information in the server "server" 
	**********************************/
void Conf::stock_server(std::string line, Servers* server)
{
	std::size_t count = count_words(line);
	std::string word = ft_first_word(line), last, token;
	std::map<std::string, std::string> settings;
	std::stringstream ss(line);
	if (count == 2)
	{
		last = ft_last_word(line);
		settings["listen"] = server->getListen();
		settings["server_name"] = server->getName();
		settings["root"] = server->getRoot();
		settings["index"] = server->getIndex();
		settings["client_max_body_size"] = server->getBody();
		settings["dir_listing"] = server->getListing();

		if (settings.find(word) != settings.end())
		{
			if (!settings[word].empty())
				throw DirTwice();
			settings[word] = last;
			if (word == "listen")
				server->setListen(last);
			else if (word == "server_name")
				server->setName(last);
			else if (word == "root")
				server->setRoot(last);
			else if (word == "index")
				server->setIndex(last);
			else if (word == "client_max_body_size")
				server->setBody(last);
			else if (word == "dir_listing")
				server->setListing(last);
		}
		else if (word == "allowed_methods")
			server->setMethod(last);
	}
	else if (count >= 3)
	{
		last = ft_last_word(line);
		while (ss >> token)
			if (line.find(token) != line.rfind(last) && token != word)
				server->setError(token, last);
	}
}
