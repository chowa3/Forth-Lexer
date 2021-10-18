//  main.cpp
//  ForthLexer
//
//  Created by Chris on 10/14/21.
//

#include <iostream>
#include "Lexer.hpp"
#define INPUT_FILE "/Users/Chris/Documents/Languages/ForthLexer/ForthLexer/lexer_input2.txt"
#define TEST_FILE "/Users/Chris/Documents/Languages/ForthLexer/ForthLexer/input.txt"

int main(int argc, const char * argv[]) {
	Lexer L(INPUT_FILE);
	L.doLex();
	return 0;
}
