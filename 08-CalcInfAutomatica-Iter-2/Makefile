#SOURCE1 = Scanner.c lex.yy.c Parser.c SemanticAnalyzer.c Calc.c AutoParser.tab.c
SOURCE1 = Scanner.c lex.yy.c SemanticAnalyzer.c Calc.c AutoParser.tab.c
BIN1 = Calc.out
OBJ1 = Scanner.o lex.yy.o SemanticAnalyzer.o Calc.o AutoParser.tab.o

CC = gcc
CFLAGS = -std=c18 -g #agrego -g para decirle al compilador que emita informacion adicional para debugger GDB

all: $(BIN1)

AutoParser.tab.c: AutoParser.y
	bison -d AutoParser.y

lex.yy.c: ScannerLex.l
	flex ScannerLex.l

$(OBJ1): $(SOURCE1)
	$(CC) -c $(SOURCE1) $(CFLAGS)

$(BIN1): $(OBJ1)
	$(CC) $(OBJ1) -o $(BIN1) $(CFLAGS)

run: $(BIN1)
	$(BIN1)