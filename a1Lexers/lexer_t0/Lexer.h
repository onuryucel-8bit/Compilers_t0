#pragma once

#include<iostream>
#include<string>

enum TokenType
{
	EMPTY,
	NUMBER,
	PLUS,
	MINUS
};

struct Token
{
	std::string m_text = "";
	TokenType m_type = EMPTY;
};

class Lexer
{
public:
	Lexer(std::string program);
	~Lexer();

	Token getNextToken();

private:

	void printError(std::string message);
	void nextChar();

	std::string m_program;
	int m_position;
	char m_currentChar;
};