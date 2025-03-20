#ifndef CONF_CLASS_HPP
# define CONF_CLASS_HPP

# include "../all_includes.hpp"

// Retrieves data from parsing, everything configured is here
class Conf
{
	public:
	/**********************************
	 * 
	 * 			Constructors
	 * 
	**********************************/
		Conf();

	/**********************************
	 * 
	 * 			Destructors
	 * 
	**********************************/
		~Conf();

	/**********************************
	 * 
	 * 			Getters
	 * 
	**********************************/
		std::vector<Servers*>		get_servers() const;

	/**********************************
	 * 
	 * 			Functions
	 * 
	**********************************/
		void	check_data();
		void	init_file_pos();
		void	read_file(std::string name);
		void	stock_data();

	private:

	/**********************************
	 * 
	 * 			Setters
	 * 
	**********************************/
		void	set_servers();

	/**********************************
	 * 
	 * 			Functions
	 * 
	**********************************/
		void	stock_server(std::string line, Servers* server);
		void	is_directive(std::string line, int pos);

	/**********************************
	 * 
	 * 			Variables
	 * 
	**********************************/
		std::vector<Servers*>		_servers;
		std::vector<int>			_file_pos;
		std::vector<std::string>	_file,
									_directives;
};

#endif