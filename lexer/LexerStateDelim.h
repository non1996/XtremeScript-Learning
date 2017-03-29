#pragma once
#include "LexerState.h"

class LexerStateDelim :
	public LexerState
{
private:
	static LexerStateDelim* _instance;

	LexerStateDelim();
public:
	
	~LexerStateDelim();

	virtual void HandleChar(Lexer* _lexer);

	virtual Token GetTokenType(Lexer* _lexer);

	static LexerStateDelim* GetInstance();
};

