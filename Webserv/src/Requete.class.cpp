#include "all_includes.hpp"

/**********************************
 * 
 * 			Constructors
 * 
**********************************/

Requete::Requete(char *requete)
{
	this->_char_request = requete;
	std::stringstream ss(requete);
	this->_request = requete;
	this->_len = 0;
	ss >> this->_method >> this->_url >> this->_protocol;
	size_t pos = this->_url.find("?");
	if (pos != std::string::npos)
		this->_query= this->_url.substr(pos + 1);
	if (this->_method == "GET")
		this->make_GET(ss);
	else if (this->_method == "POST")
		this->make_POST(ss);
}

/**********************************
 * 
 * 			Destructors
 * 
**********************************/

Requete::~Requete()
{
	this->_header.clear();
	this->_text.clear();
}

/**********************************
 * 
 * 			Getters
 * 
**********************************/

size_t								Requete::getLen() const			{return this->_len;}
std::map<std::string, std::string>	Requete::getHeader() const		{return this->_header;}
std::string							Requete::getBody() const		{return this->_body;}
std::string							Requete::getBoundary() const	{return this->_boundary;}
std::string							Requete::getFileName() const	{return this->_file_name;}
std::string							Requete::getFullBody() const	{return this->_full_body;}
std::string							Requete::getMethod() const		{return this->_method;}
std::string							Requete::getName() const		{return this->_boundary;}
std::string							Requete::getProtocol() const	{return this->_protocol;}
std::string							Requete::getQuery() const		{return this->_query;}
std::string							Requete::getRequest() const		{return this->_request;}
std::string							Requete::getType() const		{return this->_type;}
std::string							Requete::getUrl() const			{return this->_url;}
std::vector<std::string>			Requete::getText() const		{return this->_text;}

/**********************************
 * 
 * 			Functions
 * 
**********************************/

	/**********************************
	*	make_POST
	*
	* 	Params : std::stringstream& ss
	* 	Return : none
	* 
	* 	Description :
	* 		-	processes tokens, extracts key-value pairs, and populates member variables in the Requete object. 
				It handles boundary extraction, Content-Length handling, request body parsing, and updates 
				relevant variables (_header, _len, _full_body, _body).
	**********************************/
void Requete::make_POST(std::stringstream& ss)
{
	std::string token, line, key;
	std::string buff;
	size_t pos = this->_request.find("\r\n\r\n");
	size_t pos_header;

	while (ss >> token)
	{
		if (token.find("boundary=") != std::string::npos)
			this->_boundary = token.substr(token.find("boundary=") + 9);
		if (token == "Content-Length:")
		{
			if (!key.empty() && !line.empty() && key != token)
			{
				if (line[line.length() - 1] == ' ')
					line.erase(line.length() - 1);
				this->_header.insert(std::pair<std::string, std::string>(key, line));
				line.clear();
			}
			key = token;
			ss >> token;
			this->_header.insert(std::pair<std::string, std::string>(key, token));
			this->_len = atoi(token.c_str());
			key.clear();
		}
		else if (this->_request.find(token) >= pos - token.length())
		{
			pos += 4;
			if (!key.empty() && key != token)
			{
				if (!line.empty())
					line.erase(line.length() - 1);
				this->_header.insert(std::pair<std::string, std::string>(key, (line.empty()) ? token : line));
			}
			pos_header = pos;
			while (pos < this->_len + pos_header)
				this->_full_body += this->_char_request[pos++];
			if (this->_boundary.empty())
				this->_body = this->_full_body;
			break;
		}
		else if (token[token.length() - 1] == ':')
		{
			if (!key.empty() && key != token)
			{
				if (line[line.length() - 1] == ' ')
					line.erase(line.length() - 1);
				this->_header.insert(std::pair<std::string, std::string>(key, line));
			}
			token.erase(token.length() - 1);
			key = token;
			line.clear();
		}
		else
			line += ((line.empty()) ? "" : " ") + token;
	}
}

	/**********************************
	*	make_GET
	*
	* 	Params : std::stringstream& ss
	* 	Return : none
	* 
	* 	Description :
	* 		-	the function parses a formatted input stream of tokens and extracts key-value pairs, storing them in the _header map.
	**********************************/
void Requete::make_GET(std::stringstream& ss)
{
	std::string token, line, key;

	while (ss >> token)
	{
		if (token[token.length() - 1] == ':')		
		{
			if (!key.empty() && !line.empty() && key != token)
			{
				if (line[line.length() - 1] == ' ')				
					line.erase(line.length() - 1);				
				this->_header.insert(std::pair<std::string, std::string>(key, line));
			}
			token.erase(token.length() - 1);					
			key = token;
			line.clear();
		}
		else
			line += ((line.empty()) ? "" : " ") + token;
	}
	if (!line.empty() && !key.empty())
	{
		if (line[line.length() - 1] == ' ')					
			line.erase(line.length() - 1);						
		this->_header.insert(std::pair<std::string, std::string>(key, line));
	}
}