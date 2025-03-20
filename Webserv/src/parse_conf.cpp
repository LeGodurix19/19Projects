#include "all_includes.hpp"

/* --------------------------------------------------------------------------------
Count the number of words in the line "sentence" ("line" in .hpp)
-------------------------------------------------------------------------------- */
int count_words(std::string sentence)
{
	int ret = 0, i = -1;

	while (sentence[++i + 1])
		if (!isspace(sentence[i]) && isspace(sentence[i + 1]))
			ret++;
	return  (!isspace(sentence[i])) ? ret + 1: ret;
}

/* --------------------------------------------------------------------------------
Check whether the "word" string is composed solely of ints or not
-------------------------------------------------------------------------------- */
bool my_atoi(std::string word)
{
	int i = -1;
	while (word[++i])
		if (!isdigit(word[i]))
			return false;
	return true;
}

/* --------------------------------------------------------------------------------
Return the first word of the line "line"
-------------------------------------------------------------------------------- */
std::string ft_first_word(std::string line)
{
	int i = 0, j;
	while (isspace(line[i]) && line[i++]);
	j = i - 1;
	while (!isspace(line[++j]) && line[j]);
	return (line.substr(i, j - i));
}

/* --------------------------------------------------------------------------------
Return the last word of the line "line" 
-------------------------------------------------------------------------------- */
std::string ft_last_word(std::string line)
{
	int i = line.length() - 1, j;
	while (isspace(line[--i]) && line[i]);
	j = i + 1;
	while (--j > 0 && !isspace(line[j]));
	return (line.substr(j + 1, i - j));
}

/* --------------------------------------------------------------------------------
Find the file extension received as a parameter to include the correct content type in the http response message
-------------------------------------------------------------------------------- */
std::string find_type(std::string dir)
{
    std::string extension = dir.substr(dir.find_last_of(".") + 1);

	return 	(extension == "css") 						? 	"text/css" :
			(extension == "jpeg" || extension == "jpg") ? 	"image/jpeg" :
			(extension == "gif") 						? 	"image/gif" :
			(extension == "png") 						? 	"image/png" :
			(extension == "js") 						? 	"application/javascript" :
			(extension == "mp4") 						? 	"video/mp4" :
			(extension == "json") 						? 	"application/json" :
			(extension == "pdf") 						? 	"application/pdf" :
			(extension == "html") 						? 	"text/html" :
															"text/plain";
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	in,
			ih;
	char	*hs;

	ih = 0;
	hs = (char *)haystack;
	if (!strlen(needle))
		return (hs);
	if ((strlen(haystack) < strlen(needle)) || n < strlen(needle))
		return (0);
	while (hs[ih] && ih <= n - strlen(needle))
	{
		in = 0;
		while (needle[in] && (hs[ih + in] == needle[in]))
			in++;
		if (in == strlen(needle))
			return (&hs[ih]);
		ih++;
	}
	return (0);
}
/* --------------------------------------------------------------------------------
That determines whether the request has been sent by the 
client/received by the server.
-------------------------------------------------------------------------------- */
bool is_request_done(char *request, size_t header_size, size_t sizereq)
{
	size_t sizebody = sizereq - header_size;
	char *body = strstr(request, "\r\n\r\n"),
		 *start;
	int len_i;

	if (!body)
		return false;
	body += 4;
	if (ft_strnstr(request, "chunked", sizereq - sizebody))
		return (strstr(body, "\r\n\r\n"));
	else if (ft_strnstr(request, "Content-Length", sizereq - sizebody))
	{
		start = ft_strnstr(request, "Content-Length: ", sizereq - sizebody) + 16;
		len_i = atoi(strndup(start, strstr(start, "\r\n") - start));
		return ((size_t)len_i <= sizebody);
	}
	else if (ft_strnstr(request, "boundary=", sizereq - sizebody))
		return (strstr(body, "\r\n\r\n"));
	return true;
}

/* --------------------------------------------------------------------------------
Non-member function that finds the character c in all strings of the file vector, starting from the start position.
-------------------------------------------------------------------------------- */

int find_char(std::vector<std::string> file, char c, int start = 0)
{
	int len = file.size();

	for (int i = start; i < len; i++)
		for (int y = 0; y < (int)file[i].size(); y++)
			if (file[i][y] == c)
				return (i);
	return (-1);
}

void pexit(const char *error, int i)
{
	perror(error);
	exit(i);
}

void test_connection(int result_to_test, const char *error)
{
	if (result_to_test < 0)
		pexit(error, result_to_test);
}

/* --------------------------------------------------------------------------------
Transform the vector created in the newEnv function into an array of char*.
-------------------------------------------------------------------------------- */
char**	vecToTab(std::vector<std::string>& vec)
{
	char **tab;
	int i = 0;

	tab = (char** )malloc(sizeof(char *)* (vec.size() + 1));
	if (!tab)
		pexit("malloc vecToTab", 1);
	for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++)
		tab[i++] = (char *)(*it).c_str();
	tab[i] = 0;
	return tab;
}