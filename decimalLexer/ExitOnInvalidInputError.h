#pragma once

#include "stdafx.h"

void ExitOnInvalidInputError(char cInput)
{
	cout << "Error: '" << cInput << "' unexpected." << endl;
	exit(0);
}