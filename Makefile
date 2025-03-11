compiler: lex.yy.c parser.tab.o main.cc SymbolTable.cc SemanticFunctions.cc
		g++ -ggdb -w -ocompiler parser.tab.o lex.yy.c main.cc SymbolTable.cc SemanticFunctions.cc -std=c++14
parser.tab.o: parser.tab.cc
		g++ -ggdb -w -c parser.tab.cc -std=c++14
parser.tab.cc: parser.yy
		bison -v parser.yy
lex.yy.c: lexer.flex parser.tab.cc
		flex lexer.flex
tree: 
		 dot -Tpdf tree.dot -otree.pdf
clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.hh position.hh location.hh tree.dot tree.pdf
		rm -R compiler.dSYM
