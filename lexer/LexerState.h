#pragma once

#include "stdafx.h"
#include "Token.h"

class Lexer;

//词法分析器状态
class LexerState
{
public:
	LexerState();
	virtual ~LexerState();

	virtual void HandleChar(Lexer* _lexer) = 0;				//处理当前字符
	
	virtual Token GetTokenType(Lexer* _lexer) = 0;			//获取当前词的类型

	void ChangeState(Lexer* _lexer, LexerState* nextState);	//改变状态
};

