#include "stdafx.h"
#include "LexerStateString.h"
#include "Lexer.h"
#include "LexerStateStringCloseQuote.h"
#include "LexerStateStringEscape.h"

LexerStateString* LexerStateString::_instance = nullptr;

LexerStateString::LexerStateString()
{
}


LexerStateString::~LexerStateString()
{
}

void LexerStateString::HandleChar(Lexer * _lexer)
{
	if (_lexer->IsCurrCharQuote())
	{
		_lexer->AddCurrChar(false);
		ChangeState(_lexer, LexerStateStringCloseQuote::GetInstance());
	}
	else if (_lexer->IsCurrCharEscape())
	{
		_lexer->AddCurrChar(false);
		ChangeState(_lexer, LexerStateStringEscape::GetInstance());
	}
}

Token LexerStateString::GetTokenType(Lexer * _lexer)
{
	throw std::logic_error("should not call GetTokenType() with state LexerStateString.");
	return Token::TOKEN_TYPE_STRING;
}

LexerStateString * LexerStateString::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new LexerStateString();
	}
	return _instance;
}
