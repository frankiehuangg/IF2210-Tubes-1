#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <exception>

using namespace std;


class InvalidFileSyntax: public exception 
{
	public:
	const char* printError() const throw()
	{
		return "File input invalid!";
	}
};

class PlayerNotExist : public exception
{
	public:
	const char* printError() const throw()
	{
		return "Player does not exist!";
	}
};

class PlayerNameInvalid : public exception
{
	public:
	const char* printError() const throw()
	{
		return "Name not allowed. Please choose another name.";
	}
};

class CreatePlayerFailed : public exception
{
	public:
	const char* printError() const throw()
	{
		return "Name is chosen by another player. Please choose another name";
	}
};

class NoAbilityAvailable: public exception
{
	public:
	const char* printError() const throw()
	{
		return "Player has no ability available";
	}
};

class InputInvalid: public exception
{
	public:
	const char* printError() const throw()
	{
		return "Input format invalid at line ";
	}
};

class DuplicateCardExist: public exception
{
	public:
	const char* printError() const throw()
	{
		return "Duplicate card exist at line ";
	}
};

#endif
