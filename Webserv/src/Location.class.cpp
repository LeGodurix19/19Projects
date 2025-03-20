#include "all_includes.hpp"

/**********************************
 * 
 * 			Setters
 * 
**********************************/

void Location::setDir(std::string word)		                { this->_dir = word; };
void Location::setRoot(std::string word)		            { this->_root = word; };
void Location::setIndex(std::string word)		            { this->_index = word; };
void Location::setMethod(std::string word)	                { this->_method.push_back(word); };
void Location::setListing(std::string word)	                { this->_listing = word; };
void Location::setRedir(std::string word)		            { this->_redir = word; };

/**********************************
 * 
 * 			Getters
 * 
**********************************/

std::string                 Location::getDir()		        { return this->_dir; };
std::vector<std::string>	Location::getMethod()		    { return this->_method; };
std::string					Location::getRoot()		        { return this->_root; };
std::string					Location::getIndex()		    { return this->_index; };
std::string					Location::getListing()	        { return this->_listing; };
std::string					Location::getRedir()		    { return this->_redir; };
