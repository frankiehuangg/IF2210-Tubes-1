#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <exception>
#include <string>

using namespace std;

class InvalidFileSyntax : public exception
{
public:
	const char *printError() const throw()
	{
		return "File input invalid!";
	}
};

class PlayerNotExist : public exception
{
public:
	const char *printError() const throw()
	{
		return "Player does not exist!";
	}
};

class PlayerNameInvalid : public exception
{
public:
	const char *printError() const throw()
	{
		return "Name not allowed. Please choose another name.";
	}
};

class CreatePlayerFailed : public exception
{
public:
	const char *printError() const throw()
	{
		return "Name is chosen by another player. Please choose another name";
	}
};

class NoAbilityAvailable : public exception
{
private:
	string _message;
public:
	NoAbilityAvailable()
	{
		this->_message = "Kamu belum punya ability saat ini 😔";
	}
	NoAbilityAvailable(string type)
	{
		this->_message = "Ets, tidak bisa. Kamu tidak punya kartu Ability " + type;
	}
	const char *printError() const throw()
	{
		return this->_message.c_str();;
	}
};

class InputInvalid : public exception
{
public:
	const char *printError() const throw()
	{
		return "Input format invalid at line ";
	}
};

class DuplicateCardExist : public exception
{
public:
	const char *printError() const throw()
	{
		return "Duplicate card exist at line ";
	}
};

class NotExpected : public exception
{
public:
	const char *printError() const throw()
	{
		return "Input tidak sesuai kriteria. Mohon ulangi.";
	}
};

class AbilityCardDisabled : public exception
{
private:
	string _message;

public:
	AbilityCardDisabled(string message)
	{
		this->_message = message;
	}
	const char *printError() const throw()
	{
		return this->_message.c_str();
	}
};

#endif
