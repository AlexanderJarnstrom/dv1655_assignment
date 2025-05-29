compiler: lex.yy.c ./obj/parser.tab.o ./src/main.cc ./src/types.cc ./src/symbolTable.cc ./src/symanticFunction.cc
	g++ -ggdb -w -ocompiler ./obj/parser.tab.o lex.yy.c ./src/main.cc ./src/types.cc ./src/symbolTable.cc ./src/symanticFunction.cc -std=c++14

./obj/parser.tab.o: parser.tab.cc
		g++ -ggdb -w -c parser.tab.cc -std=c++14 -o ./obj/parser.tab.o

parser.tab.cc: parser.yy
	bison -v parser.yy

lex.yy.c: lexer.flex parser.tab.cc
		flex lexer.flex

tree: 
		 dot -Tpdf tree.dot -otree.pdf

clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.hh position.hh location.hh tree.dot tree.pdf
		rm -R compiler.dSYM

syntax: compiler testScript.py
	python testScript.py -syntax

