# code details

EXE_DIR = .

#use this for test file
# EXE = $(EXE_DIR)/test

# use this for user interface
EXE = $(EXE_DIR)/main

# use this for test file
# SRC= randomResponse.c keywordFinding.c saveInput.c test.c

# use this for user interface
SRC= randomResponse.c keywordFinding.c saveInput.c main.c

# generic build details

CC=      gcc
COPT=    -c

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT)  -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies
randomResponse.o: randomResponse.c randomResponse.h
keywordFinding.o: keywordFinding.c keywordFinding.h
saveInput.o: saveInput.c saveInput.h

#use this for test file
# test.o: test.c randomResponse.c keywordFinding.c saveInput.c

# use this for user interface
main.o: main.c randomResponse.c keywordFinding.c saveInput.c


