#pragma once
#include "LexerState.h"

class LexerStateOp :
	public LexerState
{
private:
	static LexerStateOp* _instance;

	LexerStateOp();

public:
	~LexerStateOp();

	// Í¨¹ý LexerState ¼Ì³Ð
	virtual void HandleChar(Lexer * _lexer) override;
	virtual Token GetTokenType(Lexer * _lexer) override;

	static LexerStateOp* GetInstance();
};

