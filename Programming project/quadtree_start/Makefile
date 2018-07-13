# code details

EXE_DIR = .
EXE = $(EXE_DIR)/test

SRC= test.c buildTree.c writeTree.c destroyTree.c growTree.c valueTree.c dependentTree.c

# generic build details

CC=      cc
COPT=    -g
CFLAGS=  -lm

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
test.o: test.c treeStructure.h buildTree.h writeTree.h
buildTree.o: buildTree.c treeStructure.h buildTree.h
writeTree.o: writeTree.c treeStructure.h writeTree.h
destroyTree.o: destroyTree.c treeStructure.h
growTree.o: growTree.c treeStructure.h
valueTree.o: valueTree.c treeStructure.h
dependentTree.o: dependentTree.c treeStructure.h
