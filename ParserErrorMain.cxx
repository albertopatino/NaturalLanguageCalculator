#include <iostream>

using std::cout;
//#include "ParserError.hxx"

enum PARSER_ERROR_TYPE { INVALID_TOKEN, MISSING_PARENTHESIS };

class ParserError {
static const char *errors[];
PARSER_ERROR_TYPE errorno;

public:
	ParserError(PARSER_ERROR_TYPE errorno); 

	const char *getError();
};
//using MyParser::ParserError;

int main(void){

ParserError p(INVALID_TOKEN);

cout << "done!";

}
