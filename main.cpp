//  main.cpp
//  ForthLexer
//
//  Created by Chris on 10/14/21.
//

#include <iostream>
#include "Lexer.hpp"

int main(int argc, const char * argv[]) {
	Token x("name", WORD);
	x.increment();
	x.print(cout);

	Token y("name", NUMBER);
	y.print(cout);

	Token z("name", STRING);
	z.print(cout);
	
	Lexer L("/Users/Chris/Documents/Languages/ForthLexer/ForthLexer/input.txt");
	L.doLex();
	L.print(cout);
	cout << "It works!\n";
	return 0;
}
