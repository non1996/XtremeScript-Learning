#pragma once
#include "LexerState.h"

class LexerStateStringCloseQuote :
	public LexerState
{
private:
	static LexerStateStringCloseQuote* _instance;
public:
	LexerStateStringCloseQuote();
	~LexerStateStringCloseQuote();

	// ͨ�� LexerState �̳�
	virtual void HandleChar(Lexer * _lexer) override;
	virtual Token GetTokenType(Lexer * _lexer) override;

	static LexerStateStringCloseQuote* GetInstance();
};

