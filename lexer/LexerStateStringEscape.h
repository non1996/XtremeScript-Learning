#pragma once
#include "LexerState.h"
class LexerStateStringEscape :
	public LexerState
{
private:
	static LexerStateStringEscape* _instance;

public:
	LexerStateStringEscape();
	~LexerStateStringEscape();

	virtual void HandleChar(Lexer* _lexer);

	virtual Token GetTokenType(Lexer* _lexer);

	static LexerStateStringEscape* GetInstance();
};

