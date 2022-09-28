CC=gcc -std=c17
CFLAGS=-g

JOGO_SRC=lib/jogo
JOGO_LIB=$(JOGO_SRC)/libjogo.a

GLFW_SRC=$(JOGO_SRC)/lib/glfw
GLFW_BUILD_DIR=$(GLFW_SRC)/build
GLFW_LIB=$(GLFW_BUILD_DIR)/src/libglfw3.a

INCLUDE_DIRS=-I. -I$(JOGO_SRC)/include -I$(GLFW_SRC)/include
LINK_DIRS=
LINKS=-lGL -lGLEW -lm -ldl -pthread
DEFINE=

SRC_DIR=src
SRC=$(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/**/*.c)
OBJ_DIR=obj
OBJ=$(foreach src,$(SRC),$(OBJ_DIR)/$(notdir $(basename $(src))).o)
EXE=jogo

VPATH=$(wildcard $(SRC_DIR)/*) $(dir JOGO_SRC)
all: $(JOGO_LIB) $(EXE)

$(JOGO_LIB):
	$(MAKE) -C $(JOGO_SRC)

$(OBJ_DIR):
	mkdir -p $@

$(EXE): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(JOGO_LIB) $(GLFW_LIB) -o $@ $(INCLUDE_DIRS) $(LINK_DIRS) $(LINKS) $(DEFINE)

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_DIRS) $(LINK_DIRS) $(LINKS) $(DEFINE)

full-clean: clean
	rm -rf $(JOGO_LIB)
	$(MAKE) -C $(JOGO_SRC) full-clean

clean:
	rm -rf $(OBJ_DIR) $(EXE)
