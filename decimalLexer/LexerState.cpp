#include "stdafx.h"

#include "Lexer.h"
#include "LexerState.h"

LexerState::LexerState()
{
}


LexerState::~LexerState()
{
}

void LexerState::ChangeState(Lexer* _lexer, LexerState * nextState)
{
	_lexer->SetState(nextState);
}
