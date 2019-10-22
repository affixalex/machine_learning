all: lecture2

CFLAGS ?= -g3 -gdwarf-4 -gsplit-dwarf -O2

clean:
	$(RM) lecture2
	$(RM) lecture2.dwo

lecture2: lecture2.cpp
	$(CXX) $(CFLAGS) lecture2.cpp -o $@
