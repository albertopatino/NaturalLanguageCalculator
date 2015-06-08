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
 *	Factor: ( Exp ) | numeral | -numeral | number | -number
 *
 */

#include "Parser.hxx"
#include "ParserError.hxx"

namespace MyParser {

void Parser::expr(int &result){
	int temp=0;
	term(result);
	exprT(result);
}

void Parser::exprT(int &result){
int temp=0;
int moreOps=1;

	if	( t.getType()==DELIMITER || t.getType() == OPERATOR ){
		while(moreOps) {
			switch(t.getValue()){
				case '+':
				case PLUS:{
					move();
					term(temp);
					result+=temp;
					break;
				}
				case '-':
				case MINUS: {
					move();
					term(temp);
					result-=temp;
					break;
				}
				default: {
					moreOps=0;
				}
			}
		}
	}
}

void Parser::term(int &result){
int temp=0;
int moreOps=1;

	factor(result);
	if	( t.getType()==DELIMITER || t.getType() == OPERATOR ){
		while(moreOps) {
			switch(t.getValue()){
				case '*':
				case TIMES:{
					move();
					factor(temp);
					result*=temp;
					break;
				}
				case '/':
				case DIV: {
					move();
					factor(temp);
					if (temp==0) {
						throw DivByZero;
					}
					result/=temp;
					break;
				}
				default: {
					moreOps=0;
				}
			}
		}
	}
}

void Parser::factor(int &result) {

	if	( t.getType()==DELIMITER &&  t.getValue()=='(' ) {
		move();
		expr(result);
		if ( (t.getType()==DELIMITER || t.getType() == EOL) && t.getValue()!=')' ) {
			throw ParserError(MISSING_PARENTHESIS);
		}
		move();
		return;
	}
	unary(result);
}

void Parser::unary(int &result) {
int mult=1;

	if	( t.getType()==DELIMITER &&  t.getValue()=='-' || 
 		 t.getType()==OPERATOR &&  t.getValue()==MINUS ) {
		mult=-1;
		move();
	}

	if	( t.getType()==NUMERAL ) {
		numeral(result);
		result*=mult;
		return;
	}

	if	( t.getType()==NUMBER ) {
		result=t.getValue();
		result*=mult;
		move();
		return;
	}
	throw ParserError(INVALID_TOKEN);
}

void Parser::numeral(int &result) {
int temp=0;

	if	( t.getType()==NUMERAL && t.getValue()==0 ){
		result=0;
		move();
		return;
	}
	n3million(temp);
	result=temp;
}

void Parser::n3million(int &result) {
int temp=0;

	n3(result);
	int mult=t.getType();
	if( mult == MULTIPLICATOR ) {
		switch(t.getValue()) {
			case MILLION: {
				result*=MILLION;
				move();
				fthousand(temp);
				result+=temp;
				return;
			}
			case THOUSAND: {
				result*=THOUSAND;
				move();
				fn3(temp);
				result+=temp;
				return;
			}
			default: {
				throw ParserError(INVALID_TOKEN);
			}
		}
	}
}

void Parser::fthousand(int &result){
int temp=0;

	n3(result);
	int mult=t.getType();
	if( mult == MULTIPLICATOR ) {
		switch(t.getValue()) {
			case THOUSAND: {
				result*=THOUSAND;
				move();
				fn3(temp);
				result+=temp;
				return;
			}
			default: {
				throw ParserError(INVALID_TOKEN);
			}
		}
	}
}

void Parser::n3(int &result){
int temp=0;

	if ( t.getType()==NUMERAL) {

		if(isUnit(t.getValue())){
			temp=t.getValue();	
			move();
			fhundred(temp);
			result+=temp;
			return;
		}
		if(isTen(t.getValue())){
			temp=t.getValue();	
			move();
			result+=temp;
			return;
		}
		if(isMten(t.getValue())){
			temp=t.getValue();	
			move();
			ften(temp);
			result+=temp;
			return;
		}
		throw ParserError(INVALID_TOKEN);
	}
}

void Parser::fn3(int &result){
int temp=0;
	if ( t.getType()==NUMERAL) {
		if(isUnit(t.getValue())){
			temp=t.getValue();	
			move();
			fhundred(temp);
			result=temp;
			return;
		}
		if(isTen(t.getValue())){
			temp=t.getValue();	
			move();
			result=temp;
			return;
		}
		if(isMten(t.getValue())){
			temp=t.getValue();	
			move();
			ften(temp);
			result=temp;
			return;
		}
	}
}

int Parser::isUnit(int value) {
	switch(value){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9: {
			return 1;
		}
	}
	return 0;
}

int Parser::isTen(int value) {
	switch(value){
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18: 
		case 19: {
			return 1;
		}
	}
	return 0;
}

int Parser::isMten(int value) {
	switch(value){
		case 20:
		case 30:
		case 40:
		case 50:
		case 60:
		case 70:
		case 80:
		case 90: {
				return 1;
		}
	}
	return 0;
}

void Parser::fhundred(int &result) {
	int temp=0;
	if ( t.getType()==MULTIPLICATOR ) {
		switch(t.getValue()){
			case HUNDRED: {
				temp=result*100;
				move();
				ffh(temp);
				result=temp;
			}
		}
	}
}

void Parser::ffh(int &result){
	int temp=0;
	if ( t.getType() == NUMERAL ) {
		if(isUnit(t.getValue()) || isTen(t.getValue())){
			temp=t.getValue();	
			move();
			result+=temp;
			return;
		}
		if(isMten(t.getValue())){
			temp=t.getValue();	
			move();
			ften(temp);
			result+=temp;
			return;
		}
	}
}

void Parser::ften(int &result) {
	int temp=t.getValue();
	if ( t.getType() == NUMERAL ) {
		if(isUnit(temp)){
			move();
			result+=temp;
			return;
		}
		throw ParserError(INVALID_TOKEN);
	}
}

void Parser::move() {
	t=scanner->scan();
		//cout << "Token[" << t.getType() << "," << t.getValue() << "]\n";
}

Parser::Parser(Scanner &s) {
	scanner=&s;
}

int Parser::parse(int &result) {
	move();
	if (t.getType()==EOL)
		return 1;
		//numeral(result);
	expr(result);
	if (t.getType() != EOL) {
		throw ParserError(INVALID_TOKEN);
	}
	return 0;
}
}
