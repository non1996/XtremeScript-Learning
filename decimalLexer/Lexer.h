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

	unique_ptr<char> g_pstrSource;				//代码保存
	int iSourceSize;							//代码长度

	char cCurrChar;								//当前分析的字符

	std::string g_strCurrLexeme;				//当前属性字

	bool iAddCurrChar;							//当前字符是否应该包括进单词

	LexerState* iCurrLexState;					//状态

	bool iLexemeDone;							//表示单词完成的标志

private:
	void LoadAndReplaceLF(FILE* pSourceFile);	//在windows中将换行符替换为\n

	void GetNextChar();							//获取当前字符

	void AddCharToLexeme();						//将当前字符添加到当前属性字字符串中

	bool GetEnd();								//到达文件尾

	void CurrCharInit();						//为分析当前字符做准备

	void CurrLexemeInit();

public:
	Lexer();
	~Lexer();

	void InitLexer();							//初始化词法分析器

	bool LoadFile(const std::string& fileName);	//读取源代码文件

	bool IsCurrCharWhiteSpace();				//判断当前字符是不是空白符

	bool IsCurrCharNumeric();					//判断当前字符是不是数字

	bool IsCurrCharPoint();						//判断字符是不是小数点

	Token GetNextToken();						//获取下一个属性类型（对外接口）

	void ExitOnInvalidInputError();				//收到非法字符串

	const char* GetCurrLexeme();				//获取当前属性字							

	Token GetTokenType();

	void HandleChar();

	void SetState(LexerState* state);

	void CurrLexemeFinish();

	void SkipWhiteSpace();
};
