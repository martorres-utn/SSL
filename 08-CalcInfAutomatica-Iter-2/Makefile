CC = gcc
CFLAGS = -std=c18 -g #agrego -g para decirle al compilador que emita informacion adicional para debugger GDB

#Common source and object files
SOURCE0 = BST.c VariableManager.c Calc.c
OBJ0 = BST.o VariableManager.o Calc.o

BLUEPRINT_BISON = AutoParser
BLUEPRINT_FLEX = AutoScanner

SOURCE_BISON_PARSER = $(BLUEPRINT_BISON).tab.c
OBJECT_BISON_PARSER = $(BLUEPRINT_BISON).tab.o

SOURCE_FLEX_SCANNER = lex.yy.c
OBJECT_FLEX_SCANNER = lex.yy.o

#Calc_1.out: Flex Scanner + Bison Parser
BIN1 = Calc_1.out
SOURCE1 = SemanticValueAuto.c ParserBison.c ScannerLex.c
OBJ1 = SemanticValueAuto.o ParserBison.o ScannerLex.o

#Calc_2.out: Manual Scanner + Manual Parser
BIN2 = Calc_2.out
SOURCE2 = SemanticValueManual.c Parser.c Scanner.c
OBJ2 = SemanticValueManual.o Parser.o Scanner.o

#Calc_3.out: Flex Scanner + Manual Parser
BIN3 = Calc_3.out
SOURCE3 =  SemanticValueManual.c ScannerLex.c Parser.c
OBJ3 = SemanticValueManual.o ScannerLex.o Parser.o

all: $(BIN1) $(BIN2) $(BIN3)

#Bison Parser
$(BLUEPRINT_BISON).tab.c: $(BLUEPRINT_BISON).y
	bison -d $(BLUEPRINT_BISON).y

#Flex Scanner
lex.yy.c: $(BLUEPRINT_FLEX).l
	flex $(BLUEPRINT_FLEX).l

#BST + VariableManager
$(OBJ0): $(SOURCE0)
	$(CC) -c $(SOURCE0) $(CFLAGS)

#Automatic Parser
$(OBJECT_BISON_PARSER): $(SOURCE_BISON_PARSER)
	$(CC) -c $(SOURCE_BISON_PARSER) $(CFLAGS)

#Flex Scanner with Automatic Parser
$(OBJECT_FLEX_SCANNER): $(SOURCE_FLEX_SCANNER)
	$(CC) -c $(SOURCE_FLEX_SCANNER) $(CFLAGS) -DAUTOMATIC_PARSER

#Flex + Bison
$(OBJ1): $(SOURCE1)
	$(CC) -c $(SOURCE1) $(CFLAGS)

$(BIN1): $(OBJ0) $(OBJECT_BISON_PARSER) $(OBJECT_FLEX_SCANNER) $(OBJ1)
	$(CC) $(OBJ0) $(OBJECT_BISON_PARSER) $(OBJECT_FLEX_SCANNER) $(OBJ1) -o $(BIN1) $(CFLAGS)

#Manual Only
$(OBJ2): $(SOURCE2)
	$(CC) -c $(SOURCE2) $(CFLAGS)

$(BIN2): $(OBJ0) $(OBJ2)
	$(CC) $(OBJ0) $(OBJ2) -o $(BIN2) $(CFLAGS)

#Lex Scanner + Manual Parser

#remove old flex scanner object file and compile it again with different flag
$(BIN3): $(OBJ0) $(OBJ3)
	-rm $(OBJECT_FLEX_SCANNER)
	$(CC) -c $(SOURCE_FLEX_SCANNER) $(CFLAGS)
	$(CC) $(OBJ0) $(OBJECT_FLEX_SCANNER) $(OBJECT_BISON_PARSER) $(OBJ3) -o $(BIN3) $(CFLAGS)

#removes *.o files
clean:
	-rm $(OBJ0)
	-rm $(OBJECT_BISON_PARSER)
	-rm $(OBJECT_FLEX_SCANNER)
	-rm $(OBJ1)
	-rm $(OBJ2)
	-rm $(OBJ3)

run: $(BIN1)
	$(BIN1)