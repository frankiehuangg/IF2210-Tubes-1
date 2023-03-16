#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <exception>
#include <string>

using namespace std;

class GameException : public exception
{
public:
	virtual ~GameException() {}
	virtual const char *printError() const throw() = 0;
};

class PlayerNotExist : public GameException
{
public:
	const char *printError() const throw()
	{
		return "Player does not exist!";
	}
};

class PlayerNameInvalid : public GameException
{
public:
	const char *printError() const throw()
	{
		return "Name not allowed. Please choose another name.";
	}
};

class CreatePlayerFailed : public GameException
{
public:
	const char *printError() const throw()
	{
		return "Name is chosen by another player. Please choose another name";
	}
};

class NoAbilityAvailable : public GameException
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



class NotExpected : public GameException
{
public:
	const char *printError() const throw()
	{
		return "Input tidak sesuai kriteria. Mohon ulangi.";
	}
};

class AbilityCardDisabled : public GameException
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
};class InvalidFile : public GameException
{
public:
	const char *printError() const throw()
	{
		return "File input invalid!";
	}
};

class InvalidFileInput : public GameException
{
public:
	const char *printError() const throw()
	{
		return "Input format invalid at line ";
	}
};

class DuplicateCardExist : public GameException
{
public:
	const char *printError() const throw()
	{
		return "Duplicate card exist at line ";
	}
};

#endif
