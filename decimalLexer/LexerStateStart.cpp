#include "stdafx.h"
#include "LexerStateStart.h"
#include "Lexer.h"
#include "LexerStateInt.h"
#include "LexerStateFloat.h"

LexerStateStart* LexerStateStart::_instance = nullptr;

LexerStateStart::LexerStateStart()
{
}

LexerStateStart::~LexerStateStart()
{
}

void LexerStateStart::HandleChar(Lexer* _lexer)
{
	if (_lexer->IsCurrCharWhiteSpace())
	{
		_lexer->SkipWhiteSpace();
	}
	else if (_lexer->IsCurrCharNumeric())
	{
		ChangeState(_lexer, LexerStateInt::GetInstance());
	}
	else if (_lexer->IsCurrCharPoint())
	{
		ChangeState(_lexer, LexerStateFloat::GetInstance());
	}
	else
	{
		_lexer->ExitOnInvalidInputError();
	}
}

Token LexerStateStart::GetTokenType()
{
	return Lexer::TOKEN_TYPE_END_OF_STREAM;
}

LexerStateStart * LexerStateStart::GetInstance()
{
	if(_instance == nullptr)
	{
		_instance = new LexerStateStart();
	}
	return _instance;
}
