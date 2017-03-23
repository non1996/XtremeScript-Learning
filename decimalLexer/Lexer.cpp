// lexer.cpp : 定义控制台应用程序的入口点。


#include "stdafx.h"
#include "Lexer.h"
#include "LexerState.h"
#include "LexerStateStart.h"

Lexer::Lexer()
{
	InitLexer();
}


Lexer::~Lexer()
{
}

void Lexer::InitLexer()
{
	m_iCurrLexemeEnd	= 0;
	m_iCurrLexemeStart	= 0;
}

bool Lexer::LoadFile(const std::string & fileName)
{
	cout << "Lexical Analyzer Demo" << endl << endl;

	FILE* pSourceFile;

	//if (!(pSourceFile = fopen(fileName, "rb")))
	if (0 != fopen_s(&pSourceFile, fileName.c_str(), "rb"))
	{
		cout << "File I/O error" << endl;
		return false;
	}

	//计算文件大小
	fseek(pSourceFile, 0, SEEK_END);
	iSourceSize = ftell(pSourceFile);
	fseek(pSourceFile, 0, SEEK_SET);

	g_pstrSource = unique_ptr<char>(new char[iSourceSize + 1]);

	//读取并替换换行符
	LoadAndReplaceLF(pSourceFile);

	fclose(pSourceFile);
	return true;
}

void Lexer::LoadAndReplaceLF(FILE * pSourceFile)
{
	char cCurrChar;
	for (int iCurrCharIndex = 0; iCurrCharIndex < iSourceSize; ++iCurrCharIndex)
	{
		cCurrChar = fgetc(pSourceFile);
		//windows换行符为 0x0d 0x0a
		if (cCurrChar == 13)
		{
			fgetc(pSourceFile);
			--iSourceSize;
			g_pstrSource.get()[iCurrCharIndex] = '\n';
		}
		else
		{
			g_pstrSource.get()[iCurrCharIndex] = cCurrChar;
		}
	}
	g_pstrSource.get()[iSourceSize] = '\0';
}

void Lexer::GetNextChar()
{
	cCurrChar = g_pstrSource.get()[m_iCurrLexemeEnd++];
}

bool Lexer::IsCurrCharWhiteSpace()
{
	if (cCurrChar == ' ' || cCurrChar == '\t' || cCurrChar == '\n')
	{
		return true;
	}
	return false;
}

bool Lexer::IsCurrCharNumeric()
{
	if (cCurrChar >= '0' && cCurrChar <= '9')
	{
		return true;
	}
	return false;
}

bool Lexer::IsCurrCharPoint()
{
	return cCurrChar == '.';
}

Token Lexer::GetNextToken()
{
	CurrLexemeInit();

	//如果已经到了文件结尾，就返回流结束属性符
	if (m_iCurrLexemeStart >= (int)strlen(g_pstrSource.get()))
	{
		return TOKEN_TYPE_END_OF_STREAM;
	}

	while (true)
	{
		GetNextChar();
		
		if (GetEnd()) 
		{
			break;
		}

		CurrCharInit();

		HandleChar();

		AddCharToLexeme();

		if (iLexemeDone)
		{
			break;
		}
	}

	//单词结尾索引回退一位
	--m_iCurrLexemeEnd;

	return GetTokenType();
}

void Lexer::ExitOnInvalidInputError()
{
	cout << "Error: '" << cCurrChar << "' unexpected." << endl;
	exit(0);
}

const char * Lexer::GetCurrLexeme()
{
	return g_strCurrLexeme.c_str();
}

bool Lexer::GetEnd()
{
	return cCurrChar == '\0';
}

void Lexer::CurrCharInit()
{
	iAddCurrChar = true;
}

void Lexer::CurrLexemeInit()
{
	//从上一个的结束为止开始一个新的单词
	m_iCurrLexemeStart = m_iCurrLexemeEnd;

	//初始状态
	SetState(LexerStateStart::GetInstance());

	//单词字符串缓冲区的当前位置
	g_strCurrLexeme.clear();

	iLexemeDone = false;

}

void Lexer::AddCharToLexeme()
{
	if (iAddCurrChar)
	{
		g_strCurrLexeme += cCurrChar;
	}
}

Token Lexer::GetTokenType()
{
	return iCurrLexState->GetTokenType();
}

void Lexer::HandleChar()
{
	iCurrLexState->HandleChar(this);
}

void Lexer::SetState(LexerState * state)
{
	iCurrLexState = state;
}

void Lexer::CurrLexemeFinish()
{
	iAddCurrChar = false;
	iLexemeDone = true;
}

void Lexer::SkipWhiteSpace()
{
	++m_iCurrLexemeStart;
	iAddCurrChar = false;
}
