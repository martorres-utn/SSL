PARSER_NAME = AutoParser
SCANNER_NAME = AutoScanner

SOURCE1 = $(PARSER_NAME).tab.c ParserBison.c lex.yy.c Scanner.c BST.c VariableManager.c Calc.c
BIN1 = Calc.out
OBJ1 = $(PARSER_NAME).tab.o ParserBison.o lex.yy.o Scanner.o BST.o VariableManager.o Calc.o

CC = gcc
CFLAGS = -std=c18 -g #agrego -g para decirle al compilador que emita informacion adicional para debugger GDB

all: $(BIN1)

$(PARSER_NAME).tab.c: $(PARSER_NAME).y
	bison -d $(PARSER_NAME).y

lex.yy.c: $(SCANNER_NAME).l
	flex $(SCANNER_NAME).l

$(OBJ1): $(SOURCE1)
	$(CC) -c $(SOURCE1) $(CFLAGS)

$(BIN1): $(OBJ1)
	$(CC) $(OBJ1) -o $(BIN1) $(CFLAGS)

run: $(BIN1)
	$(BIN1)