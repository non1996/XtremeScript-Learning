#include "stdafx.h"

#include "Lexer.h"
#include "LexerStateDelim.h"


LexerStateDelim* LexerStateDelim::_instance = nullptr;

LexerStateDelim::LexerStateDelim()
{
}


LexerStateDelim::~LexerStateDelim()
{
}

void LexerStateDelim::HandleChar(Lexer * _lexer)
{
	_lexer->CurrLexemeFinish();
}

Token LexerStateDelim::GetTokenType(Lexer * _lexer)
{
	switch (_lexer->GetCurrLexeme()[0])
	{
	case ',':
		return Token::TOKEN_TYPE_DELIM_COMMA;
	case '(':
		return Token::TOKEN_TYPE_DELIM_OPEN_PAREN;
	case ')':
		return Token::TOKEN_TYPE_DELIM_CLOSE_PAREN;
	case '[':
		return Token::TOKEN_TYPE_DELIM_OPEN_BRACE;
	case ']':
		return Token::TOKEN_TYPE_DELIM_CLOSE_BRACE;
	case '{':
		return Token::TOKEN_TYPE_DELIM_OPEN_CURLY_BRACE;
	case '}':
		return Token::TOKEN_TYPE_DELIM_CLOSE_CURLY_BRACE;
	case ';':
		return Token::TOKEN_TYPE_DELIM_SEMICOLON;
	}
}

LexerStateDelim * LexerStateDelim::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new LexerStateDelim();
	}
	return _instance;
}
