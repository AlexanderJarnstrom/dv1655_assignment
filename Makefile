
all:
	@$(MAKE) -C ./compiler_src/
	@$(MAKE) -C ./interpreter_src/
	cp ./compiler_src/compiler .
	cp ./interpreter_src/build/interpreter .

clean:
	rm compiler
	rm interpreter
	@$(MAKE) -C ./compiler_src/ clean
	@$(MAKE) -C ./interpreter_src/ clean


