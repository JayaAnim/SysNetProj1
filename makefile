# Makefile for a C++ project

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++11

SRCDIR = src
INCDIR = include
OBJDIR = .
BINDIR = bin

all: $(BINDIR) $(OBJDIR) $(BINDIR)/myshell clean

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR)/myshell: $(OBJDIR)/myshell.o $(OBJDIR)/parse.o $(OBJDIR)/param.o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/myshell.o: $(SRCDIR)/myshell.cpp $(OBJDIR)/parse.o 
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/parse.o: $(SRCDIR)/parse.cpp $(INCDIR)/parse.h $(OBJDIR)/param.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/param.o: $(SRCDIR)/param.cpp $(INCDIR)/param.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -r $(OBJDIR)/*o 
