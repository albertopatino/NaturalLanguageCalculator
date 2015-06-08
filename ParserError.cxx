/*
 *  Calculator Assignment
 *
 *  Top Down Parser 
 *
 */

#include "ParserError.hxx"

namespace MyParser {

ParserError::ParserError(PARSER_ERROR_TYPE errorno) {
	this->errorno=errorno;	
}

const char *ParserError::getError() {
	return errors[errorno];
}

const char *ParserError::errors[] = {"INVALID TOKEN","PARENTESIS ERROR"};
}
