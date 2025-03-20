#ifndef SERVERS_HPP
# define SERVERS_HPP

# include "../all_includes.hpp"

// A class that can be instantiated several times, depending on the number of servers you want to launch. Each server has its own information.
class Servers
{
	public:

	/**********************************
	 * 
	 * 			Constructors
	 * 
	**********************************/
		Servers();

	/**********************************
	 * 
	 * 			Destructor
	 * 
	**********************************/
		~Servers();

	/**********************************
	 * 
	 * 			Setters
	 * 
	**********************************/
		void setListen(std::string word);
		void setName(std::string word);
		void setMethod(std::string word);
		void setRoot(std::string word);
		void setError(std::string error, std::string page);
		void setIndex(std::string word);
		void setBody(std::string word);
		void setLocation();
		void setListing(std::string word);

	/**********************************
	 * 
	 * 			Getters
	 * 
	**********************************/
		std::string							getListen();
		std::string							getName();
		std::string							getRoot();
		std::string							getIndex();
		std::string							getBody();
		std::string							getListing();
		std::vector<std::string>			getMethod();
		std::vector<Location*>				getLocation();
		std::map<std::string, std::string>	getError();

	/**********************************
	 * 
	 * 			Functions
	 * 
	**********************************/
		void stock_location(std::string line, int pos);
		bool check_method();
		bool check_error_page();
		bool check_root();
		bool check_index();
		bool check_listing();
		bool check_locations();
		bool check_client_size();

	private:

	/**********************************
	 * 
	 * 			Variables
	 * 
	**********************************/
		std::string							_listen,
											_name,
											_root,
											_index,
											_body_size,
											_listing;
		std::vector<std::string>			_method;
		std::vector<Location*>				_locations;
		std::map<std::string, std::string>	_error;
};

#endif