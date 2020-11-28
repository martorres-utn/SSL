CC = gcc
CFLAGS = -std=c18 -g #agrego -g para decirle al compilador que emita informacion adicional para debugger GDB
OBJDIR=obj

#Common source and object files
SOURCE0 = BST.c VariableManager.c Calc.c
OBJ0 = $(addprefix $(OBJDIR)/, BST.o VariableManager.o Calc.o )

BLUEPRINT_BISON = Parser_Bison
BLUEPRINT_FLEX = Scanner_Flex

SOURCE_BISON_PARSER = $(BLUEPRINT_BISON).tab.c
OBJECT_BISON_PARSER = $(addprefix $(OBJDIR)/, $(BLUEPRINT_BISON).tab.o )

SOURCE_FLEX_SCANNER = lex.yy.c
OBJECT_FLEX_SCANNER = $(addprefix $(OBJDIR)/, lex.yy.o )

#Calc_1.out: Flex Scanner + Bison Parser
BIN1 = Calc_1.out
SOURCE1 = SemanticValue_Automatic.c Parser_Automatic.c Scanner_Automatic.c
OBJ1 = $(addprefix $(OBJDIR)/, SemanticValue_Automatic.o Parser_Automatic.o Scanner_Automatic.o )

#Calc_2.out: Manual Scanner + Manual Parser
BIN2 = Calc_2.out
SOURCE2 = SemanticValue_Manual.c Parser_Manual.c Scanner_Manual.c
OBJ2 = $(addprefix $(OBJDIR)/, SemanticValue_Manual.o Parser_Manual.o Scanner_Manual.o )

#Calc_3.out: Flex Scanner + Manual Parser
BIN3 = Calc_3.out
SOURCE3 =  SemanticValue_Manual.c Scanner_Automatic.c Parser_Manual.c
OBJ3 = $(addprefix $(OBJDIR)/, SemanticValue_Manual.o Scanner_Automatic.o Parser_Manual.o )

#Calc_4.out: Manual Scanner + Bison Parser
BIN4 = Calc_4.out
SOURCE4 = SemanticValue_Automatic.c Scanner_Manual.c Parser_Automatic.c
OBJ4 = $(addprefix $(OBJDIR)/, SemanticValue_Automatic.o Scanner_Manual.o Parser_Automatic.o)

all: make_directories $(BIN1) $(BIN2) $(BIN3) $(BIN4)

.PHONY: make_directories
make_directories: $(OBJDIR)/

$(OBJDIR)/:
	mkdir -p $(OBJDIR)

#Bison Parser
$(SOURCE_BISON_PARSER): $(BLUEPRINT_BISON).y
	bison -d $(BLUEPRINT_BISON).y

#Flex Scanner
$(SOURCE_FLEX_SCANNER): $(BLUEPRINT_FLEX).l
	flex $(BLUEPRINT_FLEX).l

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(BIN1): $(OBJ0) $(OBJECT_BISON_PARSER) $(OBJECT_FLEX_SCANNER) $(OBJ1)
	$(CC) $(OBJ0) $(OBJECT_BISON_PARSER) $(OBJECT_FLEX_SCANNER) $(OBJ1) -o $(BIN1) $(CFLAGS)

$(BIN2): $(OBJ0) $(OBJ2)
	$(CC) $(OBJ0) $(OBJ2) -o $(BIN2) $(CFLAGS)

#Lex Scanner + Manual Parser
$(BIN3): $(OBJ0) $(OBJ3) $(OBJECT_FLEX_SCANNER)
	$(CC) $(OBJ0) $(OBJECT_FLEX_SCANNER) $(OBJ3) -o $(BIN3) $(CFLAGS)

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
	-rm $(OBJECT_FLEX_SCANNER)