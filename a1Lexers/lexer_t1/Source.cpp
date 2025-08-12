#include<iostream>
#include<sstream>
#include<string>
#include<fstream>


#include "Lexer.h"

#include "../../LibsLocal/magic_enum/magic_enum.hpp"


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
	std::string program = readFile();

	Lexer lex(program);

	Token token = lex.getNextToken();
	while (token.m_type != TokenType::EMPTY && !lex.checkError())
	{
		std::cout << token.m_text << " : " << magic_enum::enum_name(token.m_type) << "\n";
		token = lex.getNextToken();
	}
}