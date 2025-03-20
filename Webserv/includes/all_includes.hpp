#ifndef ALL_INCLUDES_HPP
# define ALL_INCLUDES_HPP

# include <arpa/inet.h>
# include <dirent.h>
# include <fcntl.h>
# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <sys/stat.h>
# include <unistd.h>
# include <vector>
//linux lib
# include <signal.h> //signal
// # include <stdlib.h> //linux exit funct
# include <string.h> // bzero 
# include <sys/wait.h> //waitpid
// # include <cctype>
// # include <climits>
// # include <cstdlib>
// # include <cstring>
// # include <istream>
// # include <iterator>
// # include <netdb.h>
// # include <netinet/in.h>
// # include <set>
// # include <string>
// # include <sys/socket.h>
// # include <sys/time.h>
// # include <sys/types.h>

# include "define.hpp"
# include "errors.hpp"
# include "all_fcts.hpp"
# include "./class/Conf.class.hpp"
# include "./class/Servers.class.hpp"
# include "./class/Requete.class.hpp"
# include "./class/Location.class.hpp"
# include "./class/Client.class.hpp"
# include "./class/Socket.class.hpp"
# include "./class/Server.class.hpp"

#endif