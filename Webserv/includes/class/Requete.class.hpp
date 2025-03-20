#ifndef REQUETE_HPP
# define REQUETE_HPP

# include "../all_includes.hpp"

class Requete
{
	public:

	/**********************************
	 * 
	 * 			Constructors
	 * 
	**********************************/
		Requete(char *requete);

	/**********************************
	 * 
	 * 			Destructor
	 * 
	**********************************/
		~Requete();

	/**********************************
	 * 
	 * 			Getters
	 * 
	**********************************/
		size_t								getLen() const;
		std::map<std::string, std::string>	getHeader() const;
		std::string							getBody() const;
		std::string							getFileName() const;
		std::string							getBoundary() const;
		std::string							getFullBody() const;
		std::string							getMethod() const;
		std::string							getName() const;
		std::string							getProtocol() const;
		std::string							getQuery() const;
		std::string							getRequest() const;
		std::string							getType() const;
		std::string							getUrl() const;
		std::vector<std::string>			getText() const;

	protected:

	/**********************************
	 * 
	 * 			Functions
	 * 
	**********************************/
		void	make_POST(std::stringstream& ss);
		void	make_GET(std::stringstream& ss);

	/**********************************
	 * 
	 * 			Variables
	 * 
	**********************************/
		char*								_char_request;	// FULL Request
		size_t								_len;			// Len from Header
		std::string							_body,			// Content body without boundary
											_boundary,		// Boundary from Header
											_file_name,		// File name in body if exist not always
											_full_body,		// Content body with boundary
											_method,		// Method from Header
											_name,			// Name in body
											_protocol,		// Protocol from Header
											_query,			// Query text after url without ?
											_request,		// FULL Request
											_type,			// File name in body if exist not always
											_url;			// URL from Header
		std::vector<std::string>			_text;			// For JOHN divided with the word NewFile
		std::map<std::string, std::string>	_header;		// Header

};

#endif