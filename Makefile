INCDIR = ./inc
SRCDIR = ./src
OBJDIR = ./obj
OUTDIR = ./bin
TESTDIR = ./tests

OBJTESTDIR = $(OBJDIR)/$(notdir $(TESTDIR))

SRCS = $(wildcard $(SRCDIR)/*.cpp $(SRCDIR)/**/*.cpp)
TESTS = $(wildcard $(TESTDIR)/*.cpp $(TESTDIR)/**/*.cpp)

CXX = g++
CXXFLAGS = -I$(INCDIR) -Wall -Wextra -Wpedantic -Weffc++ \
			-Wmissing-declarations \
			-Wundef -Wlogical-op \
			-std=c++14 -g

LDFLAGS = -L$(OUTDIR)
LDLIBS = -Wl,-Bstatic -lgur -Wl,-Bdynamic -lboost_unit_test_framework

AR = ar
ARFLAGS = rvs

all: libgur.so libgur.a
test: libgur.a unit_tests

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(OBJDIR)/%.po: $(SRCDIR)/%.cpp
	$(CXX) -fPIC -c -o $@ $< $(CXXFLAGS)

$(OBJTESTDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

OBJS := $(patsubst %.cpp, %.o, $(SRCS))
OBJS := $(patsubst $(SRCDIR)%, $(OBJDIR)%, $(OBJS))

POBJS := $(patsubst %.cpp, %.po, $(SRCS))
POBJS := $(patsubst $(SRCDIR)%, $(OBJDIR)%, $(POBJS))

TESTOBJS := $(patsubst %.cpp, %.o, $(TESTS))
TESTOBJS := $(patsubst $(TESTDIR)%, $(OBJTESTDIR)%, $(TESTOBJS))

libgur.so: $(POBJS)
	$(CXX) -shared -Wl,-soname,$@ -o $(OUTDIR)/$@ $^ $(CXXFLAGS)

libgur.a: $(OBJS)
	$(AR) $(ARFLAGS) $(OUTDIR)/$@ $^

unit_tests: $(TESTOBJS)
	$(CXX) -o $(OUTDIR)/$@ $^ $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

.PHONY: clean

clean:
	rm -f $(OUTDIR)/* $(OBJDIR)/*.o $(OBJDIR)/*.po $(OBJDIR)/**/*.o \
		$(OBJDIR)/**/*.po
