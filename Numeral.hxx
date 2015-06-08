/*
 *  Calculator Assignment
 *
 *  Top Down Parser 
 *
 */
#ifndef _NUMERAL_HXX_
#define _NUMERAL_HXX_

#include <string>
#include <map>

namespace MyParser {

using std::map;
using std::string;

class Numeral {
static map<string,int> englishMap;
static map<string,int> germanMap;

public:

	map<string,int> *getEnglishMap();
};
}
#endif 
