#include "stdafx.h"
#include "LexerStateInt.h"
#include "Lexer.h"
#include "LexerStateFloat.h"

LexerStateInt* LexerStateInt::_instance = nullptr;

LexerStateInt::LexerStateInt()
{
}

LexerStateInt::~LexerStateInt()
{
}

void LexerStateInt::HandleChar(Lexer* _lexer)
{
	if (_lexer->IsCurrCharNumeric())
	{
	}
	else if (_lexer->IsCurrCharPoint())
	{
		ChangeState(_lexer, LexerStateFloat::GetInstance());
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

Token LexerStateInt::GetTokenType(Lexer* _lexer)
{
	return Token::TOKEN_TYPE_INT;
}

LexerStateInt * LexerStateInt::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new LexerStateInt();
	}
	return _instance;
}
