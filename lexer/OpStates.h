#pragma once

#include "stdafx.h"
#include "OpState.h"
#include "OpType.h"

class OpStates
{
private:
	std::vector<std::vector<OpState>> _opChars;
	
public:
	OpStates();
	~OpStates();

	bool IsCharOpChar(char cChar, int iCharIndex);

	int GetOpStateIndex(char cChar, int iCharIndex, int iSubStateIndex, int iSubStateCount);

	OpState& GetOpState(int iCharIndex, int iCurrOpStateIndex);

	OpState& GetOpState(char cChar, int iCharIndex, int iSubStateIndex, int iSubStateCount);
};

