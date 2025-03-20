#include "all_includes.hpp"

/* --------------------------------------------------------------------------------
Check whether the executable can be launched with the path received
Return the path to the executable in which to run the script, depending on whether the file extension is .py (Pyhton) or .php (PHP)
Return an empty string if the extension is different
(DELETE THE ENVP PARAMETER, WHICH NO LONGER SEEMS NECESSARY)
Return the path to the executable if it works, otherwise an empty string
-------------------------------------------------------------------------------- */
std::string searchExec(std::string filePwd)
{
	size_t  i = 0;

    while (filePwd[i]) i++;
    while(i && filePwd[i] != '.') i--;
	const std::string exec = (!strcmp(&filePwd[i], ".py")) ? WHEREISPYTHON : ((!strcmp(&filePwd[i], ".php")) ? WHEREISPHP : "");
	if (exec == "")
	{
		std::cerr << "incompatible CGI-script" << std::endl;
		return ("");
	}
	return ((!access(exec.c_str(), X_OK)) ? exec : "");
}

/* --------------------------------------------------------------------------------
Warning, this my_env is not the same as the one in the exec_cgi function
Create a new environment as a vector, which takes all the values of the environment in which webserv is executed + custom values related to the request currently being processed
-------------------------------------------------------------------------------- */
void newEnv(char** envp, Requete& req, std::vector<std::string>& my_env, Servers* serv)
{
	size_t  i = 0;
	while (envp[i])
		my_env.push_back(envp[i++]);
	my_env.push_back("CONTENT_TYPE=" + req.getHeader()["Content-Type"]);
	my_env.push_back("GATEWAY_INTERFACE=CGI/1.1");

	char path[124] = {0};
	my_env.push_back("PATH_TRANSLATED=" + std::string(getcwd(path, 124)));
	if (!req.getQuery().empty())
	{
		std::cout << "QUERY_STRING=" << req.getQuery() << std::endl;
		my_env.push_back("QUERY_STRING=" + req.getQuery());
	}
	if (!req.getMethod().empty())
		my_env.push_back("REQUEST_METHOD=" + req.getMethod());
	if (req.getLen())
		my_env.push_back("CONTENT_LENGTH=" + std::to_string(req.getLen()));
	if (!req.getProtocol().empty())
		my_env.push_back("SERVER_SOFTWARE=" + req.getProtocol());

	my_env.push_back("SERVER_NAME=" + serv->getName());
	my_env.push_back("HTTP_ACCEPT=" + req.getHeader()["Accept"]);
	my_env.push_back("HTTP_ACCEPT_LANGUAGE=" + req.getHeader()["Accept-Language"]);
	my_env.push_back("HTTP_USER_AGENT=" + req.getHeader()["User-Agent"]);
	my_env.push_back("SCRIPT_NAME=" + req.getUrl());
	my_env.push_back("HTTP_REFERER=" + req.getHeader()["Referer"]);
}

std::string execCGI(std::string filePwd, char** envp, Requete& req, Servers* serv)
{
	std::string execPwd = searchExec(filePwd);
	if (execPwd == "")
	{
		std::cerr << "Bad file" << std::endl;
		return ("");
	}

	int fdIn,
		fd_in[2],
		fd_out[2],
		i;
	char buff[2041] = {0};
	char* tab[3];
	char** my_env;
	std::vector<std::string> env;
	std::string ret = "";

	tab[0] = (char *)execPwd.c_str();
	tab[1] = (char *)filePwd.c_str();
	tab[2] = 0;
	newEnv(envp, req, env, serv);
	my_env = vecToTab(env);
	pipe(fd_in);
	pipe(fd_out);
	pid_t pid = fork();

	if (pid == -1)
		pexit("fork()", 1);
	if (pid == 0)
	{
		close(fd_in[1]);
		close(fd_out[0]);
		if (dup2(fd_in[0], 0) == -1 || dup2(fd_out[1], 1) == -1)
			pexit("dup2", 1);
		execve(tab[0], tab, my_env);
		pexit("execve", 1);
	}
	else
	{
		fdIn = dup(0);
		if (fdIn == -1)
			pexit("dup", 1);
		if (dup2(fd_in[0], 0) == -1)
			pexit("dup2", 1);
		if (!req.getFullBody().empty())
			if (write(fd_in[1], req.getFullBody().c_str(), req.getLen()) < 0)
				pexit("write", 1);
		close(fd_in[0]);
		close(fd_in[1]);
		waitpid(pid, 0, 0);
		if (dup2(fdIn, 0) == -1)
			pexit("dup2", 1);
		free(my_env);
		close(fd_out[1]);
		i = read(fd_out[0], buff, 2040);
		if (i == -1)
			pexit("read", 1);
		buff[i] = 0;
		ret += std::string(buff);
		while (i > 0)
		{
			i = read(fd_out[0], buff, 2040);
			if (i == -1)
				pexit("read", 1);
			buff[i] = 0;
			ret += std::string(buff);
		}
		close(fd_out[0]);
		return ret;
	}
	return "";
}
