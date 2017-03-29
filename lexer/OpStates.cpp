#include "stdafx.h"
#include "OpStates.h"


OpStates::OpStates()
{
	_opChars = { 
				 {	
					{ '+', 0, 2, 0 },{ '-', 2, 2, 1 },{ '*', 4, 1, 2 },{ '/', 5, 1, 3 },
					{ '%', 6, 1, 4 },{ '^', 7, 1, 5 },{ '&', 8, 2, 6 },{ '|', 10, 2, 7 },
					{ '#', 12, 1, 8 },{ '~', 0, 0, 9 },{ '!', 13, 1, 10 },{ '=', 14, 1, 11 },
					{ '<', 15, 2, 12 },{ '>', 17, 2, 13 } 
				 },

				 {	
					{ '=', 0, 0, 14 },{ '+', 0, 0, 15 },     // +=, ++
					{ '=', 0, 0, 16 },{ '-', 0, 0, 17 },     // -=, --
					{ '=', 0, 0, 18 },                        // *=
					{ '=', 0, 0, 19 },                        // /=
					{ '=', 0, 0, 20 },                        // %=
					{ '=', 0, 0, 21 },                        // ^=
					{ '=', 0, 0, 22 },{ '&', 0, 0, 23 },     // &=, &&
					{ '=', 0, 0, 24 },{ '|', 0, 0, 25 },     // |=, ||
					{ '=', 0, 0, 26 },                        // #=
					{ '=', 0, 0, 27 },                        // !=
					{ '=', 0, 0, 28 },                        // ==
					{ '=', 0, 0, 29 },{ '<', 0, 1, 30 },     // <=, <<
					{ '=', 0, 0, 31 },{ '>', 1, 1, 32 }		// >=, >> 
				 },   

				 {
					{ '=', 0, 0, 33 },{ '=', 0, 0, 34 }		// <<=, >>= 
				 } 
			}; 
}


OpStates::~OpStates()
{
}

bool OpStates::IsCharOpChar(char cChar, int iCharIndex)
{
	for (auto iter = _opChars.at(iCharIndex).begin(); iter != _opChars.at(iCharIndex).end(); ++iter)
	{
		if (cChar == iter->GetChar())
		{
			return true;
		}
	}
	return false;
}

int OpStates::GetOpStateIndex(char cChar, int iCharIndex, int iSubStateIndex, int iSubStateCount)
{
	int iStartStateIndex = 0;
	int iEndStateIndex = _opChars.at(iCharIndex).size();

	if (iCharIndex != 0)		//如果是运算符的第一个字符
	{
		iStartStateIndex = iSubStateIndex;
		iEndStateIndex = iStartStateIndex + iSubStateCount;
	}

	for (int iCurrOpStateIndex = iStartStateIndex; iCurrOpStateIndex < iEndStateIndex; ++iCurrOpStateIndex)
	{
		if (cChar == _opChars.at(iCharIndex).at(iCurrOpStateIndex).GetChar())
		{
			return iCurrOpStateIndex;
		}
	}
	return -1;
}

OpState & OpStates::GetOpState(int iCharIndex, int iCurrOpStateIndex)
{
	return _opChars.at(iCharIndex).at(iCurrOpStateIndex);
}

OpState & OpStates::GetOpState(char cChar, int iCharIndex, int iSubStateIndex, int iSubStateCount)
{
	return GetOpState(iCharIndex, GetOpStateIndex(cChar, iCharIndex, iSubStateIndex, iSubStateCount));
}
