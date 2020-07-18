
SOURCE1 = wl-1-enum-switch.c
BIN1 = wl-1-enum-switch.out
OBJ1 = wl-1-enum-switch.o

SOURCE2 = wl-2-goto.c
BIN2 = wl-2-goto.out
OBJ2 = wl-2-goto.o

SOURCE3 = wl-3-rec.c
BIN3 = wl-3-rec.out
OBJ3 = wl-3-rec.o


CC = gcc
CFLAGS = -std=c18 -g #agrego -g para decirle al compilador que emita informacion adicional para debugger GDB

all: $(BIN1) $(BIN2) $(BIN3)

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

$(OBJ3): $(SOURCE3)
	$(CC) -c $(SOURCE3) $(CFLAGS)

$(BIN3): $(OBJ3)
	$(CC) $(OBJ3) -o $(BIN3) $(CFLAGS)

#run: $(BIN3)
#	$(BIN3)