#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

#include "Lexer.h"

std::string readFile()
{
	std::fstream file("program.txt");
	
	if (!file.is_open())
	{
		std::cout << "ERROR:: couldnt open the file\n";
		return "";
	}

	std::stringstream ss;

	ss << file.rdbuf();

	return ss.str();
}


int main()
{
	//file => 2+5
	std::string program = readFile();

	Lexer lex(program);

	Token token = lex.getNextToken();
	while (token.m_type != TokenType::EMPTY)
	{
		std::cout << token.m_text << "\n";
		token = lex.getNextToken();
	}
}