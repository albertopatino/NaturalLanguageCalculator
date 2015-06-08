/*
 *  Calculator Assignment
 *
 *  Top Down Parser 
 *
 *  
 */

#ifndef _SCANNER_HXX_
#define _SCANNER_HXX_
#include <iostream>
#include <sstream>
#include "Token.hxx"
#include "Numeral.hxx"

namespace MyParser{

	using std::istream;

	class Scanner {
		istream *is;
		char buffer[MAX_TOKEN_SIZE];
		Numeral *numeral;

		int readChar();

		void putChar(int ch);

		int isNumeral(string s, int &value);

		int isMultiplicator(string s, int &value);

		int isOperator(string s, int &value);

		public:
	
		Scanner(istream &is); 

		Token scan(); 

	};
}
#endif
