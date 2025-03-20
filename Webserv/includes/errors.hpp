#ifndef ERRORS_HPP
# define ERRORS_HPP

#include "all_includes.hpp"

class ArgvErr : EXCEPTION		{ WHAT throw () { return ("Usage : ./Webserv <config_file>"); } };
class MissingArgv : EXCEPTION	{ WHAT throw () { return ("Error: Missing argument after a directive"); } };
class TooMuchArgv : EXCEPTION	{ WHAT throw () { return ("Error: Too much arguments after a directive"); } };
class DirWrongPlace : EXCEPTION	{ WHAT throw () { return ("Error: Directive is in the wrong place"); } };
class DirWrong : EXCEPTION		{ WHAT throw () { return ("Error: Directive doesn't exist"); } };
class DirMissing : EXCEPTION	{ WHAT throw () { return ("Error: Missing a directive"); } };
class NotINT : EXCEPTION		{ WHAT throw () { return ("Error: Argument needs to be a number"); } };
class MethWrong : EXCEPTION		{ WHAT throw () { return ("Error: Method is wrong"); } };
class ErrorPage : EXCEPTION		{ WHAT throw () { return ("Error: Error page is wrong"); } };
class DirTwice : EXCEPTION		{ WHAT throw () { return ("Error: Two times the same directive"); } };
class RequestErr : EXCEPTION	{ WHAT throw () { return ("Error: Request method wrong"); } };
class RootErr : EXCEPTION		{ WHAT throw () { return ("Error: In root path"); } };
class IndexLoc : EXCEPTION		{ WHAT throw () { return ("Error: Missing index in location"); } };
class ListingErr : EXCEPTION	{ WHAT throw () { return ("Error: Dir_listing must be on or off"); } };
class SizeErr : EXCEPTION		{ WHAT throw () { return ("Error: Client size"); } };

#endif