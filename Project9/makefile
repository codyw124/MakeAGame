COMPILER = g++
COMPILER_FLAGS = -Wall -g -c
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

all:TestProject

TestProject: TestProject.o Window.o Character.o
	$(COMPILER) TestProject.o Window.o Character.o $(LINKER_FLAGS) -o TestProject

Character.o: Character.cpp Character.h
	$(COMPILER) $(COMPILER_FLAGS) Character.cpp $(LINKER_FLAGS) -o Character.o

TestProject.o: TestProject.cpp Window.h Character.h
	$(COMPILER) $(COMPILER_FLAGS) TestProject.cpp $(LINKER_FLAGS) -o TestProject.o

Window.o: Window.cpp Window.h Character.h
	$(COMPILER) $(COMPILER_FLAGS) Window.cpp $(LINKER_FLAGS) -o Window.o

clean:
	rm *.o TestProject