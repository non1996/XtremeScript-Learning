// lexer.cpp : �������̨Ӧ�ó������ڵ㡣


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

	//�����ļ���С
	fseek(pSourceFile, 0, SEEK_END);
	iSourceSize = ftell(pSourceFile);
	fseek(pSourceFile, 0, SEEK_SET);

	g_pstrSource = unique_ptr<char>(new char[iSourceSize + 1]);

	//��ȡ���滻���з�
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
		//windows���з�Ϊ 0x0d 0x0a
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

	//����Ѿ������ļ���β���ͷ������������Է�
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

	//���ʽ�β��������һλ
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
	//����һ���Ľ���Ϊֹ��ʼһ���µĵ���
	m_iCurrLexemeStart = m_iCurrLexemeEnd;

	//��ʼ״̬
	SetState(LexerStateStart::GetInstance());

	//�����ַ����������ĵ�ǰλ��
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
