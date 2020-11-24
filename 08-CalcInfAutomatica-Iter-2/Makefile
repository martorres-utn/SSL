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
OBJECT_FLEX_SCANNER_AUTOPARSER = lex.yy.auto.Parser_Manual.o
OBJECT_FLEX_SCANNER_MANUALPARSER = lex.yy.manual.Parser_Manual.o

#Calc_1.out: Flex Scanner + Bison Parser
BIN1 = Calc_1.out
SOURCE1 = SemanticValue_Automatic.c Parser_Automatic.c Scanner_Automatic.c
OBJ1 = SemanticValue_Automatic.o Parser_Automatic.o Scanner_Automatic.o

#Calc_2.out: Manual Scanner + Manual Parser
BIN2 = Calc_2.out
SOURCE2 = SemanticValue_Manual.c Parser_Manual.c Scanner_Manual.c
OBJ2 = SemanticValue_Manual.o Parser_Manual.o Scanner_Manual.o

#Calc_3.out: Flex Scanner + Manual Parser
BIN3 = Calc_3.out
SOURCE3 =  SemanticValue_Manual.c Scanner_Automatic.c Parser_Manual.c
OBJ3 = SemanticValue_Manual.o Scanner_Automatic.o Parser_Manual.o

#Calc_4.out: Manual Scanner + Bison Parser
BIN4 = Calc_4.out
SOURCE4 = SemanticValue_Automatic.c Scanner_Manual.c Parser_Automatic.c
OBJ4 = SemanticValue_Automatic.o Scanner_Manual.o Parser_Automatic.o

all: $(BIN1) $(BIN2) $(BIN3) $(BIN4)

#Bison Parser
$(BLUEPRINT_BISON).tab.c: $(BLUEPRINT_BISON).y
	bison -d $(BLUEPRINT_BISON).y

#Flex Scanner
$(SOURCE_FLEX_SCANNER): $(BLUEPRINT_FLEX).l
	flex $(BLUEPRINT_FLEX).l

#BST + VariableManager
$(OBJ0): $(SOURCE0)
	$(CC) -c $(SOURCE0) $(CFLAGS)

#Automatic Parser
$(OBJECT_BISON_PARSER): $(SOURCE_BISON_PARSER)
	$(CC) -c $(SOURCE_BISON_PARSER) $(CFLAGS)

#Flex Scanner with Automatic Parser
$(OBJECT_FLEX_SCANNER_AUTOPARSER): $(SOURCE_FLEX_SCANNER)
	$(CC) -o $(OBJECT_FLEX_SCANNER_AUTOPARSER) -c $(SOURCE_FLEX_SCANNER) $(CFLAGS) -DAUTOMATIC_PARSER

#Flex Scanner with Manual Parser
$(OBJECT_FLEX_SCANNER_MANUALPARSER): $(SOURCE_FLEX_SCANNER)
	$(CC) -o $(OBJECT_FLEX_SCANNER_MANUALPARSER) -c $(SOURCE_FLEX_SCANNER) $(CFLAGS)

#Flex + Bison
$(OBJ1): $(SOURCE1)
	$(CC) -c $(SOURCE1) $(CFLAGS)

$(BIN1): $(OBJ0) $(OBJECT_BISON_PARSER) $(OBJECT_FLEX_SCANNER_AUTOPARSER) $(OBJ1)
	$(CC) $(OBJ0) $(OBJECT_BISON_PARSER) $(OBJECT_FLEX_SCANNER_AUTOPARSER) $(OBJ1) -o $(BIN1) $(CFLAGS)

#Manual Only
$(OBJ2): $(SOURCE2)
	$(CC) -c $(SOURCE2) $(CFLAGS)

$(BIN2): $(OBJ0) $(OBJ2)
	$(CC) $(OBJ0) $(OBJ2) -o $(BIN2) $(CFLAGS)

#Lex Scanner + Manual Parser
$(BIN3): $(OBJ0) $(OBJ3) $(OBJECT_FLEX_SCANNER_MANUALPARSER)
	$(CC) $(OBJ0) $(OBJECT_FLEX_SCANNER_MANUALPARSER) $(OBJ3) -o $(BIN3) $(CFLAGS)

#Manual Scanner + Automatic Parser
$(BIN4): $(OBJ0) $(OBJ4) $(OBJECT_BISON_PARSER)
	$(CC) $(OBJ0) $(OBJ4) $(OBJECT_BISON_PARSER) -o $(BIN4) $(CFLAGS)

#removes *.o files
clean:
	-rm $(OBJ0)
	-rm $(OBJ1)
	-rm $(OBJ2)
	-rm $(OBJ3)
	-rm $(OBJ4)
	-rm $(OBJECT_BISON_PARSER)
	-rm $(OBJECT_FLEX_SCANNER_AUTOPARSER)
	-rm $(OBJECT_FLEX_SCANNER_MANUALPARSER)

run: $(BIN1)
	$(BIN1)