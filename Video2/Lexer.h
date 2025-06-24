#pragma once

#include <iostream>
#include <string>

#include "LibsLocal/magic_enum/magic_enum.hpp"

enum TokenType
{
	Empty,
	Endofline,
	Number,

	Plus,
	Minus
};

struct Token
{
	std::string m_text = "";
	TokenType m_type = TokenType::Empty;
};

class Lexer
{
public:
	Lexer(std::string file);
	~Lexer();

	void run();
private:

	void nextChar();
	Token getNextToken();

	std::string m_file;
	char m_currentChar;
	int m_position;
};

