COMPILER = g++
COMPILER_FLAGS = -Wall -g -c -std=c++11
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

all: SceneEditor

SceneEditor: SceneEditor.o Scene.o
	$(COMPILER) SceneEditor.o Scene.o $(LINKER_FLAGS) -o SceneEditor

SceneEditor.o: SceneEditor.cpp Scene.h
	$(COMPILER) $(COMPILER_FLAGS) SceneEditor.cpp $(LINKER_FLAGS) -o SceneEditor.o

Scene.o: Scene.h Scene.cpp
	$(COMPILER) $(COMPILER_FLAGS) Scene.cpp $(LINKER_FLAGS) -o Scene.o

clean:
	rm *.o SceneEditor