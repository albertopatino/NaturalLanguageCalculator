/*
 *  Calculator Assignment
 *
 *  Top Down Parser 
 *
 *  
 *	Exp: 	Term Exp'
 *	Exp':	+Term Exp' | -Term Exp' | e
 *	Term:	Factor Term'
 *	Term':	*Factor Term' | /Factor Term' | e
 *	Factor: ( E ) | numeral | number
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include "Parser.hxx"
#include "Scanner.hxx"
#include "Token.hxx"
#include "ParserError.hxx"

using MyParser::Token;
using MyParser::Scanner;
using MyParser::Parser;
using MyParser::ParserError;

using namespace std;

int main(int argc, char **argv) {
string			cnumber;
char ch;
Token token;
int result=0;
const int DIV_BY_ZERO=10;

string tag(" and ");
string spaces("     ");
		
 	cout << "Calculator:" << endl << "Use (+|plus) (-|minus) (*|times) (/|div) operators" << endl;
 	cout << "And Numbers as Strings:" << endl;
 	cout << "Example: ((three hundred and nine) times (one plus nine)) times minus ten plus zero" << endl;
 	cout << "Type \"quit\" to exit" << endl;
	
	do{
		cout << "Input String>";
		getline(cin, cnumber);

		// replace " and " with spaces
		// Check spaces surrounding "and"
		// otherwise "thousand" word could be truncated to "thous   " 
		int i=cnumber.find(tag, 0);
		while ( i!=string::npos ){
			cnumber.replace(i,tag.size(),spaces);
			i=cnumber.find(tag, i+tag.size());
		}

		istringstream iss(cnumber);
		istream is(iss.rdbuf());
	
		Scanner lex(is);
		Parser parser(lex);

		try {
			parser.parse(result);
			cout << "Result: " << result << endl;	
		} catch (ParserError p) {
			cout << "Parse Error: " << p.getError() << endl;	
		} catch (const int intEx) {
			if(intEx==DIV_BY_ZERO) 
				cout << "Bivide By Zero Exception: "<< endl;	
		}
	} while(cnumber.compare("quit"));
}
