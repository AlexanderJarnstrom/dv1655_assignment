LIBS=-std=c++14 
CC=g++

TARGET=interpretor
BUILD_DIR = build
SRC_DIR = src
INC_DIR = inc

SRCS = $(wildcard $(SRC_DIR)/*.cc)
OBJS = $(patsubst %.cc, $(BUILD_DIR)/%.o, $(notdir $(SRCS)))
DEPS = $(wildcard $(INC_DIR)/*.h)

CFLAGS =-g -std=c++14 -I$(INC_DIR)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc $(DEPS)
	@mkdir -p $(BUILD_DIR)
	$(CC) -c -o $@ $< $(CFLAGS) 

.PHONY: clean cleanall

clean:
	rm -rf $(BUILD_DIR)
