#Flex Scanner + Bison Parser
PARSER_NAME = AutoParser
SCANNER_NAME = AutoScanner

SOURCE0 = BST.c VariableManager.c Calc.c
OBJ0 = BST.o VariableManager.o Calc.o

SOURCE1 = $(PARSER_NAME).tab.c ParserBison.c lex.yy.c ScannerLex.c
BIN1 = Calc_1.out
OBJ1 = $(PARSER_NAME).tab.o ParserBison.o lex.yy.o ScannerLex.o

#Manual Scanner + Manual Parser
SOURCE2 = Parser.c Scanner.c
BIN2 = Calc_2.out
OBJ2 = Parser.o Scanner.o

CC = gcc
CFLAGS = -std=c18 -g #agrego -g para decirle al compilador que emita informacion adicional para debugger GDB

all: $(BIN1) $(BIN2)

$(PARSER_NAME).tab.c: $(PARSER_NAME).y
	bison -d $(PARSER_NAME).y

lex.yy.c: $(SCANNER_NAME).l
	flex $(SCANNER_NAME).l

#BST + VariableManager
$(OBJ0): $(SOURCE0)
	$(CC) -c $(SOURCE0) $(CFLAGS)

#Flex + Bison
$(OBJ1): $(SOURCE1)
	$(CC) -c $(SOURCE1) $(CFLAGS)

$(BIN1): $(OBJ0) $(OBJ1)
	$(CC) $(OBJ0) $(OBJ1) -o $(BIN1) $(CFLAGS)

#Manual Only
$(OBJ2): $(SOURCE2)
	$(CC) -c $(SOURCE2) $(CFLAGS)

$(BIN2): $(OBJ0) $(OBJ2)
	$(CC) $(OBJ0) $(OBJ2) -o $(BIN2) $(CFLAGS)

#removes *.o files
clean:
	-rm $(OBJ0)
	-rm $(OBJ1)
	-rm $(OBJ2)

run: $(BIN1)
	$(BIN1)