# NaturalLanguageCalculator
LL Parser
NaturalLanguageCalculator
This calculator use Natural Language text as input. Just google "three times one thousand"

I checked implementations and papers from internet but no one was complete. For example I checked perl libraries Lingua::EN::Words2Num and Parse::RecDescendant but I was not convinced to follow those as references.

./LALR directory has lex and yacc files to generate parser. This was the first approach I selected to solve the problem, so the challenge was to generate the right context free grammar to parse numbers as strings. Then I thought externalize parse() funtion to use in C++ program. Finally I decided remove left side recursion from grammar and develop top down parser. This approach was more instructive and fun to implement. ./LL directory has implementation for the top down parser

Instructions:

Just run make command in proper subdirectory

$ make

make clean will remove generated files to start from zero

$ make clean

calculator program will be generated Just run ./calculator for command promt

$ ./calculator

References:

Dragon Book Second Edition Flex and Bison O'Reilly Book Internet, http://blog.cordiner.net/2010/01/02/parsing-english-numbers-with-perl/
