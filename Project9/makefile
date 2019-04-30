COMPILER = g++
COMPILER_FLAGS = -Wall -g -c -std=c++11
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

all:TestProject

TestProject: TestProject.o Window.o Character.o Timer.o
	$(COMPILER) TestProject.o Window.o Character.o Timer.o $(LINKER_FLAGS) -o TestProject

Character.o: Character.cpp Character.h
	$(COMPILER) $(COMPILER_FLAGS) Character.cpp $(LINKER_FLAGS) -o Character.o

TestProject.o: TestProject.cpp Window.h Character.h Timer.h
	$(COMPILER) $(COMPILER_FLAGS) TestProject.cpp $(LINKER_FLAGS) -o TestProject.o

Window.o: Window.cpp Window.h Character.h
	$(COMPILER) $(COMPILER_FLAGS) Window.cpp $(LINKER_FLAGS) -o Window.o

Timer.o: Timer.cpp Timer.h 
	$(COMPILER) $(COMPILER_FLAGS) Timer.cpp $(LINKER_FLAGS) -o Timer.o

clean:
	rm *.o TestProject