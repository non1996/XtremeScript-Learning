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

	unique_ptr<char> g_pstrSource;				//代码保存
	int iSourceSize;							//代码长度

	LexerState* iCurrLexState;					//状态

	char cCurrChar;								//当前分析的字符

	std::string g_strCurrLexeme;				//当前属性字

	bool iAddCurrChar;							//当前字符是否应该包括进单词
	bool iLexemeDone;							//表示单词完成的标志

	//----	运算符分析	---------------------------------------------------------------
	OpStates _opStates;							//合法运算符状态集
	OpCharAnalyser _opCharAnalyser;				//运算符分析状态记录

private:
	void LoadAndReplaceLF(FILE* pSourceFile);	//在windows中将换行符替换为\n

	void GetNextChar();							//获取当前字符

	void AddCharToLexeme();						//将当前字符添加到当前属性字字符串中

	bool GetEnd();								//到达文件尾

	void CurrCharInit();						//为分析当前字符做准备

	void CurrLexemeInit();

	Token GetTokenType();

	void HandleChar();

public:
	Lexer();
	~Lexer();

	void InitLexer();							//初始化词法分析器

	bool LoadFile(const std::string& fileName);	//读取源代码文件

	//----	判断字符类型	--------------------------------------------------------------
	bool IsCurrCharWhiteSpace();				//判断当前字符是不是空白符
	bool IsCurrCharNumeric();					//判断当前字符是不是数字
	bool IsCurrCharPoint();						//判断字符是不是小数点
	bool IsCurrCharIdent();						//判断字符是不是合理标识符
	bool IsCurrCharDelim();						//判断字符是不是分隔符
	bool IsCurrCharQuote();						//判断当前字符是不是双引号						
	bool IsCurrCharEscape();					//判断当前字符是不是转义字符
	bool IsCurrCharOpChar();					//判断当前字符是不是合法运算符
	
	//----	获取属性字信息	-------------------------------------------------------------
	Token GetNextToken();						//获取下一个属性类型（对外接口）
	const char* GetCurrLexeme();				//获取当前属性字							

	//----	改变状态		-------------------------------------------------------------
	void SetState(LexerState* state);

	//----	运算符分析	-----------------------------------------------------------------
	void InitAnalyseOpChar();					//初始化运算符分析
	bool HasNoSubState();						//判断当前运算符是否还有后继状态
	void SetNextOpState();						//获取下一个后继状态
	void ResetCurrOpIndex();					//重置运算符下标为0
	OpType GetCurrOp();

	//----	辅助		-----------------------------------------------------------------
	void CurrLexemeFinish();					
	void AddCurrChar(bool i);					//设置是否将当前字符加入单词中
	void SkipWhiteSpace();
	void ExitOnInvalidInputError();				//收到非法字符串
};
