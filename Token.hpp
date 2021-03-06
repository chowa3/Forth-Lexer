//  Token.hpp
//  ForthLexer
//
//  Created by Chris on 10/14/21.
//

#pragma once
#include "Enums.hpp"

using namespace std;

class Token{
	private:
		string name;
		TokenType type;
		
	public:
		Token() = default;
		Token(string name, TokenType type);
		~Token() = default;
		ostream& print(ostream& out);
		void increment();
		int count;
};
inline ostream& operator<<(ostream& out, Token& c){ return c.print(out); }
