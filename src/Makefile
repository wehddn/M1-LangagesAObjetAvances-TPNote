CC= g++ -Wall -std=c++11 # compilateur + options
CCO= $(CC) -c $<
OBJECTS= Sommet.o Arete.o Graphe.o GarbageCollector.o Main.o # liste des objets intermédiaires
TEST= Sommet.o Arete.o Graphe.o GarbageCollector.o Test.o
all : $(OBJECTS)
	$(CC) -o go $(OBJECTS)
	./go
test : $(TEST)
	$(CC) -o go $(TEST)
	./go
Sommet.o : Sommet.cpp Sommet.hpp
	$(CCO)
Arete.o : Arete.cpp Arete.hpp
	$(CCO)
Graphe.o : Graphe.cpp Graphe.hpp
	$(CCO)
GarbageCollector.o : GarbageCollector.cpp GarbageCollector.hpp
	$(CCO)
Main.o : Main.cpp GarbageCollector.hpp Graphe.hpp Arete.hpp Sommet.hpp
	$(CCO)
Test.o : Test.cpp GarbageCollector.hpp Graphe.hpp Arete.hpp Sommet.hpp
	$(CCO)
clean :
	rm -f *.o go