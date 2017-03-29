#include "stdafx.h"
#include "LexerStateStringCloseQuote.h"
#include "Lexer.h"

LexerStateStringCloseQuote* LexerStateStringCloseQuote::_instance = nullptr;

LexerStateStringCloseQuote::LexerStateStringCloseQuote()
{
}


LexerStateStringCloseQuote::~LexerStateStringCloseQuote()
{
}

void LexerStateStringCloseQuote::HandleChar(Lexer * _lexer)
{
	_lexer->CurrLexemeFinish();
}

Token LexerStateStringCloseQuote::GetTokenType(Lexer * _lexer)
{
	return Token::TOKEN_TYPE_STRING;
}

LexerStateStringCloseQuote * LexerStateStringCloseQuote::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new LexerStateStringCloseQuote();
	}
	return _instance;
}
