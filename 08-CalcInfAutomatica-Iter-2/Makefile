#Flex Scanner + Bison Parser
PARSER_NAME = AutoParser
SCANNER_NAME = AutoScanner

SOURCE1 = $(PARSER_NAME).tab.c ParserBison.c lex.yy.c ScannerLex.c BST.c VariableManager.c Calc.c
BIN1 = Calc_1.out
OBJ1 = $(PARSER_NAME).tab.o ParserBison.o lex.yy.o ScannerLex.o BST.o VariableManager.o Calc.o

#Manual Scanner + Manual Parser
SOURCE2 = SemanticAnalyzer.c Parser.c Scanner.c Calc_2.c
BIN2 = Calc_2.out
OBJ2 = SemanticAnalyzer.o Parser.o Scanner.o Calc_2.o

CC = gcc
CFLAGS = -std=c18 -g #agrego -g para decirle al compilador que emita informacion adicional para debugger GDB

all: $(BIN1) $(BIN2)

$(PARSER_NAME).tab.c: $(PARSER_NAME).y
	bison -d $(PARSER_NAME).y

lex.yy.c: $(SCANNER_NAME).l
	flex $(SCANNER_NAME).l

#Flex + Bison
$(OBJ1): $(SOURCE1)
	$(CC) -c $(SOURCE1) $(CFLAGS)

$(BIN1): $(OBJ1)
	$(CC) $(OBJ1) -o $(BIN1) $(CFLAGS)

#Manual Only
$(OBJ2): $(SOURCE2)
	$(CC) -c $(SOURCE2) $(CFLAGS)

$(BIN2): $(OBJ2)
	$(CC) $(OBJ2) -o $(BIN2) $(CFLAGS)

#removes *.o files
clean:
	-rm $(OBJ1)
	-rm $(OBJ2)

run: $(BIN1)
	$(BIN1)