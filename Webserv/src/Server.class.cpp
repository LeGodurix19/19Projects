#include "all_includes.hpp"

/**********************************
 * 
 * 			Getters
 * 
**********************************/

std::vector<Socket> Server::getSocketList() 	{ return this->_sockets; }
std::vector<Client> Server::getClientsList() 	{ return this->_clients; }
/* --------------------------------------------------------------------------------
Execute the GET method
-------------------------------------------------------------------------------- */
void Server::getMethod(Client& client, std::string urlrcv)
{
	std::cout << YELLOW << "GET method!" << RESET_COLOR << std::endl;
	if (urlrcv.size() >= 64)
	{
		this->showError(414, client);
		return;
	}
	struct stat path_stat;

	std::string urlsend = this->getRootPath(urlrcv, client.getNServer());

	if (this->loc && !(this->loc->getIndex().empty()) && (strcmp(urlrcv.c_str(), \
		this->loc->getDir().c_str()) == 0))
	{
		this->showPage(client, this->loc->getRoot() + this->loc->getIndex(), 200);
		return;
	}

	FILE* fd = fopen(urlsend.c_str(), "rb");
	stat(urlsend.c_str(), &path_stat);

	if (fd == NULL)
	{
		std::cout << BLUE << "Resource not found: "<< urlsend << RESET_COLOR << std::endl;
		this->showError(404, client);
	}
	else
	{
		if (S_ISDIR(path_stat.st_mode))
		{
			std::cout << BLUE << "File is a directory!" << RESET_COLOR << std::endl;

			if (strcmp(urlrcv.c_str(), "/") == 0)
				this->showPage(client, urlsend + this->servers[client.getNServer()]->getIndex(), 200);
			else if (this->servers[client.getNServer()]->getListing() == "on" || (this->loc && this->loc->getListing() == "on"))
				this->rep_listing(client.getClientSocket(), urlrcv, urlsend, client);
			else
			{
				std::cout << RED << "DIR listing off" << RESET_COLOR << std::endl;
				this->showError(404, client);	
			}
		}
		else
			this->showPage(client, urlsend, 200);
		fclose(fd);
	}
}

/* --------------------------------------------------------------------------------
Returns the url to give to the CGI script, or where to fetch the html page to be 
displayed
-------------------------------------------------------------------------------- */
std::string Server::getRootPath(std::string urlrcv, int i)
{
	std::string urlroot = this->servers[i]->getRoot();
	if (urlroot[urlroot.size() - 1] == '/')
		urlroot.erase(urlroot.size() - 1, 1);
	std::cout << "Url To Send: " << GREEN << urlroot + urlrcv << RESET_COLOR << std::endl;
	return urlroot + urlrcv;
}

Location* Server::getLocation(std::string url, int i)
{
	std::vector<Location*> locs = this->servers[i]->getLocation();
	for (size_t i = 0; i < locs.size(); i++)
	{
		if (strncmp(locs[i]->getDir().c_str(), url.c_str(), locs[i]->getDir().size()) == 0)
		{
			std::cout << CYAN << url << " is the location!" << RESET_COLOR << std::endl;
			return locs[i];
		}
	}
	return NULL;
}

/* --------------------------------------------------------------------------------

FD_SET() Sets the bit for the file descriptor fd in the set of fdset file 
descriptors.

The "addtowait" function takes as input a socket and a pointer to a set of 
sockets (fd_set). It adds the socket to the set using the FD_SET function, 
then updates the maximum socket value (max_fd) of the objet Server if the 
input socket is larger than the current value of max_fd.

-------------------------------------------------------------------------------- */
void Server::addtowait(int socket, fd_set* set)
{
	FD_SET(socket, set);
	if (socket > this->max_fd)
		this->max_fd = socket;
}

/* --------------------------------------------------------------------------------
Select()

Is a way of managing multiple clients
    The Select command allows you to monitor several file descriptors, waiting 
	for one of them to become active.
    For example, if data needs to be read from one of the sockets, the select 
	command will provide this information. Select works like an interrupt handler, 
	activating as soon as a file descriptor sends data.

It calls the "select" function to monitor the set of sockets
of sockets given as input, waiting for one of them to be ready to be
read or written. If select() returns a value less than 0, this indicates an error.
In this case, the program terminates with an output code of -1. If
select() returns 0, this means that the function has expired before a socket
is ready, and a "select() time out" message is displayed. Otherwise, the sets
of sockets to be written and read are updated with the corresponding sockets
in the Server object.

-------------------------------------------------------------------------------- */
void Server::selectfd(fd_set* read, fd_set* write)
{
	int r = 0;
	if ((r = select(this->max_fd + 1, read, write, 0, 0)) < 0)
		exit(-1);
	else if (r == 0)
		std::cout << "select() time out" << std::endl;
	this->writeSet = *write;
	this->readSet = *read;
}

/* --------------------------------------------------------------------------------
The "wait_client" function initializes the read and write sockets to
zero (using the FD_ZERO function) to prepare them for use. 
It then adds server sockets and client sockets to the read set by calling the 
"addtowait" function. Finally, it calls the "selectfd" function with 
the read and write socket sets. This allows you to wait for one or more 
sockets are ready to be read or written, by monitoring all sockets 
sockets present in the read set.

-------------------------------------------------------------------------------- */
void Server::wait_client()
{
	fd_set 	read,
			write;

	FD_ZERO(&read);
	FD_ZERO(&write);
	for (size_t i = 0; i < this->_sockets.size(); i++)
		this->addtowait(this->_sockets[i].getServerSocket(), &read);
	for (size_t i = 0; i < this->_clients.size(); i++)
		this->addtowait(this->_clients[i].getClientSocket(), &read);
	this->selectfd(&read, &write);

}

/* --------------------------------------------------------------------------------
Accept client, configure class, register in _clients
FD_ISSET() checks whether a descriptor is contained in a set, 
mainly useful after the return of select().

It extracts the first connection request from the queue of pending connections 
for the listening socket, sockfd, creates a new connected socket and returns 
a new file descriptor referencing this socket. At this point, the connection 
is established between client and server, and they are ready to transfer data.
-------------------------------------------------------------------------------- */
void Server::accept_client()
{
	sockaddr_in addrclient;
	socklen_t clientSize = sizeof(addrclient);

	for (size_t i = 0; i < this->_sockets.size(); i++)
	{
		if (FD_ISSET(this->_sockets[i].getServerSocket(), &this->readSet))
		{
			Client client(i);
			client.setSocketClient(accept(this->_sockets[i].getServerSocket(), (struct sockaddr*)&addrclient, &clientSize));
			this->_clients.push_back(client);
			if (client.getClientSocket() < 0)
				pexit("Connect", -1);
			std::cout << GREEN << "New connection!" << RESET_COLOR << std::endl;
		}
	}
}

/* --------------------------------------------------------------------------------
Function that handles the requests received by the server
- Receives the request
	recv -> Receive the request message and store its size in a variable
- Separates the header and the body
- Processes the header information
- Processes the message according to the requested method
- Executes the CGI script
-------------------------------------------------------------------------------- */
void Server::handle_request()
{
	for (size_t i = 0; i < this->_clients.size(); i++)
	{
		if (FD_ISSET(this->_clients[i].getClientSocket(), &this->readSet))
		{
			size_t Reqsize = recv(this->_clients[i].getClientSocket(), this->_clients[i].request, MAX_REQUEST_SIZE, 0);
			if (Reqsize < 0)
			{
				std::cout << RED << "Error: recv() failed" << RESET_COLOR << std::endl;
				this->kill_client(this->_clients[i--]);
			}
			this->_clients[i].requestSize += Reqsize;
			for (size_t size = 0; size < Reqsize; size++)
				this->_clients[i].final_request.push_back(this->_clients[i].request[size]);
			// PEPE
			// std::cout << "final request: \n" << this->_clients[i].final_request << std::endl;
			int header_size = this->_clients[i].final_request.find("\r\n\r\n", 0);
			header_size += 4;
			if (Reqsize == 0)
			{
				std::cout << RED << "Connection is closed!" << RESET_COLOR << std::endl;
				this->kill_client(this->_clients[i--]);
			}
			else if (is_request_done((char *)this->_clients[i].final_request.c_str(), header_size, this->_clients[i].requestSize))
			{
				std::cout << CYAN << "== New request! ==" << RESET_COLOR << std::endl;
				Requete requete((char*)this->_clients[i].final_request.c_str());
				int ret = -1;
				if ((ret = ((requete.getMethod() != "POST" && requete.getMethod() != "GET" && requete.getMethod() != "DELETE")? 405 : ((requete.getProtocol() != "HTTP/1.1") ? 505 : -1))) != -1)
				{
					this->showError(ret, this->_clients[i]);
					if (this->kill_client(this->_clients[i]))
						i--;
					continue;
				}
				if (requete.getLen() != std::string::npos && requete.getLen() > (size_t)stoi(this->servers[this->_clients[i].getNServer()]->getBody()))
				{
					this->showError(413, this->_clients[i]);
					if (this->kill_client(this->_clients[i]))
						i--;
					continue;
				}
				std::string urlrcv = requete.getUrl().substr(0, requete.getUrl().rfind("?"));
				this->loc = this->getLocation(urlrcv, this->_clients[i].getNServer());
				if (!((this->loc == NULL) ? \
					this->is_allowed(this->servers[this->_clients[i].getNServer()]->getMethod(),requete.getMethod()) \
					: this->is_allowed(this->loc->getMethod(), requete.getMethod()))
						&& urlrcv.find("cgi_bin") == std::string::npos)
				{
					std::cout << "Unautorised method " << requete.getMethod() << "!" << std::endl;
					showError(405, this->_clients[i]);
					if (this->kill_client(this->_clients[i]))
						i--;
					continue;
				}
				if (this->is_cgi(urlrcv))
				{
					std::cout << BLUE << "CGI start!" << RESET_COLOR << std::endl;
					std::string urlsend = this->getRootPath(urlrcv, this->_clients[i].getNServer());
					
					std::string rescgi = execCGI(urlsend, this->envp, requete, this->servers[this->_clients[i].getNServer()]);
					if (rescgi.empty())
						this->showError(404, this->_clients[i]);
					rescgi = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n" + rescgi;
					int r = send(this->_clients[i].getClientSocket(), rescgi.c_str(), rescgi.size(), 0);
					if (r < 0)
						this->showError(500, this->_clients[i]);
					else if (r == 0)
						this->showError(400, this->_clients[i]);
				}
				else
				{
					if (this->loc && !this->loc->getRedir().empty())
						this->do_redir(this->_clients[i], this->loc->getRedir());
					else if (requete.getMethod() == "GET")
						this->getMethod(this->_clients[i], urlrcv);
					else if (requete.getMethod() == "POST")
						this->postMethod(this->_clients[i], urlrcv, requete);
					else if (requete.getMethod() == "DELETE")
						this->deleteMethod(this->_clients[i], urlrcv);
				}
				if (this->kill_client(this->_clients[i]))
					i--;
				if (i <= 0)
				{
					this->_clients[i].requestSize = 0;
					bzero(this->_clients[i].request, MAX_REQUEST_SIZE);
				}
			}
		}
	}
	usleep(10000);	
}

/* --------------------------------------------------------------------------------
Execute the DELETE method
-------------------------------------------------------------------------------- */
void Server::deleteMethod(Client& client, std::string urlrcv)
{
	std::cout << YELLOW << "DELETE method!" << RESET_COLOR << std::endl;
	std::string urlsend = this->getRootPath(urlrcv, client.getNServer());
	FILE* fd = fopen(urlsend.c_str(), "r");

	if (!fd)
	{
		this->showError(404, client);
		return;
	}
	fclose(fd);
	std::remove(urlsend.c_str());

	std::string tosend = "HTTP/1.1 200 OK\n";
	int ret = send(client.getClientSocket(), tosend.c_str(), tosend.size(), 0);
	if (ret < 0)
		this->showError(500, client);
	else if (ret == 0)
		this->showError(400, client);
	std::cout << GREEN << urlsend << " has been deleted!" << RESET_COLOR << std::endl;
}

/* --------------------------------------------------------------------------------
Execute the POST method
-------------------------------------------------------------------------------- */
void Server::postMethod(Client client, std::string url, Requete req)
{
	if (req.getHeader()["Transfer-Encoding"] == "chunked")
	{
		this->showError(411, client);
		return;
	}
	std::string urlsend = this->getRootPath(url, client.getNServer());
	struct stat buf;
	lstat(urlsend.c_str(), &buf);

	if (S_ISDIR(buf.st_mode))
	{
		std::string name,
					body = req.getFullBody(),
					file;
		size_t 	start = 0,
				end = 0;
		if (!(req.getHeader()["Content-Type"].empty()) && !(req.getBoundary().empty()))
		{
			std::cout << CYAN <<  "Post in directory: " << RESET_COLOR << std::endl;
			while (true)
			{
				if ((start = body.find("name=\"", start)) == std::string::npos)
					break;
				start += 6;
				if ((end = body.find("\"", start)) == std::string::npos)
					break;
				name = body.substr(start, end - start);
				std::cout << "+ " + name << std::endl;

				if ((start = body.find("\r\n\r\n", end)) == std::string::npos)
					break;
				start += 4;
				if ((end = body.find(req.getBoundary(), start)) == std::string::npos)
					break;

				file = body.substr(start, end - start - 4);

				if (!this->writewithpoll(urlsend + "/" + name, client, file) || body[end + req.getBoundary().size()] == '-')
					break;
			}
		}
		else
		{
			this->showError(400, client);
			return;
		}
	}
	else
	{
		std::cout << "Post in file" << std::endl;
		if (!this->writewithpoll(urlsend, client, req))
			return;
	}
	this->showPage(client, "", (req.getLen()) ? 201 : 204);
}

/* --------------------------------------------------------------------------------
Initialize the base socket for each of the servers you want to runin the program
Insert error codes in _errors

socket: basic, listening socket, can be instantiated several times if the 
configuration of webserv requires the configuration of several servers
-------------------------------------------------------------------------------- */
void Server::init_server(std::vector<Servers*> servers, char **envp)
{
	this->servers = servers;
	this->envp = envp; 	
	for (size_t i = 0; i < this->servers.size(); i++)
	{
		Socket socket(this->servers[i]->getListen(), this->servers[i]->getName());
		this->_sockets.push_back(socket);
	}
	this->_errors.insert(std::make_pair(200, "200 OK"));
	this->_errors.insert(std::make_pair(201, "201 Created"));
	this->_errors.insert(std::make_pair(204, "204 No Content"));
	this->_errors.insert(std::make_pair(300, "300 Multiple Choices"));
	this->_errors.insert(std::make_pair(301, "301 Moved Permanently"));
	this->_errors.insert(std::make_pair(302, "302 Found"));
	this->_errors.insert(std::make_pair(303, "303 See Other"));
	this->_errors.insert(std::make_pair(307, "307 Temporary Redirect"));
	this->_errors.insert(std::make_pair(400, "400 Bad Request"));
	this->_errors.insert(std::make_pair(404, "404 Not Found"));
	this->_errors.insert(std::make_pair(405, "405 Method Not Allowed"));
	this->_errors.insert(std::make_pair(408, "408 Request Timeout"));
	this->_errors.insert(std::make_pair(411, "411 Length Required"));
	this->_errors.insert(std::make_pair(413, "413 Request Entity Too Large"));
	this->_errors.insert(std::make_pair(414, "414 Request-URI Too Long"));
	this->_errors.insert(std::make_pair(500, "500 Internal Server Error"));
	this->_errors.insert(std::make_pair(502, "502 Bad Gateway"));
	this->_errors.insert(std::make_pair(505, "505 HTTP Version Not Supported"));
	this->max_fd = -1;
}

/* --------------------------------------------------------------------------------
Send the message and error page corresponding to the int received on the socket
in first parameter
-------------------------------------------------------------------------------- */
void Server::showError(int err, Client& client)
{
	std::map<std::string, std::string> errpages = this->servers[client.getNServer()]->getError();
	if (errpages.find(std::to_string(err)) != errpages.end())
	{
		int fd = open(errpages[std::to_string(err)].c_str(), O_RDONLY);
		if (fd < 0)
		{
			std::cout << RED << "Show error: " << this->_errors[err] << "!\nPre-config error page doesn't exist: " << errpages[std::to_string(err)] << RESET_COLOR << std::endl;
			close(fd);
			return;
		}
		close(fd);
		this->showPage(client, errpages[std::to_string(err)], 200);
	}
	else
	{
		std::map<int, std::string>::iterator it = this->_errors.find(err);
		if (it != this->_errors.end())
		{
			std::cout << RED << "Show error: " << it->second << "!" << RESET_COLOR << std::endl;
			std::string msg = "HTTP/1.1 " + it->second + "\nContent-Type: text/plain\nContent-Length: " + std::to_string(it->second.size()) + "\n\n" + it->second + "\n";
			int sendret = send(client.getClientSocket(), msg.c_str(), msg.size(), 0);
			if (sendret < 0)
				std::cout << "Client disconnected" << std::endl;
			else if (sendret == 0)
				std::cout << "0 byte passed to server" << std::endl;
		}
	}
}

/* --------------------------------------------------------------------------------
Close the socket assigned to the client passed in parameter and then delete it from 
the list of registered clients
-------------------------------------------------------------------------------- */
bool Server::kill_client(Client client)
{
	std::cout << RED << "Client killed" << RESET_COLOR << std::endl;

	close(client.getClientSocket());
	for (size_t i = 0; i < this->_clients.size(); i++)
	{
		if (this->_clients[i].getClientSocket() == client.getClientSocket())
		{
			this->_clients.erase(this->_clients.begin() + i);
			return true;
		}
	}
	exit(1);
}

/* --------------------------------------------------------------------------------
Checks whether the method received by the client is one of the authorized methods or not
-------------------------------------------------------------------------------- */
bool Server::is_allowed(std::vector<std::string> methodlist, std::string methodreq)
{
	for (size_t i = 0; i < methodlist.size(); i++)
		if (methodlist[i] == methodreq)
			return true;
	return false;
}

/* --------------------------------------------------------------------------------
Check that the file to be processed is supported by our server (python or
php)
-------------------------------------------------------------------------------- */
bool Server::is_cgi(std::string filename)
{
	std::vector<std::string>  cgi_list;
	cgi_list.push_back(".py");
	cgi_list.push_back(".php");
	if (filename.find('.') == std::string::npos)
		return false;
	std::string extension = filename.substr(filename.find('.'), filename.size());
	for (size_t i = 0; i < cgi_list.size(); i++)
		if (cgi_list[i] == extension)
			return true;
	return false;
}

/* --------------------------------------------------------------------------------
Send the page to be displayed to the socket
(may need further explanation)
-------------------------------------------------------------------------------- */
void Server::showPage(Client client, std::string dir, int code)
{
	int r;

	if (dir != "")
		std::cout << CYAN << "Show page: " << dir << RESET_COLOR << std::endl;

	if (dir.empty())
	{
		std::string err_msg = "HTTP/1.1 " + this->_errors[code] + "\n\n";
		if ((r = send(client.getClientSocket(), err_msg.c_str(), err_msg.size(), 0)) < 0)
			this->showError(500, client);
		else if (r == 0)
			this->showError(400, client);
		return;
	}
	else
	{
		FILE* fd_s = fopen(dir.c_str(), "rb");
		if (fd_s == NULL)
		{
			this->showError(404, client);
			return;
		}
		fseek (fd_s, 0, SEEK_END);
		int lSize = ftell (fd_s);
		rewind (fd_s);
		fclose(fd_s);
		std::string type = find_type(dir),
					msg = "HTTP/1.1 " + this->_errors.find(code)->second + "\n" + "Content-Type: " + type + "\nContent-Length: " + std::to_string(lSize) + "\n\n";
		int ret = send(client.getClientSocket(), msg.c_str(), msg.size(), 0);
		if (ret < 0)
			this->showError(500, client);
		else if (ret == 0)
			this->showError(400, client);
		int fd_r = open(dir.c_str(), O_RDONLY);
		if (fd_r < 0)
		{
			this->showError(500, client);
			return;
		}
		this->addtowait(fd_r, &this->readSet);
		this->selectfd(&this->readSet, &this->writeSet);
		char file[1024];
		int r2;
		int r = read(fd_r, file, 1024);
		if (r < 0)
			this->showError(500, client);
		else
		{
			while (r)
			{
				if ((r2 = send(client.getClientSocket(), file, r, 0)) < 0)
				{
					this->showError(500, client);
					break;
				}
				else if (r2 == 0)
				{
					this->showError(400, client);
					break;
				}
				this->addtowait(fd_r, &this->readSet);
				this->selectfd(&this->readSet, &this->writeSet);
				if ((r = read(fd_r, file, 1024)) < 0)
				{
					this->showError(500, client);
					break;
				}
				if (r == 0)
					break;
			}
		}
		close(fd_r);
	}
}
/* --------------------------------------------------------------------------------
opens a directory, reads the directory entries, constructs an HTML response with 
the list of files and directories, sends this response to the client and handles 
any errors during sending.
-------------------------------------------------------------------------------- */
void Server::rep_listing(int socket, std::string path, std::string fullurl, Client client)
{
	std::cout << CYAN << "Show repository listing" << RESET_COLOR << std::endl;

	DIR* dir;
	struct dirent* ent;
	std::string data,
				tosend = "HTTP/1.1 200 OK\n\n<!DOCTYPE html>\n<html>\n<body>\n<h1>" + path + "</h1>\n<pre>\n";

	if ((dir = opendir (fullurl.c_str())) != NULL)
	{
		while ((ent = readdir (dir)) != NULL)
			tosend += "<a href=\"" + ((std::string(ent->d_name) == ".") ? std::string(path) : (std::string(path) + "/" + std::string(ent->d_name))) + "\">" + std::string(ent->d_name) + "</a>\n";
		closedir (dir);
	}
	else
	{
		perror ("Directory listing");
		return;
	}
	tosend += "</pre>\n</body>\n</html>\n";
	int r = send(socket, tosend.c_str(), tosend.size(), 0);
	if (r < 0)
		this->showError(500, client);
	else if (r == 0)
		this->showError(400, client);

}

/* --------------------------------------------------------------------------------
opens a file, uses select to wait until the file descriptor is ready for writing, 
writes the data to the file with write, then closes the file. It also handles 
errors and displays an appropriate error page in the event of failure.
-------------------------------------------------------------------------------- */
bool Server::writewithpoll(std::string url, Client client, std::string str)
{
	int r = 0;
	int fd = open(url.c_str(), O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		this->showError(500, client);
		close(fd);
		return false;
	}
	this->addtowait(fd, &this->writeSet);
	this->selectfd(&this->readSet, &this->writeSet);
	r = write(fd, str.c_str(), str.size());
	if (r < 0)
	{
		this->showError(500, client);
		close(fd);
		return false;
	}
	close(fd);
	return true;
}

bool Server::writewithpoll(std::string url, Client client, Requete req)
{
	int r = 0,
		fd = open(url.c_str(), O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		this->showError(500, client);
		close(fd);
		return false;
	}
	this->addtowait(fd, &this->writeSet);
	this->selectfd(&this->readSet, &this->writeSet);
	std::cout << GREEN << req.getFullBody() << RESET_COLOR << std::endl;
	r = write(fd, req.getFullBody().c_str(), req.getFullBody().size());
	if (r < 0)
	{
		this->showError(500, client);
		close(fd);
		return false;
	}
	close(fd);
	return true;
}

void Server::do_redir(Client client, std::string url)
{
	std::cout << CYAN << "Is a redirection to: " << url << RESET_COLOR << std::endl;
	std::string tosend = "HTTP/1.1 200 OK\n\n<head><meta http-equiv = \"refresh\" content = \"0; url =" + url + "\" /></head>";

	int r = send(client.getClientSocket(), tosend.c_str(), tosend.size(), 0);
	if (r < 0)
		this->showError(500, client);
	else if (r == 0)
		this->showError(400, client);
}
