#pragma once

#include<iostream>
#include<string>


enum TokenType
{
	ENDOFLINE = -1,
	EMPTY,
	NUMBER,
	PLUS,
	MINUS,
	ASTERISK,
	SLASH
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

	bool checkError();

private:

	void printError(std::string message);
	void nextChar();
	char peek();
	void skipWhiteSpace();


	Token lexInteger();
	Token lexSingleChar();

	std::string m_program;
	int m_position;
	char m_currentChar;
	bool f_error;
};