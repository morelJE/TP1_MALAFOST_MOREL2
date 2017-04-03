SRCDIR = src
BINDIR = bin
OBJDIR = obj
PROG = $(BINDIR)/main
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
CXX = g++
CXXFLAGS = -Wall -g

default:
	$(CXX) $(CXXFLAGS) -c -o obj/main.o src/main.cpp
	$(CXX) $(CXXFLAGS) -c -o obj/Dvector.o src/Dvector.cpp
	
	$(CXX) $(CXXFLAGS) -o $(PROG) $(OBJS)

clean:
	rm -f $(OBJS) $(PROG)
