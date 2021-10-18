//
//  Enums.cpp
//  ForthLexer
//
//  Created by Chris on 10/14/21.
//
#pragma once
#include "tools.hpp"

using namespace std;

//Step 2.1
enum TokenType {
	WORD,
	NUMBER,
	STRING
};

//Step 2.2
enum StateType {
	START,
	ACQUIRE_TOKEN,
	ACQUIRE_STRING,
	ACQUIRE_SLASH,
	SLASH_PENDING,
	ACQUIRE_PAREN,
	PAREN_PENDING,
};
