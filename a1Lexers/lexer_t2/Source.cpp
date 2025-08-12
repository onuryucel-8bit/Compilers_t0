#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

#include "Interpreter.h"

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


/*
<expression> ::= <integer> (<operator> <integer>)+
<integer> ::= [0-9]+
<operator> ::= "+" | "-" | "*" | "/"
*/

int main()
{
	std::string program = readFile();

	Interpreter interpreter(program);

	interpreter.program();
	
}