#
# Makefile
#
# @author Clément Rivière <criviere@ecole.ensicaen.fr>
#
# ENSICAEN
# 6, boulevard Maréchal Juin
# F-14050 Caen cedex
#
# Compile the mazeGame program.

APP = BattleShip
TEST = Test_BattleShip

MAIN_FILE = main.c

CC = gcc
RM = rm
RMFLAGS = -rf
CFLAGS = -Wall -Wextra -ansi
LDFLAGS = -lm
LDFLAGS_TEST = -lcunit -L/lib/CUnit/lib

# All directories of files.
INCLUDE_DIR = ./include
SRC_DIR = ./src
LIB_DIR = ./lib
BIN_DIR = ./bin
DOC_DIR = ./doc
OBJ_DIR = ./src/obj
TEST_DIR = ./tests

TEST_SRC_DIR = $(TEST_DIR)/$(SRC_DIR)
TEST_OBJ_DIR = $(TEST_DIR)/$(OBJ_DIR)
TEST_BIN_DIR = $(TEST_DIR)/$(BIN_DIR)

LIB_SRC_DIR = $(LIB_DIR)/$(SRC_DIR)
LIB_OBJ_DIR = $(LIB_DIR)/$(OBJ_DIR)
LIB_BIN_DIR = $(LIB_DIR)/$(BIN_DIR)
LIB_INCLUDE_DIR = $(LIB_DIR)/$(INCLUDE_DIR)

DOXYFILE = doxyfile
HTML = YES
LATEX = NO
RTF = NO

SOURCES := $(wildcard $(SRC_DIR)/*.c)
SOURCES := $(filter-out $(SRC_DIR)/$(MAIN_FILE), $(SOURCES))
OBJECTS := $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MAIN_SOURCE = $(SRC_DIR)/$(MAIN_FILE)
MAIN_OBJECT := $(MAIN_SOURCE:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

TEST_SOURCES := $(wildcard $(TEST_SRC_DIR)/*.c)
TEST_OBJECTS := $(TEST_SOURCES:$(TEST_SRC_DIR)/%.c=$(TEST_OBJ_DIR)/%.o)

LIB_SOURCES := $(wildcard $(LIB_SRC_DIR)/*.c)
LIB_OBJECTS := $(LIB_SOURCES:$(LIB_SRC_DIR)/%.c=$(LIB_OBJ_DIR)/%.o)



.PHONY: all clean distclean docclean

all: createObjectTree $(APP)
test: createObjectTree createTestObjectTree createLibObjectTree $(TEST)


$(APP): $(OBJECTS) $(MAIN_OBJECT)
	$(CC) $^ -o $(BIN_DIR)/$@ $(LDFLAGS)

$(TEST): $(OBJECTS) $(TEST_OBJECTS) $(LIB_OBJECTS)
	$(CC) $^ -o $(BIN_DIR)/$@ $(LDFLAGS_TEST)

createObjectTree:
	mkdir -p $(OBJ_DIR)

createTestObjectTree:
	mkdir -p $(TEST_OBJ_DIR)

createLibObjectTree:
	mkdir -p $(LIB_OBJ_DIR)

#Dependencies

$(OBJECTS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/%.h
	$(CC) $(CFLAGS) -c -I $(INCLUDE_DIR) -o $@ $<

$(MAIN_OBJECT) : $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TEST_OBJECTS) : $(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB_OBJECTS) : $(LIB_OBJ_DIR)/%.o: $(LIB_SRC_DIR)/%.c $(LIB_INCLUDE_DIR)/%.h
	$(CC) $(CFLAGS) -c -I $(LIB_INCLUDE_DIR) -o $@ $<


clean:
	$(RM) $(RMFLAGS) $(OBJ_DIR)
	$(RM) $(RMFLAGS) $(TEST_OBJ_DIR)
	$(RM) $(RMFLAGS) $(LIB_OBJ_DIR)

distclean: clean
	$(RM) $(RMFLAGS) $(BIN_DIR)/$(APP)
	$(RM) $(RMFLAGS) $(DOC_DIR)/$(DOXYFILE)
	$(RM) $(RMFLAGS) $(BIN_DIR)/$(TEST)

docclean:
	$(RM) $(RMFLAGS) $(DOC_DIR)/*

doxysetup:
	-touch $(DOC_DIR)/$(DOXYFILE)
	-echo PROJECT_NAME = "$(APP)" > $(DOC_DIR)/$(DOXYFILE)
	-echo EXCLUDE = >> $(DOC_DIR)/$(DOXYFILE)
	-echo INPUT = $(INCLUDE_DIR) $(SRC_DIR) >> $(DOC_DIR)/$(DOXYFILE)
	-echo FILE_PATTERNS = *.h *.c >> $(DOC_DIR)/$(DOXYFILE)
	-echo GENERATE_LATEX = $(LATEX) >> $(DOC_DIR)/$(DOXYFILE)
	-echo GENERATE_HTML = $(HTML) >> $(DOC_DIR)/$(DOXYFILE)
	-echo GENERATE_RTF = $(RTF) >> $(DOC_DIR)/$(DOXYFILE)
	-echo OUTPUT_DIRECTORY = $(DOC_DIR) >> $(DOC_DIR)/$(DOXYFILE)

doc: doxysetup createObjectTree $(APP)
	-doxygen $(DOC_DIR)/$(DOXYFILE)
