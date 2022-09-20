CC=gcc -std=c17
CFLAGS=-g

GLFW_SRC=lib/glfw

JOGO_SRC=lib/jogo
JOGO_OBJ=$(JOGO_SRC)/jogo.o

INCLUDE_DIRS=-I. -I$(JOGO_SRC)/include -I$(JOGO_SRC)/$(GLFW_SRC)/include
LINK_DIRS=
LINKS=-lGL -lm -ldl -pthread
DEFINE=

SRC_DIR=src
SRC=$(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/**/*.c)
OBJ_DIR=obj
OBJ=$(foreach src,$(SRC),$(OBJ_DIR)/$(notdir $(basename $(src))).o)
EXE=jogo

VPATH=$(wildcard $(SRC_DIR)/*) $(dir JOGO_SRC)
all: $(JOGO_OBJ) $(EXE)

$(JOGO_OBJ):
	$(MAKE) -C $(JOGO_SRC)

$(OBJ_DIR):
	mkdir -p $@

$(EXE): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(JOGO_OBJ) -o $@ $(INCLUDE_DIRS) $(LINK_DIRS) $(LINKS) $(DEFINE)

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_DIRS) $(LINK_DIRS) $(LINKS) $(DEFINE)

full-clean: clean
	rm -rf $(JOGO_OBJ)

clean:
	rm -rf $(OBJ_DIR) $(EXE)
