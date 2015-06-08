#ifndef _TOKEN_HXX_
#define _TOKEN_HXX_
namespace MyParser{

	enum TTYPE { NUMBER, NUMERAL, MULTIPLICATOR, OPERATOR, WORD, DELIMITER, UNKNOWN, EOL, 
				PLUS, MINUS, TIMES, DIV, HUNDRED=100, THOUSAND=1000, MILLION=1000000 };

	const int MAX_TOKEN_SIZE=512;

	class Token {
		TTYPE type;
		int value;
	public:

		Token();
	
		Token(TTYPE type,int value);

		TTYPE getType();

		int getValue();

		void setType(TTYPE t);

		void setValue(int v);
	};
}

#endif
