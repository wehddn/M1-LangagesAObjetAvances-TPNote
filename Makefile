CC= g++ -Wall -std=c++11 # compilateur + options
CCO= $(CC) -c $<
OBJECTS= src/Sommet.o src/Arete.o src/Graphe.o src/GarbageCollector.o src/Main.o # liste des objets intermédiaires
all : $(OBJECTS)
	$(CC) -o go $(OBJECTS)
	./go
Sommet.o : src/Sommet.cpp src/Sommet.hpp
	$(CCO)
Arete.o : src/Arete.cpp src/Arete.hpp
	$(CCO)
Graphe.o : src/Graphe.cpp src/Graphe.hpp
	$(CCO)
GarbageCollector.o : src/GarbageCollector.cpp src/GarbageCollector.hpp
	$(CCO)
Main.o : src/Main.cpp src/GarbageCollector.hpp src/Graphe.hpp src/Arete.hpp src/Sommet.hpp
	$(CCO)
clean :
	rm -f src/*.o go