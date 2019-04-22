CC = g++ 

COMPILER_FLAGS = -Wall -c

LINKER_FLAGS = -lSDL2 -lSDL2_image 

test: test.o Texture.o
	$(CC) test.o Texture.o $(LINKER_FLAGS) -o test

test.o: test.cpp  Texture.o
	$(CC) $(COMPILER_FLAGS) test.cpp  $(LINKER_FLAGS) -o test.o

Texture.o: Texture.h Texture.cpp
	$(CC) $(COMPILER_FLAGS) Texture.cpp  $(LINKER_FLAGS) -o Texture.o 

clean:
	rm test *.o
