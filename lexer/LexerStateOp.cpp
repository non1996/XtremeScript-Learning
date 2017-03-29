#include "stdafx.h"
#include "LexerStateOp.h"
#include "Lexer.h"

LexerStateOp* LexerStateOp::_instance = nullptr;

LexerStateOp::LexerStateOp()
{
}


LexerStateOp::~LexerStateOp()
{
}

void LexerStateOp::HandleChar(Lexer * _lexer)
{
	if (_lexer->HasNoSubState())
	{
		_lexer->CurrLexemeFinish();
		_lexer->ResetCurrOpIndex();
		return;
	}
	if (_lexer->IsCurrCharOpChar())
	{
		_lexer->SetNextOpState();
	}
	else
	{
		_lexer->CurrLexemeFinish();
		_lexer->ResetCurrOpIndex();
	}
}

Token LexerStateOp::GetTokenType(Lexer * _lexer)
{
	return Token::TOKEN_TYPE_OP;
}

LexerStateOp * LexerStateOp::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new LexerStateOp();
	}
	return _instance;
}
