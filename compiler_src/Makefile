LIBS=-std=c++14 
CFLAGS=-g
LDFLAGS=$(LIBS) -I/usr/include/postgresqlCC=gcc
BFLAGS=--debug
BIN=compiler
CC=g++

SDIR=src
ODIR=obj
IDIR=inc
BDIR=src/bison

_OBJ=main.o parser.tab.o symbol_table.o scope.o symbol.o node.o semantic.o block.o ir_generation.o node_execute/generate_block.o node_execute/generate_tacs.o node_execute/get_type.o node_execute/in_execute.o node_execute/post_execute.o node_execute/pre_execute.o block_handler.o tac.o code_generation.o byte_code.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(BIN): $(SDIR)/lex.yy.c $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

$(ODIR)/%.o: $(SDIR)/%.cc $(ODIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(ODIR):
	mkdir -p $(ODIR)/node_execute

$(SDIR)/lex.yy.c: $(BDIR)/lexer.flex $(SDIR)/parser.tab.cc
	flex -o$(SDIR)/lex.yy.c $(BDIR)/lexer.flex

$(SDIR)/parser.tab.cc: $(BDIR)/parser.yy
	bison $(BFLAGS) -H$(IDIR)/parser.tab.h -o$(SDIR)/parser.tab.cc $(BDIR)/parser.yy
	sed -i -e 's/parser.tab.h/..\/inc\/parser.tab.h/g' $(SDIR)/parser.tab.cc

clean:
	rm -fr $(ODIR)
	rm -f $(BIN)
	rm -f $(SDIR)/lex.yy.c
	rm -f $(SDIR)/parser.tab.cc
	rm -f $(IDIR)/parser.tab.h
	rm -f tree.dot 
	rm -f tree.pdf
	rm -f blocks.dot 
	rm -f blocks.pdf

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

blocks:
	dot -Tpdf blocks.dot -oblocks.pdf
