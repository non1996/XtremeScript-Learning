#pragma once
#include "LexerState.h"

class LexerStateStart :
	public LexerState
{
private:
	static LexerStateStart* _instance;

	LexerStateStart();

public:
	~LexerStateStart();

	virtual void HandleChar(Lexer* _lexer);

	virtual Token GetTokenType();

	static LexerStateStart* GetInstance();
};

