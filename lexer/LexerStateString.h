#pragma once
#include "LexerState.h"
class LexerStateString :
	public LexerState
{
private:
	static LexerStateString* _instance;

public:
	LexerStateString();
	~LexerStateString();

	
	virtual void HandleChar(Lexer* _lexer);

	virtual Token GetTokenType(Lexer* _lexer);

	static LexerStateString* GetInstance();
};

