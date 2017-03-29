#pragma once
#include "LexerState.h"

class LexerStateIdent :
	public LexerState
{
private:
	static LexerStateIdent* _instance;

	LexerStateIdent();

public:
	~LexerStateIdent();

	virtual void HandleChar(Lexer* _lexer);

	virtual Token GetTokenType(Lexer* _lexer);

	static LexerStateIdent* GetInstance();
};

