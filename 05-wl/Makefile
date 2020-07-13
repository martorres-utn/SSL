
SOURCE1 = wl-1-enum-switch.c
BIN1 = wl-1.exe
OBJ1 = wl-1-enum-switch.o

SOURCE2 = wl-2-goto.c
BIN2 = wl-2.exe
OBJ2 = wl-2-goto.o

CC = gcc
CFLAGS = -std=c18 -g #agrego -g para decirle al compilador que emita informacion adicional para debugger GDB

all: $(BIN1) $(BIN2)

$(OBJ1): $(SOURCE1)
	$(CC) -c $(SOURCE1) $(CFLAGS)

$(BIN1): $(OBJ1)
	$(CC) $(OBJ1) -o $(BIN1) $(CFLAGS)

#run: $(BIN1)
#	$(BIN1)
	
$(OBJ2): $(SOURCE2)
	$(CC) -c $(SOURCE2) $(CFLAGS)

$(BIN2): $(OBJ2)
	$(CC) $(OBJ2) -o $(BIN2) $(CFLAGS)

#run: $(BIN2)
#	$(BIN2)