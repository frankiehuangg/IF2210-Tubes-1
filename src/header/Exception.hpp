#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <exception>

using namespace std;

struct InvalidFileSyntax: public exception 
{
	const char* printError() const throw()
	{
		return "File input invalid!";
	}
};

struct PlayerNotExist : public exception
{
	const char* printError() const throw()
	{
		return "Player does not exist!";
	}
};

struct CreatePlayerFailed : public exception
{
	const char* printError() const throw()
	{
		return "Name not allowed. Please choose another name";
	}
};

struct NoAbilityAvailable: public exception
{
	const char* printError() const throw()
	{
		return "Player has no ability available";
	}
};

struct InputInvalid: public exception
{
	InputInvalid(int _line) {
		line = _line;
	}

	const char* printError() const throw()
	{
		string msg = "Input format invalid at line " + to_string(line);
		return msg.c_str();
	}

	private:
		int line;
};

struct DuplicateCardExist: public exception
{
	DuplicateCardExist(int _line) {
		line = _line;
	}

	const char* printError() const throw()
	{
		string msg = "Duplicate card exist at line " + to_string(line);
		return msg.c_str();
	}

	private:
		int line;
};

#endif
