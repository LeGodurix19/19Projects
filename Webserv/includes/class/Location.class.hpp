#ifndef LOCATION_HPP
# define LOCATION_HPP

# include "../all_includes.hpp"

// Class in which information relating to the rental directive will be stored (explain)
class Location
{
	public:

	/**********************************
	 * 
	 * 			Constructors
	 * 
	**********************************/
		Location() {};

	/**********************************
	 * 
	 * 			Destructor
	 * 
	**********************************/
		~Location() {_method.clear();};

	/**********************************
	 * 
	 * 			Setters
	 * 
	**********************************/
		void setDir(std::string word);
		void setRoot(std::string word);
		void setIndex(std::string word);
		void setMethod(std::string word);
		void setListing(std::string word);
		void setRedir(std::string word);

	/**********************************
	 * 
	 * 			Getters
	 * 
	**********************************/
		std::vector<std::string>	getMethod();
		std::string					getDir();
		std::string					getRoot();
		std::string					getIndex();
		std::string					getListing();
		std::string					getRedir();

	private:

	/**********************************
	 * 
	 * 			Variables
	 * 
	**********************************/
		std::vector<std::string>	_method;
		std::string					_dir,
									_root,
									_index,
									_listing,
									_redir;
};

#endif