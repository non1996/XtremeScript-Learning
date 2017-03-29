#include "stdafx.h"
#include "OpCharAnalyser.h"


OpCharAnalyser::OpCharAnalyser()
{
	_iCurrOpCharIndex = 0;
	_iCurrOpStateIndex = 0;
}


OpCharAnalyser::~OpCharAnalyser()
{
}

void OpCharAnalyser::SetCurrOpState(const OpState & opState)
{
	_currOpState = opState;
	SetCurrOpType((OpType)_currOpState.GetIndex());
}

OpState & OpCharAnalyser::GetCurrOpState()
{
	return _currOpState;
}

OpType OpCharAnalyser::GetCurrOpType()
{
	return _iCurrOp;
}

void OpCharAnalyser::SetCurrOpType(OpType type)
{
	_iCurrOp = type;
}

void OpCharAnalyser::SetCurrOpCharIndex(int iCurrOpCharIndex)
{
	_iCurrOpCharIndex = iCurrOpCharIndex;
}

int OpCharAnalyser::GetCurrOpCharIndex()
{
	return _iCurrOpCharIndex;
}

void OpCharAnalyser::IncCurrOpCharIndex()
{
	_iCurrOpCharIndex++;
}
