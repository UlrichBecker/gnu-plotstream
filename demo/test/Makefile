###############################################################################
##                                                                           ##
##    Makefile of minimal test program for testing the class PlotStream      ##
##                                                                           ##
##---------------------------------------------------------------------------##
## File:    demo/test/Makefile                                               ##
## Author:  Ulrich Becker                                                    ##
## Company: GSI Helmholtz Centre for Heavy Ion Research GmbH                 ##
## Date:    07.05.2019                                                       ##
###############################################################################
BASEDIR = ../../src
SOURCES = gptest.cpp $(BASEDIR)/gnuplotstream.cpp
EXE_NAME = gptest

VPATH= $(BASEDIR)
INCDIR = $(BASEDIR)
CXXFLAGS = -g -O0 -std=c++11

CXX ?= g++
CXXFLAGS += $(addprefix -I,$(INCDIR))

OBJDIR=.obj
LIBS = stdc++

OBJ = $(addprefix $(OBJDIR)/,$(addsuffix .opp,$(notdir $(basename $(SOURCES)))))

.PHONY: all 
all: $(EXE_NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.opp: %.cpp $(SOURCES) $(OBJDIR)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(EXE_NAME): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(addfrefix "-l",$(LIBS))

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.opp $(EXE_NAME) core
	rmdir $(OBJDIR)

#=================================== EOF ======================================
