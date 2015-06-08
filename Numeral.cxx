/*
 *  Calculator Assignment
 *
 *  Top Down Parser 
 *
 */
#include "Numeral.hxx"

namespace MyParser{

map<string,int> * Numeral::getEnglishMap() {
	return &englishMap;
}

namespace {
	map<string,int> createEngMap() {
  		map<string, int> m;
		m["zero"]=0;
		m["one"]=1;
		m["two"]=2;
		m["three"]=3;
		m["four"]=4;
		m["five"]=5;
		m["six"]=6;
		m["seven"]=7;
		m["eight"]=8;
		m["nine"]=9;
		m["ten"]=10;
		m["eleven"]=11;
		m["twelve"]=12;
		m["thirteen"]=13;
		m["fourteen"]=14;
		m["fifteen"]=15;
		m["sixteen"]=16;
		m["seventeen"]=17;
		m["eighteen"]=18;
		m["nineteen"]=19;
		m["twenty"]=20;
		m["thirty"]=30;
		m["forty"]=40;
		m["fifty"]=50;
		m["sixty"]=60;
		m["seventy"]=70;
		m["eighty"]=80;
		m["ninety"]=90;
		m["hundred"]=100;
		m["thousand"]=1000;
		m["million"]=1000000;	

		return m;
	}

	map<string,int> createDeuMap() {
  		map<string, int> m;
		m["null"]=0;
		m["eins"]=1;
		m["zwei"]=2;
		m["drei"]=3;
		m["vier"]=4;
		m["fünf"]=5;
		m["sechs"]=6;
		m["sieben"]=7;
		m["acht"]=8;
		m["neun"]=9;
		m["zehn"]=10;
		m["elf"]=11;
		m["zwölf"]=12;
		m["dreizehn"]=13;
		m["vierzehn"]=14;
		m["fünfzehn"]=15;
		m["sechszehn"]=16;
		m["siebzehn"]=17;
		m["achtzehn"]=18;
		m["neunzehn"]=19;
		m["zwanzig"]=20;
		m["dreißig"]=30;
		m["vierzig"]=40;
		m["fünfzig"]=50;
		m["sechzig"]=60;
		m["siebzig"]=70;
		m["achtzig"]=80;
		m["neunzig"]=90;
		m["hundert"]=100;
		m["tausend"]=1000;
		m["million"]=1000000;

  		return m;
	}
}

map<string, int> Numeral::englishMap=createEngMap();
map<string, int> Numeral::germanMap=createDeuMap();
}
