#pragma once
#include "LexerState.h"

#include "Token.h"

class LexerStateStart :
	public LexerState
{
private:
	static LexerStateStart* _instance;

	LexerStateStart();

public:
	~LexerStateStart();

	virtual void HandleChar(Lexer* _lexer);

	virtual Token GetTokenType(Lexer* _lexer);

	static LexerStateStart* GetInstance();
};

