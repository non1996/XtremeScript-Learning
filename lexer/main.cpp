#include "stdafx.h"
#include "PrintResult.h"

int main()
{
	Lexer lex;

	lex.LoadFile("test.txt");

	PrintResult(lex);

	system("pause");

	return 0;
}
