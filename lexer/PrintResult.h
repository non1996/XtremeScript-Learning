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
		case Token::TOKEN_TYPE_INT:
			strcpy_s(pstrToken, "Integer");
			break;
		case Token::TOKEN_TYPE_FLOAT:
			strcpy_s(pstrToken, "Float");
			break;
		case Token::TOKEN_TYPE_END_OF_STREAM:
			strcpy_s(pstrToken, "End");
			break;
		case Token::TOKEN_TYPE_IDENT:
			strcpy_s(pstrToken, "Identifier");
			break;
		case Token::TOKEN_TYPE_RSRVD_VAR:
			strcpy_s(pstrToken, "var");
			break;

		case Token::TOKEN_TYPE_RSRVD_TRUE:
			strcpy_s(pstrToken, "true");
			break;

		case Token::TOKEN_TYPE_RSRVD_FALSE:
			strcpy_s(pstrToken, "false");
			break;

		case Token::TOKEN_TYPE_RSRVD_IF:
			strcpy_s(pstrToken, "if");
			break;

		case Token::TOKEN_TYPE_RSRVD_ELSE:
			strcpy_s(pstrToken, "else");
			break;

		case Token::TOKEN_TYPE_RSRVD_BREAK:
			strcpy_s(pstrToken, "break");
			break;

		case Token::TOKEN_TYPE_RSRVD_CONTINUE:
			strcpy_s(pstrToken, "continue");
			break;

		case Token::TOKEN_TYPE_RSRVD_FOR:
			strcpy_s(pstrToken, "for");
			break;

		case Token::TOKEN_TYPE_RSRVD_WHILE:
			strcpy_s(pstrToken, "while");
			break;

		case Token::TOKEN_TYPE_RSRVD_FUNC:
			strcpy_s(pstrToken, "func");
			break;

		case Token::TOKEN_TYPE_RSRVD_RETURN:
			strcpy_s(pstrToken, "return");
			break;

		case Token::TOKEN_TYPE_OP:
			sprintf_s(pstrToken, "Operator %d", (int)lexer.GetCurrOp());
			break;

		case Token::TOKEN_TYPE_DELIM_COMMA:
			strcpy_s(pstrToken, "Comma");
			break;

		case Token::TOKEN_TYPE_DELIM_OPEN_PAREN:
			strcpy_s(pstrToken, "Opening Parenthesis");
			break;

		case Token::TOKEN_TYPE_DELIM_CLOSE_PAREN:
			strcpy_s(pstrToken, "Closing Parenthesis");
			break;

		case Token::TOKEN_TYPE_DELIM_OPEN_BRACE:
			strcpy_s(pstrToken, "Opening Brace");
			break;

		case Token::TOKEN_TYPE_DELIM_CLOSE_BRACE:
			strcpy_s(pstrToken, "Closing Brace");
			break;

		case Token::TOKEN_TYPE_DELIM_OPEN_CURLY_BRACE:
			strcpy_s(pstrToken, "Opening Curly Brace");
			break;

		case Token::TOKEN_TYPE_DELIM_CLOSE_CURLY_BRACE:
			strcpy_s(pstrToken, "Closing Curly Brace");
			break;

		case Token::TOKEN_TYPE_DELIM_SEMICOLON:
			strcpy_s(pstrToken, "Semicolon");
			break;

		case Token::TOKEN_TYPE_STRING:
			strcpy_s(pstrToken, "String");
			break;
		}

		//确保属性符没有结束
		if (CurrToken == Token::TOKEN_TYPE_END_OF_STREAM)
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
