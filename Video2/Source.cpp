#include "Fileio/FileReader.h"
#include "Lexer.h"

int main()
{
	FileReader fr;
	Lexer lex(fr.read("program.txt"));
	lex.run();
}