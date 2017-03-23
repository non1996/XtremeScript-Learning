#pragma once

#include "stdafx.h"

class Lexer;

typedef int Token;

class LexerState
{
public:
	LexerState();
	virtual ~LexerState();

	virtual void HandleChar(Lexer* _lexer) = 0;
	virtual Token GetTokenType() = 0;

	void ChangeState(Lexer* _lexer, LexerState* nextState);
};

