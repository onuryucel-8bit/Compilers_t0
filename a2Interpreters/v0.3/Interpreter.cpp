#include "Interpreter.h"


Interpreter::Interpreter(std::string program)
	:lex(program)
{
	f_error = false;
	m_result = 0;

	m_currentToken = lex.getNextToken();
	m_peekToken = lex.getNextToken();
}

Interpreter::~Interpreter()
{
}

void Interpreter::printError()
{
	std::cout << "ERROR::Interpreter\n";
	f_error = true;
}

void Interpreter::program()
{
	m_result = expression();

	
	while (m_currentToken.m_type != TokenType::EMPTY && !lex.checkError() && !f_error
		&& m_currentToken.m_type == TokenType::SHL || m_currentToken.m_type == TokenType::SHR)
	{

		switch (m_currentToken.m_type)
		{
		case TokenType::SHL:
			getToken();
			m_result = (int)m_result << (int)expression();
			break;

		case TokenType::SHR:
			getToken();
			m_result = (int)m_result >> (int)expression();
			break;
		}
	}

	/*
	std::cout << m_currentToken.m_text
			  << " : " << magic_enum::enum_name(m_currentToken.m_type)
			  << "\n";
	*/

	
	

	std::cout << ">" << m_result << "\n";
}

float Interpreter::term()
{	
	float value = integer();

	while (m_currentToken.m_type == TokenType::ASTERISK 
		|| m_currentToken.m_type == TokenType::SLASH
		|| m_currentToken.m_type == TokenType::MOD )
	{
		
		switch (m_currentToken.m_type)
		{
		case TokenType::ASTERISK:
			getToken();
			value *= integer();
			break;

		case TokenType::SLASH:
			getToken();
			value /= integer();
			break;

		case TokenType::MOD:
			getToken();
			value = (int)value % (int)integer();
			break;
		}
	}

	return value;
}

void Interpreter::getToken()
{
	m_currentToken = m_peekToken;
	m_peekToken = lex.getNextToken();
}

float Interpreter::expression()
{

	float value = term();

	while (m_currentToken.m_type == TokenType::PLUS || m_currentToken.m_type == TokenType::MINUS)
	{

		switch (m_currentToken.m_type)
		{
		case TokenType::PLUS:
			getToken();
			m_result += term();
			break;

		case TokenType::MINUS:
			getToken();
			m_result -= term();
			break;
		}
	}

	return value;
}


float Interpreter::integer()
{
	if (m_currentToken.m_type != TokenType::NUMBER)
	{
		printError();

		return 0;
	}
	float value = std::stoi(m_currentToken.m_text);
	getToken();

	return value;

}