LIBS=-std=c++14 
CFLAGS=-g
LDFLAGS=$(LIBS) -I/usr/include/postgresqlCC=gcc
BIN=compiler
CC=g++

SDIR=src
ODIR=obj
IDIR=inc
BDIR=src/bison

_OBJ=main.o parser.tab.o hasher.o symbol_node.o utils.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(BIN): $(SDIR)/lex.yy.c $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

$(ODIR)/%.o: $(SDIR)/%.cc $(ODIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(ODIR):
	mkdir -p $(ODIR)

$(SDIR)/lex.yy.c: $(BDIR)/lexer.flex $(SDIR)/parser.tab.cc
	flex -o$(SDIR)/lex.yy.c $(BDIR)/lexer.flex

$(SDIR)/parser.tab.cc: $(BDIR)/parser.yy
	bison -H$(IDIR)/parser.tab.h -o$(SDIR)/parser.tab.cc $(BDIR)/parser.yy

clean:
	rm -r $(ODIR)
	rm $(BIN)
	rm $(SDIR)/lex.yy.c
	rm $(SDIR)/parser.tab.cc
	rm $(IDIR)/parser.tab.h
	rm tree.dot 
	rm tree.pdf

syntax: $(BIN) testScript.py
	python testScript.py -syntax

semantic: $(BIN) testScript.py
	python testScript.py -semantic
	
valid: $(BIN) testScript.py
	python testScript.py -valid

interpreter: $(BIN) testScript.py
	python testScript.py -interpreter

lexical: $(BIN) testScript.py
	python testScript.py -lexical

tree:
	dot -Tpdf tree.dot -otree.pdf
