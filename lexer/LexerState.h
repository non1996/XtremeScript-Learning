#pragma once

#include "stdafx.h"
#include "Token.h"

class Lexer;

//�ʷ�������״̬
class LexerState
{
public:
	LexerState();
	virtual ~LexerState();

	virtual void HandleChar(Lexer* _lexer) = 0;				//����ǰ�ַ�
	
	virtual Token GetTokenType(Lexer* _lexer) = 0;			//��ȡ��ǰ�ʵ�����

	void ChangeState(Lexer* _lexer, LexerState* nextState);	//�ı�״̬
};

