#pragma once

#include "stdafx.h"
#include "OpState.h"
#include "OpType.h"


class OpCharAnalyser
{
private:
	int _iCurrOpCharIndex;					//	当前运算符下标，0 ~ 2
	int _iCurrOpStateIndex;					//	当前运算符状态下标
	OpState _currOpState;						//	当前运算符状态
	OpType _iCurrOp;							//	当前运算符类型符

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

