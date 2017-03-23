#pragma once

#include "stdafx.h"	
#include "TokenType.h"
#include "Lexer.h"

void PrintResult(Lexer& lexer)
{
	Token CurrToken;
	//���Է�����
	int iTokenCount = 0;
	//��¼���Է����͵��ַ���
	char pstrToken[128];
	//�����ļ�
	while(true)
	{
		//ȡ��һ�����Է�
		CurrToken = lexer.GetNextToken();

		//�����Է�����ת��Ϊһ�������ַ���
		switch (CurrToken)
		{
			//����
		case Lexer::TOKEN_TYPE_INT:
			//strcpy(pstrToken, "Integer");
			strcpy_s(pstrToken, sizeof("Integer"), "Integer");
			break;
		case Lexer::TOKEN_TYPE_FLOAT:
			//strcpy(pstrToken, "Float");
			strcpy_s(pstrToken, sizeof("Float"), "Float");
			break;
		case Lexer::TOKEN_TYPE_END_OF_STREAM:
			strcpy_s(pstrToken, sizeof("End"), "End");
			break;
		}

		//ȷ�����Է�û�н���
		if (CurrToken == Lexer::TOKEN_TYPE_END_OF_STREAM)
		{
			cout << iTokenCount << ": "
				<< "Token: " << pstrToken << endl;
			break;
		}

		//��ӡ���Է��ϵ���
		cout << iTokenCount << ": "
  			 << "Token: " << pstrToken << ", "
			 << "Lexeme: [ " << lexer.GetCurrLexeme() << " ]" << endl;
		++iTokenCount;
	}

	cout << endl;
	cout << "\tToken count: " << iTokenCount << endl;
}
