CSRC=compiler_src
ISRC=interpreter_src

CBIN=compiler
IBIN=interpreter

all:
	@$(MAKE) -C ./compiler_src/
	@$(MAKE) -C ./interpreter_src/
	ln -s ./compiler_src/compiler .
	ln -s ./interpreter_src/build/interpreter .

clean:
	rm -f compiler
	rm -f interpreter
	rm -f tree.dot 
	rm -f tree.pdf
	rm -f blocks.dot 
	rm -f blocks.pdf
	@$(MAKE) -C ./compiler_src/ clean
	@$(MAKE) -C ./interpreter_src/ clean

test: $(CBIN) $(IBIN) testScript.py
	python testScript.py -lexical -syntax -semantic -valid -interpreter

syntax: $(CBIN) testScript.py
	python testScript.py -syntax

semantic: $(CBIN) testScript.py
	python testScript.py -semantic
	
valid: $(CBIN) testScript.py
	python testScript.py -valid

interpreter: $(IBIN) testScript.py
	python testScript.py -interpreter

lexical: $(CBIN) testScript.py
	python testScript.py -lexical

tree:
	dot -Tpdf tree.dot -otree.pdf

blocks:
	dot -Tpdf blocks.dot -oblocks.pdf

