#include "all_includes.hpp"

/**********************************
 * 
 * 			Constructors
 * 
**********************************/

Servers::Servers() {}

/**********************************
 * 
 * 			Destructors
 * 
**********************************/

Servers::~Servers()
{
	for (size_t i = 0; i < this->_locations.size(); i++)
		delete this->_locations[i];
	this->_locations.clear();
	this->_method.clear();
	this->_error.clear();
}

/**********************************
 * 
 * 			Setters
 * 
**********************************/

void Servers::setListen(std::string word)					{ this->_listen = word; }
void Servers::setName(std::string word)						{ this->_name = word; }
void Servers::setMethod(std::string word)					{ this->_method.push_back(word); }
void Servers::setRoot(std::string word)						{ this->_root = word; }
void Servers::setError(std::string error, std::string page)	{ this->_error.insert(std::pair<std::string, std::string>(error, page)); }
void Servers::setIndex(std::string word)					{ this->_index = word; }
void Servers::setBody(std::string word)						{ this->_body_size = word; }
void Servers::setLocation()									{ this->_locations.push_back(new Location()); }
void Servers::setListing(std::string word)					{ this->_listing = word; }

/**********************************
 * 
 * 			Getters
 * 
**********************************/

std::string							Servers::getListen()		{return this->_listen; }
std::string							Servers::getName()			{return this->_name; }
std::string							Servers::getRoot()			{return this->_root; }
std::string							Servers::getIndex()			{return this->_index; }
std::string							Servers::getBody()			{return this->_body_size; }
std::string							Servers::getListing()		{return this->_listing; }
std::vector<std::string>			Servers::getMethod()		{return this->_method; }
std::vector<Location*>				Servers::getLocation()		{return this->_locations; }
std::map<std::string, std::string>	Servers::getError()			{return this->_error; }

/**********************************
 * 
 * 			Functions
 * 
**********************************/

	/**********************************
	*	Check_client_size
	*
	* 	Params : none
	* 	Return : true if max server size is between 10 and 2147483647, false otherwise
	* 
	* 	Description :
	* 		- Check that the server's max size (client_max_body_size directive, _body_size variable) is not greater than 2147483647 or less than 10
	**********************************/
bool Servers::check_client_size()
{
	return (this->_body_size.size() > 10) ? false : (atoi(this->_body_size.c_str()) <= 2147483647);
}

	/**********************************
	 *	check_locations
	*
	* 	Params : none
	* 	Return : true if the data stored in the instances of the Location class included in the "_locations" member vector are not empty, false otherwise
	* 
	* 	Description :
	* 		- Check that the data stored in the instances of the Location class in the "_locations" member vector are not empty.
	**********************************/
bool Servers::check_locations()
{
	for (size_t i = 0; i < this->_locations.size(); i++)
		if (this->_locations[i]->getDir().empty() || this->_locations[i]->getMethod().empty() || this->_locations[i]->getRoot().empty() || this->_locations[i]->getIndex().empty() || this->_locations[i]->getListing().empty())
			return false;
	return true;
}

	/**********************************
	 *	check_index
	*
	* 	Params : none
	* 	Return : true if all locations have an index, false otherwise
	* 
	* 	Description :
	* 		- Check that all rentals have an index
	**********************************/
bool Servers::check_index()
{
	if (this->_index.find(".html") == std::string::npos)
		return false;
	for (size_t i = 0; i < this->_locations.size(); i++)
	{
		if (this->_locations[i]->getIndex().empty())
			return false;
		else if (this->_locations[i]->getIndex().find(".html") == std::string::npos)
			return false;
	}
	return true;
}

	/**********************************
	 *	check_listing
	*
	* 	Params : none
	* 	Return : true if the content of the _listing variable (dir_listing) is "on" or "off", false otherwise.
	* 
	* 	Description :
	* 		- Check whether the content of the _listing variable (dir_listing) is "on" or "off".
	**********************************/
bool Servers::check_listing()
{
	if (this->_listing != "on" && this->_listing != "off")
		return false;
	for (size_t i = 0; i < this->_locations.size(); i++)
		if (this->_locations[i]->getListing() != "on" && this->_locations[i]->getListing() != "off")
			return false;
	return true;
}

	/**********************************
	 *	check_method
	*
	* 	Params : none
	* 	Return : false if the authorized methods are not POST, GET or DELETE in a server or in its locations, true otherwise
	* 
	* 	Description :
	* 		- Check that authorized methods are POST, GET or DELETE in a server or in its locations
	**********************************/
bool Servers::check_method()
{
	for (size_t j = 0; j < this->_method.size(); j++)
		if (this->_method[j] != "POST" &&  this->_method[j] != "GET" &&  this->_method[j] != "DELETE")
			return false;
	for (size_t i = 0; i < this->_locations.size(); i++)
		for (size_t j = 0; j < this->_locations[i]->getMethod().size(); j++)
			if (this->_locations[i]->getMethod()[j] != "POST" && this->_locations[i]->getMethod()[j] != "GET" && this->_locations[i]->getMethod()[j] != "DELETE")
				return false;
	return true;
}

	/**********************************
	 *	check_error_page
	*
	* 	Params : none
	* 	Return : true if elements of the "_error" map (error pages) are correctly formatted (error number and .html extension), false otherwise
	* 
	* 	Description :
	* 		- Check that elements of the "_error" map (error pages) are correctly formatted (error number and .html extension)
	**********************************/
bool Servers::check_error_page()
{
	std::map<std::string, std::string>::iterator it = this->_error.begin();
	std::map<std::string, std::string>::iterator it_end = this->_error.end();
	while (it != it_end)
	{
		if (!my_atoi(it->first) || (it->second).find(".html") == std::string::npos)
			return false;
		it++;
	}
	return true;
}

	/**********************************
	 *	check_root
	*
	* 	Params : none
	* 	Return : true if the contents of the _root variable are correctly formatted, false otherwise.
	* 
	* 	Description :
	* 		- Check that the contents of the _root variable are correctly formatted
	**********************************/
bool Servers::check_root()
{
	if (this->_root.length() <= 2)
		return (this->_root == "./");
	if (this->_root[this->_root.length() - 1] != '/')
		this->_root += "/";
	for (size_t i = 0; i < this->_locations.size(); i++)
	{
		if (this->_locations[i]->getRoot().length() <= 2)
		{
			if (this->_locations[i]->getRoot() == "./")
				continue;
			return false;
		}
		if (this->_locations[i]->getRoot()[this->_locations[i]->getRoot().length() - 1] != '/')
			this->_locations[i]->setRoot(this->_locations[i]->getRoot() + "/");
	}
	return true;
}

	/**********************************
	 *	check_root
	*
	* 	Params : string line, int pos
	* 	Return : none
	* 
	* 	Description :
	* 		- Store the line "line" information in the member vector _locations at position "pos".
	**********************************/
void Servers::stock_location(std::string line, int pos)
{
	std::string word = ft_first_word(line);
	std::string last = ft_last_word(line);

	if (word == "location")
		this->_locations[pos]->setDir(last);
	else if (word == "root")
	{
		if (!this->_locations[pos]->getRoot().empty())
			throw DirTwice();
		this->_locations[pos]->setRoot(last);
	}
	else if (word == "index")
	{
		if (!this->_locations[pos]->getIndex().empty())
			throw DirTwice();
		this->_locations[pos]->setIndex(last);
	}
	else if (word == "allowed_methods")
		this->_locations[pos]->setMethod(last);
	else if (word == "dir_listing")
	{
		if (!this->_locations[pos]->getListing().empty())
			throw DirTwice();
		this->_locations[pos]->setListing(last);
	}
	else if (word == "redir")
	{
		if (!this->_locations[pos]->getRedir().empty())
			throw DirTwice();
		this->_locations[pos]->setRedir(last);
	}
}
