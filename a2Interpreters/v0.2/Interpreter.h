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
	
	void printError();
	void getToken();
	
	void expression();
	float term();
	float integer();


	Lexer lex;

	bool f_error;
	float m_result;


	Token m_currentToken;
	Token m_peekToken;
};
