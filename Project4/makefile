COMPILER=g++
COMPILER_FLAGS = -w 
LINKER_FLAGS = -lGL -lGLU -lglut

test: LUtil.o vectors.o matrices.o Geometry2D.o main.cpp
	$(COMPILER) LUtil.o vectors.o matrices.o Geometry2D.o main.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -o test

LUtil.o: LUtil.h LUtil.cpp
	$(COMPILER) -c LUtil.cpp -o LUtil.o

vectors.o: vectors.h vectors.cpp
	$(COMPILER) -c vectors.cpp -o vectors.o

matrices.o: matrices.h matrices.cpp
	$(COMPILER) -c matrices.cpp -o matrices.o

Geometry2D.o: Geometry2D.h Geometry2D.cpp
	$(COMPILER) -c Geometry2D.cpp -o Geometry2D.o

clean: 
	rm *.o test
