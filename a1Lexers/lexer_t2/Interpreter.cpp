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

void Interpreter::printError()
{
	std::cout << "ERROR::Interpreter\n";
	f_error = true;
}

void Interpreter::program()
{
	float result = integer();

	while (m_currentToken.m_type != TokenType::EMPTY && !lex.checkError() && !f_error)
	{
		getToken();

		std::cout << m_currentToken.m_text
			<< " : " << magic_enum::enum_name(m_currentToken.m_type)
			<< "\n";

		switch (m_currentToken.m_type)
		{
		case TokenType::PLUS:
			getToken();
			result += integer();
			break;

		case TokenType::MINUS:
			getToken();
			result -= integer();
			break;

		case TokenType::ASTERISK:
			getToken();
			result *= integer();
			break;

		case TokenType::SLASH:
			getToken();
			result /= integer();
			break;
		}
	}

	std::cout << "RESULT :: " << result << "\n";
}

void Interpreter::getToken()
{
	m_currentToken = m_peekToken;
	m_peekToken = lex.getNextToken();
}

int Interpreter::integer()
{
	if (m_currentToken.m_type != TokenType::NUMBER)
	{
		printError();

		return 0;
	}

	return std::stoi(m_currentToken.m_text);

}
