#pragma once

#include "stdafx.h"

class LexerState;

typedef int Token;

class Lexer
{
public:
	//Token type
	const static int TOKEN_TYPE_END_OF_STREAM = 0;
	const static int TOKEN_TYPE_INT = 1;
	const static int TOKEN_TYPE_FLOAT = 2;

private:
	int m_iCurrLexemeStart;
	int m_iCurrLexemeEnd;

	unique_ptr<char> g_pstrSource;				//���뱣��
	int iSourceSize;							//���볤��

	char cCurrChar;								//��ǰ�������ַ�

	std::string g_strCurrLexeme;				//��ǰ������

	bool iAddCurrChar;							//��ǰ�ַ��Ƿ�Ӧ�ð���������

	LexerState* iCurrLexState;					//״̬

	bool iLexemeDone;							//��ʾ������ɵı�־

private:
	void LoadAndReplaceLF(FILE* pSourceFile);	//��windows�н����з��滻Ϊ\n

	void GetNextChar();							//��ȡ��ǰ�ַ�

	void AddCharToLexeme();						//����ǰ�ַ���ӵ���ǰ�������ַ�����

	bool GetEnd();								//�����ļ�β

	void CurrCharInit();						//Ϊ������ǰ�ַ���׼��

	void CurrLexemeInit();

public:
	Lexer();
	~Lexer();

	void InitLexer();							//��ʼ���ʷ�������

	bool LoadFile(const std::string& fileName);	//��ȡԴ�����ļ�

	bool IsCurrCharWhiteSpace();				//�жϵ�ǰ�ַ��ǲ��ǿհ׷�

	bool IsCurrCharNumeric();					//�жϵ�ǰ�ַ��ǲ�������

	bool IsCurrCharPoint();						//�ж��ַ��ǲ���С����

	Token GetNextToken();						//��ȡ��һ���������ͣ�����ӿڣ�

	void ExitOnInvalidInputError();				//�յ��Ƿ��ַ���

	const char* GetCurrLexeme();				//��ȡ��ǰ������							

	Token GetTokenType();

	void HandleChar();

	void SetState(LexerState* state);

	void CurrLexemeFinish();

	void SkipWhiteSpace();
};
