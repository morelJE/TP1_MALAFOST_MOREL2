SRCDIR = src
BINDIR = bin
OBJDIR = obj
PROG = $(BINDIR)/main
PROG2 = $(BINDIR)/gentest
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
CXX = g++
CXXFLAGS = -Wall -g

default:
	mkdir -p bin
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c -o obj/gentest.o src/gentest.cpp
	$(CXX) $(CXXFLAGS) -c -o obj/Dvector.o src/Dvector.cpp
	$(CXX) $(CXXFLAGS) -c -o obj/GenerateurNombreAleatoire.o src/GenerateurNombreAleatoire.cpp
	$(CXX) $(CXXFLAGS) -c -o obj/ParkMiller.o src/ParkMiller.cpp
	$(CXX) $(CXXFLAGS) -c -o obj/GenerateurParkMiller.o src/GenerateurParkMiller.cpp

	g++ -Wall -g -o bin/main obj/Dvector.o obj/main.o
	g++ -Wall -g -o bin/gentest obj/GenerateurNombreAleatoire.o obj/GenerateurParkMiller.o obj/ParkMiller.o obj/gentest.o obj/Dvector.o

.PHONY : doc

doc:
	doxygen doc/Doxyfile.in
	firefox doc/html/index.html &

clean:
	rm -rf $(OBJS) $(PROG) $(PROG2) doc/html doc/latex
