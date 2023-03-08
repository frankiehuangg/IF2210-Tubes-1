#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <exception>

using namespace std;

struct InvalidFileSyntax: public exception 
{
	const char* printError() const throw()
	{
		return "File input invalid!\n";
	}
};

#endif
