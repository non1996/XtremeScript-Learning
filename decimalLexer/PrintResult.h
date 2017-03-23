#pragma once

#include "stdafx.h"	
#include "TokenType.h"
#include "Lexer.h"

void PrintResult(Lexer& lexer)
{
	Token CurrToken;
	//属性符个数
	int iTokenCount = 0;
	//记录属性符类型的字符串
	char pstrToken[128];
	//分析文件
	while(true)
	{
		//取下一个属性符
		CurrToken = lexer.GetNextToken();

		//将属性符代码转换为一个描述字符串
		switch (CurrToken)
		{
			//整形
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

		//确保属性符没有结束
		if (CurrToken == Lexer::TOKEN_TYPE_END_OF_STREAM)
		{
			cout << iTokenCount << ": "
				<< "Token: " << pstrToken << endl;
			break;
		}

		//打印属性符合单词
		cout << iTokenCount << ": "
  			 << "Token: " << pstrToken << ", "
			 << "Lexeme: [ " << lexer.GetCurrLexeme() << " ]" << endl;
		++iTokenCount;
	}

	cout << endl;
	cout << "\tToken count: " << iTokenCount << endl;
}
