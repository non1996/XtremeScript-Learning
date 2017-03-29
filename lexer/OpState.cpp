#include "stdafx.h"
#include "OpState.h"


OpState::OpState()
{
}

OpState::OpState(char cChar, int iSubStateIndex, int iSubStateCount, int iIndex)
	:_cChar(cChar), _iSubStateIndex(iSubStateIndex), _iSubStateCount(iSubStateCount), _iIndex(iIndex)
{
}

OpState::~OpState()
{
}

char OpState::GetChar()
{
	return _cChar;
}

int OpState::GetSubStateIndex()
{
	return _iSubStateIndex;
}

int OpState::GetSubStateCount()
{
	return _iSubStateCount;
}

int OpState::GetIndex()
{
	return _iIndex;
}
