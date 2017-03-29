#pragma once

#include "stdafx.h"
#include "Token.h"
#include "OpStates.h"
#include "OpCharAnalyser.h"
class LexerState;


class Lexer
{
private:
//	char cDelims[MAX_DELIM_COUNT] = { ',', '(', ')', '[', ']', '{', '}', ';' };
	std::string validDelimes = ",()[]{};";

private:
	int m_iCurrLexemeStart;
	int m_iCurrLexemeEnd;

	unique_ptr<char> g_pstrSource;				//���뱣��
	int iSourceSize;							//���볤��

	LexerState* iCurrLexState;					//״̬

	char cCurrChar;								//��ǰ�������ַ�

	std::string g_strCurrLexeme;				//��ǰ������

	bool iAddCurrChar;							//��ǰ�ַ��Ƿ�Ӧ�ð���������
	bool iLexemeDone;							//��ʾ������ɵı�־

	//----	���������	---------------------------------------------------------------
	OpStates _opStates;							//�Ϸ������״̬��
	OpCharAnalyser _opCharAnalyser;				//���������״̬��¼

private:
	void LoadAndReplaceLF(FILE* pSourceFile);	//��windows�н����з��滻Ϊ\n

	void GetNextChar();							//��ȡ��ǰ�ַ�

	void AddCharToLexeme();						//����ǰ�ַ���ӵ���ǰ�������ַ�����

	bool GetEnd();								//�����ļ�β

	void CurrCharInit();						//Ϊ������ǰ�ַ���׼��

	void CurrLexemeInit();

	Token GetTokenType();

	void HandleChar();

public:
	Lexer();
	~Lexer();

	void InitLexer();							//��ʼ���ʷ�������

	bool LoadFile(const std::string& fileName);	//��ȡԴ�����ļ�

	//----	�ж��ַ�����	--------------------------------------------------------------
	bool IsCurrCharWhiteSpace();				//�жϵ�ǰ�ַ��ǲ��ǿհ׷�
	bool IsCurrCharNumeric();					//�жϵ�ǰ�ַ��ǲ�������
	bool IsCurrCharPoint();						//�ж��ַ��ǲ���С����
	bool IsCurrCharIdent();						//�ж��ַ��ǲ��Ǻ����ʶ��
	bool IsCurrCharDelim();						//�ж��ַ��ǲ��Ƿָ���
	bool IsCurrCharQuote();						//�жϵ�ǰ�ַ��ǲ���˫����						
	bool IsCurrCharEscape();					//�жϵ�ǰ�ַ��ǲ���ת���ַ�
	bool IsCurrCharOpChar();					//�жϵ�ǰ�ַ��ǲ��ǺϷ������
	
	//----	��ȡ��������Ϣ	-------------------------------------------------------------
	Token GetNextToken();						//��ȡ��һ���������ͣ�����ӿڣ�
	const char* GetCurrLexeme();				//��ȡ��ǰ������							

	//----	�ı�״̬		-------------------------------------------------------------
	void SetState(LexerState* state);

	//----	���������	-----------------------------------------------------------------
	void InitAnalyseOpChar();					//��ʼ�����������
	bool HasNoSubState();						//�жϵ�ǰ������Ƿ��к��״̬
	void SetNextOpState();						//��ȡ��һ�����״̬
	void ResetCurrOpIndex();					//����������±�Ϊ0
	OpType GetCurrOp();

	//----	����		-----------------------------------------------------------------
	void CurrLexemeFinish();					
	void AddCurrChar(bool i);					//�����Ƿ񽫵�ǰ�ַ����뵥����
	void SkipWhiteSpace();
	void ExitOnInvalidInputError();				//�յ��Ƿ��ַ���
};
