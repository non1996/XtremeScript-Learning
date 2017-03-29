#pragma once

class OpState					//运算符状态，供查询用
{
private:
	char _cChar;				//状态字符
	int _iSubStateIndex;		//后继状态数组的索引
	int _iSubStateCount;		//后继状态的个数
	int _iIndex;				//运算符索引

public:
	OpState();

	OpState(char cChar, int iSubStateIndex, int iSubStateCount, int iIndex);

	~OpState();

	char GetChar();

	int GetSubStateIndex();

	int GetSubStateCount();

	int GetIndex();
};

