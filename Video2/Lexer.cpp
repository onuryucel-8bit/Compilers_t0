#include "Lexer.h"

Lexer::Lexer(std::string file)
{
	m_file = file;
	
	m_position = -1;
	m_currentChar = 0;

	nextChar();
}

Lexer::~Lexer()
{
}

void Lexer::run()
{
	while (m_currentChar != EOF)
	{	
		Token token = getNextToken();
		std::cout << token.m_text << ":" << magic_enum::enum_name(token.m_type) << "\n";
		
	}
}

void Lexer::nextChar()
{
	m_position++;
	if (m_position >= m_file.length())
	{
		m_currentChar = EOF;
	}
	else
	{
		m_currentChar = m_file[m_position];
	}
}

Token Lexer::getNextToken()
{
	Token token;

	//0-9
	if (std::isdigit(m_currentChar))
	{
		token.m_text += m_currentChar;
		token.m_type = TokenType::Number;
	}
	else
	{
		switch (m_currentChar)
		{
		case '+':
			token.m_text += m_currentChar;
			token.m_type = TokenType::Plus;
			break;
		case '-':
			token.m_text += m_currentChar;
			token.m_type = TokenType::Minus;
			break;
		default:
			break;
		}
	}
	nextChar();

	return token;
}
