SRCDIR = src
BINDIR = bin
OBJDIR = obj
PROG = $(BINDIR)/main
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
CXX = g++
CXXFLAGS = -Wall -g

default:
	mkdir -p bin
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c -o obj/main.o src/main.cpp
	$(CXX) $(CXXFLAGS) -c -o obj/Dvector.o src/Dvector.cpp

	g++ -Wall -g -o bin/main obj/Dvector.o obj/main.o

Gen:
	mkdir -p bin
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c -o obj/gentest.o src/gentest.cpp
	$(CXX) $(CXXFLAGS) -c -o obj/GenerateurNombreAleatoire.o src/GenerateurNombreAleatoire.cpp

	g++ -Wall -g -o bin/gentest obj/GenerateurNombreAleatoire.o obj/gentest.o

clean:
	rm -f $(OBJS) $(PROG)
