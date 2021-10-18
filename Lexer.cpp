//  Lexer.cpp
//  ForthLexer
//
//  Created by Chris on 10/14/21.
//

#include "Lexer.hpp"
#define OUTPUT_FILE "/Users/Chris/Documents/Languages/ForthLexer/ForthLexer/output.txt"

Lexer::Lexer(string fname){
	state = START; //Needed to start the process. TESTED: WORKING.
	
	//Read in the Forth source code.
	fileIn.open (fname, ios_base::in); //open file in read mode.
	if (fileIn.is_open() != true){
		fatal("Error: could not open input file. \n");
	}
	
	//Output symbol table in human readable format.
	fileOut.open (OUTPUT_FILE, ios_base::out); //open file in write mode.
	if (fileOut.is_open() != true){
		fatal("Error: could not open SymbolTable.txt. \n");
	} else {
		//Step 3.2.2
		fileOut << "Chris Howard" << endl;
		fileOut << "Lab 3: Forth Lexer" << endl;
		fileOut << "Comments" << endl;
	}
}

Lexer::~Lexer() {
	fileIn.close();
	print(cout);
	print(fileOut);
	fileOut.close();
};

//Step 3.2.5
ostream& Lexer::print(ostream& out){
	//map<string, Token> tMap
	//Auto was the simplest way to get this to work.
	out << "------------------------------------------------------------" << endl;
	for (auto& it : tMap){
		out << setw(30) << left << it.first << " " << it.second << endl;
	}
	return out;
}

//Step 3.2.4
void Lexer::doLex(){
	while (!fileIn.eof()){
		fileIn.get(currentChar);
		
		switch(state) {
			case START: doStart(); //Step 4.1
				break;
			case SLASH_PENDING: slashPending(); //Step 4.2
				break;
			case ACQUIRE_SLASH: acquireSlash(); //Step 4.3
				break;
			case ACQUIRE_PAREN: acquireParen(); //Step 4.5
				break;
			case ACQUIRE_TOKEN: acquireToken(); //Step 4.6
				break;
			case ACQUIRE_STRING: acquireString(); //Step 4.7
				break;
			case PAREN_PENDING:
				//Step 4.4
				if (currentChar == ' ' || currentChar != '\t'){
					state = ACQUIRE_PAREN;
					fileOut << currentChar;
				} else {
					state = ACQUIRE_TOKEN;
				}
				break;
			default:
				break;
		}
	}
}

//Step 3.2.7
void Lexer::doStart(){
	if (currentChar == ' ' || currentChar == '\t'){
		//Do nothing to break out of switch statement in calling function.
	}else if (currentChar == '\\' ){
		state = SLASH_PENDING;
		fileOut << currentChar;
	}else if (currentChar == '('){
		state = PAREN_PENDING;
		fileOut << currentChar;
	}else{
		state = ACQUIRE_TOKEN;
		if (currentChar != ' ' && currentChar != '\n' && currentChar != '\t'){
			tokenString.push_back(currentChar);
		}
	}
}

//Step 4.2
void Lexer::slashPending(){
	fileOut << currentChar;
	if (currentChar==' ' || currentChar != '\t'){
		state = ACQUIRE_SLASH;
	} else {
		state = ACQUIRE_TOKEN;
	}
}

//Step 4.3
void Lexer::acquireSlash(){
	char buffer[256];
	fileOut << currentChar;
	fileIn.getline(buffer, 256, '\n');
	fileOut << buffer << endl;
	state = START;
}

//Step 4.5
void Lexer::acquireParen(){
	char buffer[256];
	fileOut << currentChar;
	fileIn.getline(buffer, 256, ')');
	fileOut << buffer << ")" << endl;
	state = START;
}

//Step 4.6
void Lexer::acquireToken(){
	string dot = ".\"";
	
	//If statement doesn't work when nested.
	if (tokenString.compare(dot) == 0){
		//."
		doToken(tokenString, WORD);
		state = ACQUIRE_STRING;
	}
	
	if (currentChar != ' ' && currentChar != '\n' && currentChar != '\t'
	&& tokenString.compare(dot) != 0){
		tokenString.push_back(currentChar);
	} else if (isNumber()){
		//number
		doToken(tokenString, NUMBER);
		state = START;
	} else {
		//word
		doToken(tokenString, WORD);
		state = START;
	}
}

//Step 6
void Lexer::doToken(string name, TokenType tt){
	//map<string, Token> tMap;
	if (tMap.count(name)>0){
		tMap.at(name).increment();
	} else {
		Token temp(name, tt);
		tMap[name] = temp;
	}
	tokenString = ""; //Reset for next token.
}

//Step 4.7
void Lexer::acquireString(){
	//Tokenize the string and drop the quotes.
	while (true){
		if (currentChar == '\"'){
			doToken(tokenString, STRING);
			state = START;
			break;
		}
		tokenString.push_back(currentChar);
		fileIn.get(currentChar);
	}
}

bool Lexer::isNumber(){
	bool answer; //Starts as a number.
	
	//If the first element is a number. Then all elements must be numbers for it to be a number.
	if (tokenString[0] >= '0' && tokenString[0] <= '9'){
		answer = true;
		//For each element in the array. Test if it is a number.
		for (int i = 1; i < tokenString.length(); i++){
			//If a char other than number is found. Enter dead state (always false).
			if (tokenString[i] < '0' || tokenString[i] > '9'){
				answer = false;
				break;
			}
		}
	} else {
	//If the first element is a letter. Then it is a word.
		answer = false;
	}
	
	return answer;
}
