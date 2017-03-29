#include "stdafx.h"

#include "Lexer.h"
#include "LexerStateStart.h"
#include "LexerStateInt.h"
#include "LexerStateFloat.h"
#include "LexerStateIdent.h"
#include "LexerStateDelim.h"
#include "LexerStateString.h"
#include "LexerStateOp.h"

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
	else if (_lexer->IsCurrCharIdent())
	{
		ChangeState(_lexer, LexerStateIdent::GetInstance());
	}
	else if (_lexer->IsCurrCharDelim())
	{
		ChangeState(_lexer, LexerStateDelim::GetInstance());
	}
	else if (_lexer->IsCurrCharOpChar())
	{
		_lexer->InitAnalyseOpChar();
		ChangeState(_lexer, LexerStateOp::GetInstance());
	}
	else if (_lexer->IsCurrCharQuote())
	{
		_lexer->AddCurrChar(false);								//收到引号进入接收字符串状态，且不把引号加入字符串
		ChangeState(_lexer, LexerStateString::GetInstance());
	}
	else
	{
		_lexer->ExitOnInvalidInputError();
	}
}

Token LexerStateStart::GetTokenType(Lexer* _lexer)
{
	return Token::TOKEN_TYPE_END_OF_STREAM;
}

LexerStateStart * LexerStateStart::GetInstance()
{
	if(_instance == nullptr)
	{
		_instance = new LexerStateStart();
	}
	return _instance;
}
