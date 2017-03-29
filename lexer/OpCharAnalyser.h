#pragma once

#include "stdafx.h"
#include "OpState.h"
#include "OpType.h"


class OpCharAnalyser
{
private:
	int _iCurrOpCharIndex;					//	��ǰ������±꣬0 ~ 2
	int _iCurrOpStateIndex;					//	��ǰ�����״̬�±�
	OpState _currOpState;						//	��ǰ�����״̬
	OpType _iCurrOp;							//	��ǰ��������ͷ�

public:
	OpCharAnalyser();
	~OpCharAnalyser();

	void SetCurrOpState(const OpState& opState);

	OpState& GetCurrOpState();

	OpType GetCurrOpType();

	void SetCurrOpType(OpType type);

	void SetCurrOpCharIndex(int iCurrOpCharIndex);

	int GetCurrOpCharIndex();

	void IncCurrOpCharIndex();
};

