ifeq ($(OS),Windows_NT)
	MKDIR=powershell -file .\utils\mkdir.ps1 -dirs
	RMRF=powershell -file .\utils\rm.ps1 -dirs
else
	MKDIR=mkdir -p
	RMRF=rm -rf
endif

CC=gcc -std=c17
CFLAGS=-g

JOGO_SRC=lib/jogo
JOGO_LIB=$(JOGO_SRC)/libjogo.a

INCLUDE_DIRS=-I. $(shell $(MAKE) --quiet -C $(JOGO_SRC) includes)
LINK_DIRS=
LINKS=$(shell $(MAKE) --quiet -C $(JOGO_SRC) links)
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
	$(MKDIR) "$@"

$(EXE): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(JOGO_LIB) -o $@ $(INCLUDE_DIRS) $(LINK_DIRS) $(LINKS) $(DEFINE)

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_DIRS) $(LINK_DIRS) $(LINKS) $(DEFINE)

full-clean: clean
	$(RMRF) $(JOGO_LIB)
	$(MAKE) -C $(JOGO_SRC) full-clean

clean:
	$(RMRF) $(OBJ_DIR) $(EXE)
