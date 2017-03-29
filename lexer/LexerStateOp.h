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

	// ͨ�� LexerState �̳�
	virtual void HandleChar(Lexer * _lexer) override;
	virtual Token GetTokenType(Lexer * _lexer) override;

	static LexerStateOp* GetInstance();
};

