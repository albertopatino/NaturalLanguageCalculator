/*
 *  Calculator Assignment
 *
 *  Top Down Parser 
 *
 *  
 */

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <string.h>
#include "Scanner.hxx"

namespace MyParser {

int Scanner::readChar(){
	return is->get();
}

void Scanner::putChar(int ch){
	is->putback(ch);
}

int Scanner::isNumeral(string s, int &value) {
	value=0;
	map<string,int> *m;

	m=numeral->getEnglishMap();
	for( map<string, int>::iterator ii=m->begin(); ii!=m->end(); ++ii)
	{
		if ( !s.compare((*ii).first) ) {
			value=(*ii).second;
			return 1;
		}

	}
	return 0;
}

int Scanner::isMultiplicator(string s, int &value) {
	value=0;

	//cout << "String: " << s << "\n";
	if ( !s.compare("hundred") ) {
		value=100;
		return 1;
	}
	if ( !s.compare("thousand") ) {
		value=1000;
		return 1;
	}
	if ( !s.compare("million") ) {
		value=1000000;
		return 1;
	}
	return 0;
}

int Scanner::isOperator(string s, int &value) {
	value=0;

	//cout << "String: " << s << "\n";
	if ( !s.compare("plus") ) {
		value=PLUS;
		return 1;
	}
	if ( !s.compare("minus") ) {
		value=MINUS;
		return 1;
	}
	if ( !s.compare("times") ) {
		value=TIMES;
		return 1;
	}
	if ( !s.compare("div") ) {
		value=DIV;
		return 1;
	}
	return 0;
}

Scanner::Scanner(istream &is) {
	numeral=new Numeral;
	this->is=&is;
}

Token Scanner::scan() {
	char *p='\0';
	Token token;
	int ch;
	int value=0;
	int hasDigit=0;

	while((ch=readChar())==' ' || ch=='\t' );

	if (ch=='\r' || ch==std::char_traits<char>::eof()){
       	token.setType(EOL);
       	token.setValue(0);
       	return token;
   	}

	p=buffer;

	if ( isdigit(ch) ) {
	*p++=ch;
	token.setType(NUMBER);
    do {
          value=10*value+ch-0x30;
             *p++=ch;
             ch=readChar();
         } while(isdigit(ch));
		putChar(ch);
        token.setValue(value);
        *p='\0';
        return token;
    }

    if ( isalpha(ch) ) {
        token.setType(WORD);
        do {
            *p++=ch;
            ch=readChar();
			hasDigit+=isdigit(ch);
        } while(isdigit(ch)||isalpha(ch)||ch=='_');
		putChar(ch);
        *p='\0';

		if ( !hasDigit ) { // No Digits in WORD
			if (isMultiplicator(buffer,value)) {

				token.setType(MULTIPLICATOR);
				token.setValue(value);
				return token;		// MULTIPLICATOR
			} 
			if (isNumeral(buffer,value)) {
				token.setType(NUMERAL);

				token.setValue(value);
				return token;		// NUMERAL
			} 
			if (isOperator(buffer,value)) {
				token.setType(OPERATOR);
				token.setValue(value);
				return token;	// OPERATOR
			}
		}
        return token;	// WORD
    }

	if ( strchr("(){};,+-/*=",ch) ) {	
		token.setType(DELIMITER);
		token.setValue(ch); // WARNING: NOT OVERLAP ENUM
		return token;	// DELIMITER
	}

	token.setType(UNKNOWN);
	return token;	// UNKNOWN
}
}
