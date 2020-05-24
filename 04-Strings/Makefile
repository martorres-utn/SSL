SOURCE = String.c
BIN = String.out
OBJ = String.o
CC = gcc
CFLAGS = -std=c18 -g #agrego -g para decirle al compilador que emita informacion adicional para debugger GDB

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

run: $(BIN)
	$(BIN)
$(OBJ): $(SOURCE)
	$(CC) -c $(SOURCE) -o $(OBJ) $(CFLAGS)