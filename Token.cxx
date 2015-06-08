/*
 *  Calculator Assignment
 *
 *  Top Down Parser 
 *
 *
 */

#include "Token.hxx"

namespace MyParser{
    Token::Token() {
    	this->type=UNKNOWN;
    	this->value=UNKNOWN;
    }

    Token::Token(TTYPE type,int value){
    	this->type=type;
    	this->value=value;
    }

    TTYPE Token::getType() {
    	return type;
    }

    int Token::getValue(){
    	return value;
    }

    void Token::setType(TTYPE t){ 
    	type=t;
    }

    void Token::setValue(int v){
    	value=v;
    }
}
