
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/tree

SRC= tree.c 

# generic build details

CC=      cc
COPT=    -O
CFLAGS= 

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE) 

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

tree.o:  tree.c 

