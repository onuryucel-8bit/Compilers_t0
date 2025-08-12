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

	
	void run();
private:
	
	void printError();
	void getToken();
	
	float program();
	float expression();
	float term();
	float integer();


	Lexer lex;

	bool f_error;

	Token m_currentToken;
	Token m_peekToken;
};
