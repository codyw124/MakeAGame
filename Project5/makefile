COMPILER=g++
COMPILER_FLAGS = -Wall
LINKER_FLAGS = -lGL -lGLU -lglut -lILU -lIL

test: LUtil.o LTexture.o main.cpp
	$(COMPILER) LUtil.o LTexture.o main.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -o test

LUtil.o: LUtil.h LUtil.cpp
	$(COMPILER) -c LUtil.cpp -o LUtil.o

LTexture.o: LTexture.h LTexture.cpp
	$(COMPILER) -c LTexture.cpp -o LTexture.o

clean: 
	rm *.o test
