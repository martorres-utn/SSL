SOURCE1 = Scanner.c Parser.c Calc.c
BIN1 = Calc.out
OBJ1 = Scanner.o Parser.o Calc.o

SOURCE2 = Scanner2.c Parser2.c Calc2.c
BIN2 = Calc2.out
OBJ2 = Scanner2.o Parser2.o Calc2.o

CC = gcc
CFLAGS = -std=c18 -g #agrego -g para decirle al compilador que emita informacion adicional para debugger GDB

all: $(BIN1) $(BIN2)

$(OBJ1): $(SOURCE1)
	$(CC) -c $(SOURCE1) $(CFLAGS)

$(BIN1): $(OBJ1)
	$(CC) $(OBJ1) -o $(BIN1) $(CFLAGS)


#run: $(BIN1)
#	$(BIN1)

$(BIN2): $(OBJ2)
	$(CC) $(OBJ2) -o $(BIN2) $(CFLAGS)

$(OBJ2): $(SOURCE2)
	$(CC) -c $(SOURCE2) $(CFLAGS)