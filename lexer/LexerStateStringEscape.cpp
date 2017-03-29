#include "stdafx.h"
#include "LexerStateStringEscape.h"
#include "Lexer.h"
#include "LexerStateString.h"

LexerStateStringEscape* LexerStateStringEscape::_instance = nullptr;

LexerStateStringEscape::LexerStateStringEscape()
{
}

LexerStateStringEscape::~LexerStateStringEscape()
{
}

void LexerStateStringEscape::HandleChar(Lexer * _lexer)
{
	ChangeState(_lexer, LexerStateString::GetInstance());
}

Token LexerStateStringEscape::GetTokenType(Lexer * _lexer)
{
	throw std::logic_error("should not call GetTokenType() with state LexerStateStringEscape.");
	return Token();
}

LexerStateStringEscape * LexerStateStringEscape::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new LexerStateStringEscape();
	}
	return _instance;
}
