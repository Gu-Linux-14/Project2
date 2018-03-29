# Source, Executable, Includes, Library Defines
INCL   = ncurses.h stdio.h stdlib.h string.h 
SRC    = main.c fndRplc.c  openFile.c saveFile.c copy.c deleteLine.c editText.c insert.c 
OBJ    = $(SRC:.c=.o)
LIBS   = -lgen
EXE    = project2

# Compiler, Linker Defines
CC      = gcc
CFLAGS  = -lncurses -Wall
LIBPATH = -L.
LDFLAGS = -o $(EXE) $(LIBPATH) $(LIBS)
CFDEBUG = -ansi -pedantic -lncurses -Wall -g -DDEBUG $(LDFLAGS)
RM      = rm -f

# Compile and Assemble C Source Files into Object Files
%.o: %.c
	$(CC) -lncurse -Wall $(CFLAGS) $*.c

# Link all Object Files with external Libraries into Binaries
$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ)

# Objects depend on these Libraries
$(OBJ): $(INCL)

fndRplc.o: fndRplc.c fndRplc.h openFile.h 
saveFile.h
	$(CC) -lncurses -Wall fndRplc.c

editText.o: editText.c editText.c openFile.h saveFile.h 
	$(CC) -lncurses -Wall editText.c

deleteLine.o: deleteLine.c editText.c openFile.h saveFile.h 
	$(CC) -lncurses -Wall deleteLine.c
	
# Create a gdb/dbx Capable Executable with DEBUG flags turned on
debug:
	$(CC) $(CFDEBUG) $(SRC)

# Clean Up Objects, Exectuables, Dumps out of source directory
clean:
	$(RM) $(OBJ) $(EXE) core a.out
