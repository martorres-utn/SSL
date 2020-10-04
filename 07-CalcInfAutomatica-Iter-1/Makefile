SOURCE1 = Scanner.c Parser.c SemanticAnalyzer.c Calc.c
BIN1 = Calc.out
OBJ1 = Scanner.o Parser.o SemanticAnalyzer.o Calc.o

CC = gcc
CFLAGS = -std=c18 -g #agrego -g para decirle al compilador que emita informacion adicional para debugger GDB

all: $(BIN1)

$(OBJ1): $(SOURCE1)
	$(CC) -c $(SOURCE1) $(CFLAGS)

$(BIN1): $(OBJ1)
	$(CC) $(OBJ1) -o $(BIN1) $(CFLAGS)

run: $(BIN1)
	$(BIN1)