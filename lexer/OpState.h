#pragma once

class OpState					//�����״̬������ѯ��
{
private:
	char _cChar;				//״̬�ַ�
	int _iSubStateIndex;		//���״̬���������
	int _iSubStateCount;		//���״̬�ĸ���
	int _iIndex;				//���������

public:
	OpState();

	OpState(char cChar, int iSubStateIndex, int iSubStateCount, int iIndex);

	~OpState();

	char GetChar();

	int GetSubStateIndex();

	int GetSubStateCount();

	int GetIndex();
};

