OBJS=main.o Token.o Scanner.o Parser.o ParserError.o Numeral.o
CC=g++
DEBUG=-g
OPTIONS=-c

calculator:		$(OBJS)
			$(CC) $(OBJS) -o calculator

main.o:	main.cxx
		$(CC) $(OPTIONS) $(DEBUG) main.cxx -o main.o

Scanner.o: Scanner.cxx Scanner.hxx
		$(CC) $(OPTIONS) $(DEBUG) Scanner.cxx -o Scanner.o

Token.o: Token.cxx Token.hxx
		$(CC) $(OPTIONS) $(DEBUG) Token.cxx -o Token.o

Parser.o: Parser.cxx Parser.hxx
		$(CC) $(OPTIONS) $(DEBUG) Parser.cxx -o Parser.o

ParserError.o: ParserError.cxx ParserError.hxx
		$(CC) $(OPTIONS) $(DEBUG) ParserError.cxx -o ParserError.o

Numeral.o: Numeral.cxx Numeral.hxx
		$(CC) $(OPTIONS) $(DEBUG) Numeral.cxx -o Numeral.o

clean:
	rm *.o calculator
