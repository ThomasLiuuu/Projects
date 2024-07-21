CXX=g++
CXXFLAGS=-std=c++20 -Wall -O -g -MMD -Werror=vla -g
SOURCES=$(wildcard *.cc)
OBJECTS=${SOURCES:.cc=.o}
DEPENDS=${OBJECTS:.o=.d}  
EXEC=watopoly

# First target in the makefile is the default target.
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC) -lX11;

%.o: %.cc
	$(CXX) -c -o $@ $< $(CXXFLAGS) 

-include ${DEPENDS}

.PHONY: clean
clean:
	rm  -f $(OBJECTS) $(DEPENDS) $(EXEC)
	