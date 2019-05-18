COMPILER = g++
COMPILER_FLAGS = -Wall -g -c -std=c++11
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

all: Level1 SceneEditor objects/Level1.o objects/Scene.o objects/GameObject.o objects/Vector3.o objects/SceneEditor.o objects/Window.o objects/tinyxml2.o

Level1: objects/Window.o objects/Level1.o objects/Scene.o objects/GameObject.o
	$(COMPILER) objects/Window.o objects/Level1.o objects/Scene.o objects/GameObject.o $(LINKER_FLAGS) -o Level1

SceneEditor: objects/SceneEditor.o objects/Scene.o objects/GameObject.o
	$(COMPILER) objects/SceneEditor.o objects/Scene.o objects/GameObject.o $(LINKER_FLAGS) -o SceneEditor

objects/Level1.o: source/Level1.cpp headers/Window.h
	$(COMPILER) $(COMPILER_FLAGS) source/Level1.cpp $(LINKER_FLAGS) -o objects/Level1.o

objects/Scene.o: headers/Scene.h source/Scene.cpp headers/GameObject.h
	$(COMPILER) $(COMPILER_FLAGS) source/Scene.cpp $(LINKER_FLAGS) -o objects/Scene.o
	
objects/GameObject.o: headers/GameObject.h source/GameObject.cpp
	$(COMPILER) $(COMPILER_FLAGS) source/GameObject.cpp $(LINKER_FLAGS) -o objects/GameObject.o

objects/Vector3.o: headers/Vector3.h source/Vector3.cpp
	$(COMPILER) $(COMPILER_FLAGS) source/Vector3.cpp $(LINKER_FLAGS) -o objects/Vector3.o

objects/SceneEditor.o: headers/SceneEditor.h source/SceneEditor.cpp headers/Scene.h headers/GameObject.h  headers/Component.h
	$(COMPILER) $(COMPILER_FLAGS) source/SceneEditor.cpp $(LINKER_FLAGS) -o objects/SceneEditor.o

objects/Window.o: headers/Window.h source/Window.cpp headers/Scene.h
	$(COMPILER) $(COMPILER_FLAGS) source/Window.cpp $(LINKER_FLAGS) -o objects/Window.o

objects/tinyxml2.o: headers/tinyxml2.h source/tinyxml2.cpp
	$(COMPILER) $(COMPILER_FLAGS) source/tinyxml2.cpp $(LINKER_FLAGS) -o objects/tinyxml2.o

clean:
	rm objects/*.o ./SceneEditor ./Level1