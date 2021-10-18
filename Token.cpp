//  Token.cpp
//  ForthLexer
//
//  Created by Chris on 10/14/21.
//
#include "Token.hpp"

const char* tokens[6] = {"word ", "number ", "string "};

//Step 3.1.1 and 3.1.2
Token::Token(string name, TokenType type): name(name), type(type) {
	count = 1;
}

//Step 3.1.3
ostream& Token::print(ostream& out){
	out << tokens[type] << '\t' << count << endl;
	return out;
}

void Token::increment(){
	count++;
}
