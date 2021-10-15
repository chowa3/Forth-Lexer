//  Lexer.hpp
//  ForthLexer
//
//  Created by Chris on 10/14/21.
//

#pragma once
#include "Token.hpp"

using namespace std;

//Step 3.2.1
class Lexer{
	private:
		StateType state;
		ifstream fileIn;
		ofstream fileOut;
		map<string, Token> tMap;
		char currentChar;
		TokenType current;
		string tokenString;
		
	public:
		Lexer(string fname);
		~Lexer();
		ostream& print(ostream& out);
		bool isNumber();
		void doLex();
		void doToken(string name, TokenType tt);
		void doStart();
		void acquireSlash();
		void slashPending();
		void acquireParen();
		void acquireToken();
		void acquireString();
};
inline ostream& operator<<(ostream& out, Lexer& c){ return c.print(out); }
