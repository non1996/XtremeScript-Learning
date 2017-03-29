#include "stdafx.h"
#include "LexerStateIdent.h"

#include "Lexer.h"

LexerStateIdent* LexerStateIdent::_instance = nullptr;

LexerStateIdent::LexerStateIdent()
{
}


LexerStateIdent::~LexerStateIdent()
{
}

void LexerStateIdent::HandleChar(Lexer * _lexer)
{
	if (_lexer->IsCurrCharIdent())
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

Token LexerStateIdent::GetTokenType(Lexer* _lexer)
{
	if (_stricmp(_lexer->GetCurrLexeme(), "var") == 0)
		return Token::TOKEN_TYPE_RSRVD_VAR;
	if (_stricmp(_lexer->GetCurrLexeme(), "true") == 0)
		return Token::TOKEN_TYPE_RSRVD_TRUE;
	if (_stricmp(_lexer->GetCurrLexeme(), "false") == 0)
		return Token::TOKEN_TYPE_RSRVD_FALSE;
	if (_stricmp(_lexer->GetCurrLexeme(), "if") == 0)
		return Token::TOKEN_TYPE_RSRVD_IF;
	if (_stricmp(_lexer->GetCurrLexeme(), "else") == 0)
		return Token::TOKEN_TYPE_RSRVD_ELSE;
	if (_stricmp(_lexer->GetCurrLexeme(), "break") == 0)
		return Token::TOKEN_TYPE_RSRVD_BREAK;
	if (_stricmp(_lexer->GetCurrLexeme(), "continue") == 0)
		return Token::TOKEN_TYPE_RSRVD_CONTINUE;
	if (_stricmp(_lexer->GetCurrLexeme(), "for") == 0)
		return Token::TOKEN_TYPE_RSRVD_FOR;
	if (_stricmp(_lexer->GetCurrLexeme(), "while") == 0)
		return Token::TOKEN_TYPE_RSRVD_WHILE;
	if (_stricmp(_lexer->GetCurrLexeme(), "func") == 0)
		return Token::TOKEN_TYPE_RSRVD_FUNC;
	if (_stricmp(_lexer->GetCurrLexeme(), "return") == 0)
		return Token::TOKEN_TYPE_RSRVD_RETURN;
	return Token::TOKEN_TYPE_IDENT;
}

LexerStateIdent * LexerStateIdent::GetInstance()
{
	if (_instance == nullptr) 
	{
		_instance = new LexerStateIdent();
	}
	return _instance;
}
