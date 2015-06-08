#ifndef _PARSERERROR_HXX_
#define _PARSERERROR_HXX_

namespace MyParser {

enum PARSER_ERROR_TYPE { INVALID_TOKEN, MISSING_PARENTHESIS };

class ParserError {
static const char *errors[];
PARSER_ERROR_TYPE errorno;

public:
	ParserError(PARSER_ERROR_TYPE errorno); 

	const char *getError();
};
}

#endif
