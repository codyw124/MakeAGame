COMPILER = g++
COMPILER_FLAGS = -Wall -g -c -std=c++11
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

all: objects \
objects/Vector2.o \
objects/Vector3.o \
objects/Vector2Tests.o \
objects/Vector3Tests.o \
objects/MatricesTests.o \
objects/Transform.o \
objects/Level1.o \
objects/Scene.o \
objects/GameObject.o \
objects/SceneEditor.o \
objects/Window.o \
objects/tinyxml2.o \
objects/SaveGameObject.o \
objects/TestAll.o \
TestAll \
Level1 \
SceneEditor \
SaveGameObject 

#make the objects directory so we can build everything else
objects:
	mkdir objects

#testing gamephysics test program
TestAll: objects/PhysicsHelper.o \
objects/Vector2Tests.o \
objects/Vector2.o \
objects/Vector3Tests.o \
objects/Vector3.o \
objects/MatricesTests.o \
objects/TestAll.o
	$(COMPILER) objects/PhysicsHelper.o \
objects/Vector2Tests.o \
objects/Vector2.o \
objects/Vector3Tests.o \
objects/Vector3.o \
objects/MatricesTests.o \
objects/TestAll.o $(LINKER_FLAGS) -o TestAll



#mycode
Level1: objects/Window.o objects/Level1.o objects/Scene.o objects/GameObject.o
	$(COMPILER) objects/Window.o objects/Level1.o objects/Scene.o objects/GameObject.o $(LINKER_FLAGS) -o Level1

SceneEditor: objects/SceneEditor.o objects/Scene.o objects/GameObject.o
	$(COMPILER) objects/SceneEditor.o objects/Scene.o objects/GameObject.o $(LINKER_FLAGS) -o SceneEditor

SaveGameObject: objects/SaveGameObject.o objects/GameObject.o
	$(COMPILER) objects/SaveGameObject.o objects/GameObject.o $(LINKER_FLAGS) -o SaveGameObject


#objects
objects/PhysicsHelper.o: source/PhysicsHelper.cpp headers/PhysicsHelper.h
	$(COMPILER) $(COMPILER_FLAGS) source/PhysicsHelper.cpp -o objects/PhysicsHelper.o

objects/Vector2.o: source/Vector2.cpp headers/Vector2.h headers/PhysicsHelper.h
	$(COMPILER) $(COMPILER_FLAGS) source/Vector2.cpp -o objects/Vector2.o

objects/Vector3.o: source/Vector3.cpp headers/Vector3.h headers/PhysicsHelper.h
	$(COMPILER) $(COMPILER_FLAGS) source/Vector3.cpp -o objects/Vector3.o

objects/Transform.o: source/Transform.cpp headers/Transform.h
	$(COMPILER) $(COMPILER_FLAGS) source/Transform.cpp -o objects/Transform.o



#test objects
objects/Vector2Tests.o: source/Vector2Tests.cpp headers/Vector2Tests.h headers/Vector2.h
	$(COMPILER) $(COMPILER_FLAGS) source/Vector2Tests.cpp -o objects/Vector2Tests.o

objects/Vector3Tests.o: source/Vector3Tests.cpp headers/Vector3Tests.h headers/Vector3.h
	$(COMPILER) $(COMPILER_FLAGS) source/Vector3Tests.cpp -o objects/Vector3Tests.o

objects/MatricesTests.o: source/MatricesTests.cpp headers/MatricesTests.h headers/Matrix.h
	$(COMPILER) $(COMPILER_FLAGS) source/MatricesTests.cpp -o objects/MatricesTests.o

objects/TestAll.o: source/TestAll.cpp headers/MatricesTests.h headers/Vector2Tests.h headers/Vector3Tests.h
	$(COMPILER) $(COMPILER_FLAGS) source/TestAll.cpp -o objects/TestAll.o



#my objects
objects/Level1.o: source/Level1.cpp headers/Window.h
	$(COMPILER) $(COMPILER_FLAGS) source/Level1.cpp -o objects/Level1.o

objects/Scene.o: headers/Scene.h source/Scene.cpp headers/GameObject.h headers/tinyxml2.h
	$(COMPILER) $(COMPILER_FLAGS) source/Scene.cpp -o objects/Scene.o
	
objects/GameObject.o: headers/GameObject.h source/GameObject.cpp
	$(COMPILER) $(COMPILER_FLAGS) source/GameObject.cpp -o objects/GameObject.o

objects/SceneEditor.o: headers/SceneEditor.h source/SceneEditor.cpp headers/Scene.h headers/GameObject.h  headers/Component.h
	$(COMPILER) $(COMPILER_FLAGS) source/SceneEditor.cpp -o objects/SceneEditor.o

objects/Window.o: headers/Window.h source/Window.cpp headers/Scene.h
	$(COMPILER) $(COMPILER_FLAGS) source/Window.cpp -o objects/Window.o

objects/SaveGameObject.o: source/SaveGameObject.cpp headers/GameObject.h
	$(COMPILER) $(COMPILER_FLAGS) source/SaveGameObject.cpp -o objects/SaveGameObject.o


#tiny xml object
objects/tinyxml2.o: headers/tinyxml2.h source/tinyxml2.cpp
	$(COMPILER) $(COMPILER_FLAGS) source/tinyxml2.cpp -o objects/tinyxml2.o



clean:
	rm TestAll SceneEditor Level1 SaveGameObject; rm -r .vscode objects;