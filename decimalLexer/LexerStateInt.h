#pragma once
#include "LexerState.h"

class LexerStateInt :
	public LexerState
{
private:
	static LexerStateInt* _instance;
	
	LexerStateInt();

public:

	~LexerStateInt();

	virtual void HandleChar(Lexer* _lexer);
	virtual Token GetTokenType();

	static LexerStateInt* GetInstance();
};

