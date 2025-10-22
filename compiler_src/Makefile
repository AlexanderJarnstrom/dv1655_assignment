LIBS=-std=c++14 
CFLAGS=-g
BFLAGS=--debug
CC=g++

TARGET = compiler
BUILD_DIR = build
SRC_DIR = src
INC_DIR = inc
BISON_DIR = $(SRC_DIR)/bison

SRCS = $(wildcard $(SRC_DIR)/node_execute/*.cc $(SRC_DIR)/*.cc)
OBJS = $(patsubst %.cc, $(BUILD_DIR)/%.o, $(notdir $(SRCS)))
DEPS = $(wildcard $(INC_DIR)/*.h)

$(BUILD_DIR)/$(TARGET): $(BUILD_DIR)/parser.tab.o $(BUILD_DIR)/lex.yy.o $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc $(DEPS)
	@mkdir -p $(BUILD_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/node_execute/%.cc $(DEPS)
	@mkdir -p $(BUILD_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/lex.yy.o: $(SRC_DIR)/lex.yy.c
	@mkdir -p $(BUILD_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/parser.tab.o: $(SRC_DIR)/parser.tab.cc
	@mkdir -p $(BUILD_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(SRC_DIR)/lex.yy.c: $(BISON_DIR)/lexer.flex $(SRC_DIR)/parser.tab.cc
	flex -o$(SRC_DIR)/lex.yy.c $(BISON_DIR)/lexer.flex

$(SRC_DIR)/parser.tab.cc: $(BISON_DIR)/parser.yy
	bison $(BFLAGS) -H$(INC_DIR)/parser.tab.h -o$(SRC_DIR)/parser.tab.cc $(BISON_DIR)/parser.yy
	sed -i -e 's/parser.tab.h/..\/inc\/parser.tab.h/g' $(SRC_DIR)/parser.tab.cc

clean:
	rm -fr $(BUILD_DIR)
	rm -f $(SRC_DIR)/lex.yy.c
	rm -f $(SRC_DIR)/parser.tab.cc
	rm -f $(INC_DIR)/parser.tab.h

