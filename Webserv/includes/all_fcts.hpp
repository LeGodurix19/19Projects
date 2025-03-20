#ifndef WEBSERV_HPP
# define WEBSERV_HPP

# include "all_includes.hpp"

class Location;
class Servers;
class Conf;
class Requete;
class Client;
class Socket;
class Server;

void        pexit(const char *error, int i);
int			count_words(std::string line);
bool		my_atoi(std::string word);
std::string	ft_first_word(std::string line);
std::string	ft_last_word(std::string line);
std::string find_type(std::string dir);
std::string execCGI(std::string filePwd, char** envp, Requete& req, Servers* serv);
char	    *ft_strnstr(const char *haystack, const char *needle, size_t n);
bool        is_request_done(char *request, size_t header_size, size_t sizereq);
int         find_char(std::vector<std::string> file, char c, int start);
void        test_connection(int result_to_test, const char *error);
char**	    vecToTab(std::vector<std::string>& vec);

#endif