CXX = g++

CXXFLAGS = -std=c++98 -Wall -Wextra

SRCDIR = srcs
INCDIR = include
OBJDIR = objs
BINDIR = .


SOURCES = $(wildcard $(SRCDIR)/*.cpp)

OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

EXEC = btc

all: $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(BINDIR)/$(EXEC)

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: all clean

$(OBJS): | $(OBJDIR)

