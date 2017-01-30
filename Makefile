PROG = main
OBJS = Dvector.o main.o
CXX = g++
CXXFLAGS = -Wall -g
$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)


clean:
	rm -f $(OBJS) main
