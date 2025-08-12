#include "Interpreter.h"


Interpreter::Interpreter(std::string program)
	:lex(program)
{
	f_error = false;
	

	m_currentToken = lex.getNextToken();
	m_peekToken = lex.getNextToken();
}

Interpreter::~Interpreter()
{
}

void Interpreter::run()
{
	std::cout << "val = " << program() << "\n";
}

void Interpreter::printError()
{
	std::cout << "ERROR::Interpreter\n";
	f_error = true;
}

float Interpreter::program()
{
	float val = expression();

	
	while (m_currentToken.m_type != TokenType::EMPTY && !lex.checkError() && !f_error
		&& m_currentToken.m_type == TokenType::SHL || m_currentToken.m_type == TokenType::SHR)
	{

		switch (m_currentToken.m_type)
		{
		case TokenType::SHL:
			getToken();
			val = (int)val << (int)expression();
			break;

		case TokenType::SHR:
			getToken();
			val = (int)val >> (int)expression();
			break;
		}
	}

	return val;
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
			value += term();
			break;

		case TokenType::MINUS:
			getToken();
			value -= term();
			break;
		}
	}

	return value;
}


float Interpreter::integer()
{
	if (m_currentToken.m_type == TokenType::NUMBER)
	{
		float val = std::stoi(m_currentToken.m_text);
		getToken();

		return val;
	}
	else if (m_currentToken.m_type == TokenType::LPAREN)
	{
		getToken();

		float val = program();

		if (m_currentToken.m_type != TokenType::RPAREN)
		{
			printError();
			return 0;
		}
		else
		{
			getToken();
			return val;
		}
	}
	printError();

	return 0;
	

}