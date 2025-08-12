#include "Lexer.h"
Lexer::Lexer(std::string program)
{
	m_program = program;
	m_position = -1;
	m_currentChar = 0;

	f_error = false;

	nextChar();
}

Lexer::~Lexer()
{
}

void Lexer::printError(std::string message)
{
	std::cout <<  "ERROR::" << message << " m_currentChar:["<< m_currentChar <<"]\n";
	f_error = true;
}

void Lexer::skipWhiteSpace()
{
	while (m_currentChar == ' ' || m_currentChar == '\t')
	{
		nextChar();
	}
}

char Lexer::peek()
{
	if (m_position + 1 >= m_program.length())
	{
		return ENDOFLINE;
	}
	return m_program[m_position + 1];
}

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

Token Lexer::lexInteger()
{
	size_t startPos = m_position;
	size_t length = 1;

	std::string tokenStr(1, m_currentChar);
	while (std::isdigit(peek()))
	{
		nextChar();
		tokenStr += m_currentChar;
	}

	return Token{ tokenStr, TokenType::NUMBER };
}

Token Lexer::lexSingleChar()
{
	Token token;

	switch (m_currentChar)
	{
	case '+':
		token = Token{ std::string(1, m_currentChar), TokenType::PLUS };
		break;

	case '-':
		token = Token{ std::string(1, m_currentChar), TokenType::MINUS };
		break;

	case '*':
		token = Token{ std::string(1, m_currentChar), TokenType::ASTERISK };
		break;

	case '/':
		token = Token{ std::string(1, m_currentChar), TokenType::SLASH };
		break;

	case '%':
		token = Token{ std::string(1, m_currentChar), TokenType::MOD};
		break;

	case '<':
		if (peek() == '<')
		{
			token = Token{ "<<", TokenType::SHL};
			nextChar();
		}
		
		break;

	case '>':
		if (peek() == '>')
		{
			token = Token{ ">>", TokenType::SHR};
			nextChar();
		}
		
		break;

	default:
		printError("Lexer::getNextToken()::Undefined token");
		token = Token{ std::string(1, m_currentChar), TokenType::ENDOFLINE };
		break;
	}

	return token;
}

Token Lexer::getNextToken()
{
	Token token;

	skipWhiteSpace();

	if (m_currentChar == EOF)
	{
		return Token{ "EOF", TokenType::EMPTY};
	}
	//NUMBER
	else if (std::isdigit(m_currentChar))
	{
		token = lexInteger();
	}
	else
	{
		token = lexSingleChar();
	}
	
	nextChar();

	return token;
}

bool Lexer::checkError()
{
	return f_error;
}
