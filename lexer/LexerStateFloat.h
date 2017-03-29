#pragma once
#include "LexerState.h"

class LexerStateFloat :
	public LexerState
{
private:
	static LexerStateFloat* _instance;

	LexerStateFloat();

public:
	
	~LexerStateFloat();

	virtual void HandleChar(Lexer* _lexer);
	virtual Token GetTokenType(Lexer* _lexer);

	static LexerStateFloat* GetInstance();
};

