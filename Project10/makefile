COMPILER = g++
COMPILER_FLAGS = -Wall -g -c -std=c++11
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

all: objects/Matrix.o\
objects/Vector2.o \
objects/Vector3.o \
objects/Vector2Tests.o \
objects/Level1.o \
objects/Scene.o \
objects/GameObject.o \
objects/SceneEditor.o \
objects/Window.o \
objects/tinyxml2.o \
objects/SaveGameObject.o \
objects/Vector3Tests.o \
objects/Geometry2DTests.o \
Vector2Tests \
Vector3Tests \
Geometry2DTests \
Level1 SceneEditor \
SaveGameObject 



#testing gamephysics test programs
Vector2Tests: objects/Vector2Tests.o objects/Vector2.o objects/PhysicsVector.o
	$(COMPILER) objects/Vector2Tests.o objects/Vector2.o objects/PhysicsVector.o $(LINKER_FLAGS) -o Vector2Tests

Vector3Tests: objects/Vector3Tests.o objects/Vector3.o objects/PhysicsVector.o
	$(COMPILER) objects/Vector3Tests.o objects/Vector3.o objects/PhysicsVector.o $(LINKER_FLAGS) -o Vector3Tests

Geometry2DTests: objects/Geometry2DTests.o objects/Vector2.o objects/PhysicsVector.o
	$(COMPILER) objects/Geometry2DTests.o objects/Vector2.o objects/PhysicsVector.o $(LINKER_FLAGS) -o Geometry2DTests



#mycode
Level1: objects/Window.o objects/Level1.o objects/Scene.o objects/GameObject.o
	$(COMPILER) objects/Window.o objects/Level1.o objects/Scene.o objects/GameObject.o $(LINKER_FLAGS) -o Level1

SceneEditor: objects/SceneEditor.o objects/Scene.o objects/GameObject.o
	$(COMPILER) objects/SceneEditor.o objects/Scene.o objects/GameObject.o $(LINKER_FLAGS) -o SceneEditor

SaveGameObject: objects/SaveGameObject.o objects/GameObject.o
	$(COMPILER) objects/SaveGameObject.o objects/GameObject.o $(LINKER_FLAGS) -o SaveGameObject


#gamephysics objects and gamephysics test objects
objects/Matrix.o: source/Matrix.cpp headers/Matrix.h headers/IMatrix.h
	$(COMPILER) $(COMPILER_FLAGS) source/Matrix.cpp $(LINKER_FLAGS) -o objects/Matrix.o

objects/Vector2.o: source/Vector2.cpp headers/Vector2.h headers/IVector.h headers/PhysicsVector.h
	$(COMPILER) $(COMPILER_FLAGS) source/Vector2.cpp $(LINKER_FLAGS) -o objects/Vector2.o

objects/Vector3.o: source/Vector3.cpp headers/Vector3.h headers/IVector.h headers/PhysicsVector.h
	$(COMPILER) $(COMPILER_FLAGS) source/Vector3.cpp $(LINKER_FLAGS) -o objects/Vector3.o

objects/PhysicsVector.o: source/PhysicsVector.cpp headers/PhysicsVector.h
	$(COMPILER) $(COMPILER_FLAGS) source/PhysicsVector.cpp $(LINKER_FLAGS) -o objects/PhysicsVector.o

objects/Vector2Tests.o: source/Vector2Tests.cpp headers/Vector2.h
	$(COMPILER) $(COMPILER_FLAGS) source/Vector2Tests.cpp $(LINKER_FLAGS) -o objects/Vector2Tests.o

objects/Vector3Tests.o: source/Vector3Tests.cpp headers/Vector3.h
	$(COMPILER) $(COMPILER_FLAGS) source/Vector3Tests.cpp $(LINKER_FLAGS) -o objects/Vector3Tests.o

objects/Geometry2DTests.o: source/Geometry2DTests.cpp headers/Geometry2D.h
	$(COMPILER) $(COMPILER_FLAGS) source/Geometry2DTests.cpp $(LINKER_FLAGS) -o objects/Geometry2DTests.o



#my objects
objects/Level1.o: source/Level1.cpp headers/Window.h
	$(COMPILER) $(COMPILER_FLAGS) source/Level1.cpp $(LINKER_FLAGS) -o objects/Level1.o

objects/Scene.o: headers/Scene.h source/Scene.cpp headers/GameObject.h headers/tinyxml2.h
	$(COMPILER) $(COMPILER_FLAGS) source/Scene.cpp $(LINKER_FLAGS) -o objects/Scene.o
	
objects/GameObject.o: headers/GameObject.h source/GameObject.cpp
	$(COMPILER) $(COMPILER_FLAGS) source/GameObject.cpp $(LINKER_FLAGS) -o objects/GameObject.o

objects/SceneEditor.o: headers/SceneEditor.h source/SceneEditor.cpp headers/Scene.h headers/GameObject.h  headers/Component.h
	$(COMPILER) $(COMPILER_FLAGS) source/SceneEditor.cpp $(LINKER_FLAGS) -o objects/SceneEditor.o

objects/Window.o: headers/Window.h source/Window.cpp headers/Scene.h
	$(COMPILER) $(COMPILER_FLAGS) source/Window.cpp $(LINKER_FLAGS) -o objects/Window.o

objects/tinyxml2.o: headers/tinyxml2.h source/tinyxml2.cpp
	$(COMPILER) $(COMPILER_FLAGS) source/tinyxml2.cpp $(LINKER_FLAGS) -o objects/tinyxml2.o

objects/SaveGameObject.o: source/SaveGameObject.cpp headers/GameObject.h
	$(COMPILER) $(COMPILER_FLAGS) source/SaveGameObject.cpp $(LINKER_FLAGS) -o objects/SaveGameObject.o



clean:
	rm objects/*.o Vector2Tests Vector3Tests Geometry2DTests SceneEditor Level1 SaveGameObject