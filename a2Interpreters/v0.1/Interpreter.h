#pragma once

#include <iostream>
#include <string>

#include "Lexer.h"

#include "LibsLocal/magic_enum/magic_enum.hpp"

class Interpreter
{
public:
	Interpreter(std::string program);
	~Interpreter();

	void program();

private:

	void getToken();
	int integer();
	void printError();


	Lexer lex;

	bool f_error;

	Token m_currentToken;
	Token m_peekToken;
};
