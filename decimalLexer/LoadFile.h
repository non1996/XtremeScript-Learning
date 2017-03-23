#pragma once

#include "stdafx.h"

void LoadAndReplaceLF(FILE* pSourceFile, char** g_ppstrSource, int iSourceSize)
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
			(*g_ppstrSource)[iCurrCharIndex] = '\n';
		}
		else
		{
			(*g_ppstrSource)[iCurrCharIndex] = cCurrChar;
		}
	}
	(*g_ppstrSource)[iSourceSize] = '\0';
}

bool LoadFile(const char* fileName, char** g_ppstrSource)
{
	cout << "Lexical Analyzer Demo" << endl << endl;

	FILE* pSourceFile;

	if (!(pSourceFile = fopen(fileName, "rb"))) 
	{
		cout << "File I/O error" << endl;
		return false;
	}

	//�����ļ���С
	fseek(pSourceFile, 0, SEEK_END);
	int iSourceSize = ftell(pSourceFile);
	fseek(pSourceFile, 0, SEEK_SET);

	*g_ppstrSource = (char*)malloc(iSourceSize + 1);

	//��ȡ���滻���з�
	LoadAndReplaceLF(pSourceFile, g_ppstrSource, iSourceSize);

	fclose(pSourceFile);
	return true;
}
