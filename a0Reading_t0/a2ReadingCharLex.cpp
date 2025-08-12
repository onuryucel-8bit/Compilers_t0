#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

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

class Lexer
{
public:
	Lexer(std::string program);

	char nextChar();

private:
	std::string m_program;
	int m_position;
};

char Lexer::nextChar()
{
	m_position++;
	if (m_position >= m_program.length())
	{
		return EOF;
	}

	return m_program[m_position];
}

Lexer::Lexer(std::string program)
{
	m_program = program;
	m_position = -1;	
}

int main()
{
	std::string program = readFile();

	Lexer lex(program);

	char c = lex.nextChar();
	while (c != EOF)
	{
		std::cout << c << "\n";
		c = lex.nextChar();		
	}
}