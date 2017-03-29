#include "stdafx.h"
#include "LexerStateFloat.h"
#include "Lexer.h"
#include "LexerStateInt.h"

LexerStateFloat* LexerStateFloat::_instance = nullptr;

LexerStateFloat::LexerStateFloat()
{
}

LexerStateFloat::~LexerStateFloat()
{
}

void LexerStateFloat::HandleChar(Lexer* _lexer)
{
	if (_lexer->IsCurrCharNumeric())
	{
	}
	else if (_lexer->IsCurrCharWhiteSpace() || _lexer->IsCurrCharDelim())
	{
		_lexer->CurrLexemeFinish();
	}
	else
	{
		_lexer->ExitOnInvalidInputError();
	}
}

Token LexerStateFloat::GetTokenType(Lexer* _lexer)
{
	return Token::TOKEN_TYPE_FLOAT;
}

LexerStateFloat * LexerStateFloat::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new LexerStateFloat();
	}
	return _instance;
}
