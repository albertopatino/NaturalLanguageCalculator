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
#ifndef _PARSER_HXX_
#define _PARSER_HXX_
#include "Scanner.hxx"
#include "Token.hxx"

namespace MyParser {
const int DivByZero=10; 
class Parser {
	Scanner *scanner;
	Token t;

	void expr(int &result);

	void exprT(int &result);

	void term(int &result);

	void factor(int &result);

	void unary(int &result);

	void numeral(int &result);

	void n3million(int &result);

	void fthousand(int &result);

	void n3(int &result);

	void fn3(int &result);

	int isUnit(int value);

	int isTen(int value);

	int isMten(int value);

	void fhundred(int &result);

	void ffh(int &result);

	void ften(int &result);

	void move();

public:

	Parser(Scanner &s);

	int parse(int &result);
};
}

#endif
