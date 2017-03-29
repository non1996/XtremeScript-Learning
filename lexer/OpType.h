#pragma once

#include "stdafx.h"

enum class OpType
{
	ADD							= 0,	//	+
	SUB							= 1,	//	-
	MUL							= 2,	//	*
	DIV							= 3,	//	/
	MOD							= 4,	//	%
	EXP							= 5,	//	^
	INC							= 15,	//	++
	DEC							= 17,	//	--
	ASSIGN_ADD					= 14,	//	+=
	ASSIGN_SUB					= 16,	//	-=
	ASSIGN_MUL					= 18,	//	*=
	ASSIGN_DIV					= 19,	//	/=
	ASSIGN_MOD					= 20,	//	%=
	ASSIGN_EXP					= 21,	//	^=

	BITWISE_AND					= 6,	//	&
	BITWISE_OR					= 7,	//	|
	BITWISE_XOR					= 8,	//	#
	BITWISE_NOT					= 9,	//	~
	BITWISE_SHIFT_LEFT			= 30,	//	<<
	BITWISE_SHIFT_RIGHT			= 32,	//	>>
	BITWISE_ASSIGN_AND			= 22,	//	&=
	BITWISE_ASSIGN_OR			= 24,	//	|=
	BITWISE_ASSIGN_XOR			= 26,	//	#=
	BITWISE_ASSIGN_SHIFT_LEFT	= 33,	//	<<=
	BITWISE_ASSIGN_SHIFT_RIGHT	= 34,	//	>>=

	LOGICAL_AND					= 23,	//	&&
	LOGICAL_OR					= 25,	//	||
	LOGICAL_NOT					= 10,	//	!

	EQUAL						= 28,	//	==
	NOT_EQUAL					= 27,	//	!=
	LESS						= 12,	//	<
	GREATER						= 13,	//	>
	LESS_EQUAL					= 29,	//	<=
	GREATER_EQUAL				= 31	//	>=
};