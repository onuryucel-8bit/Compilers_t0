#include "Lexer.h"

void Lexer::nextChar()
{
	m_position++;
	if (m_position >= m_program.length())
	{
		m_currentChar = EOF;
	}
	else
	{
		m_currentChar = m_program[m_position];
	}
	
}

Lexer::Lexer(std::string program)
{
	m_program = program;
	m_position = -1;
	m_currentChar = 0;

	nextChar();
}

Lexer::~Lexer()
{
}

void Lexer::printError(std::string message)
{
	std::cout <<"ERROR::"<< message << "\n";
}

Token Lexer::getNextToken()
{
	Token token;

	if (m_currentChar == EOF)
	{
		return Token{ "EOF", TokenType::EMPTY};
	}
	else if (std::isdigit(m_currentChar))
	{
		token = Token{ std::string(1, m_currentChar), TokenType::NUMBER };
	}
	else
	{
		switch (m_currentChar)
		{
		case '+':
			token = Token{ std::string(1, m_currentChar), TokenType::PLUS };
			break;
		}
	}
	
	nextChar();

	return token;
}
