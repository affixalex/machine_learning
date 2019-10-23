all: lecture2.exe lecture3.exe lecture4.exe

CXXFLAGS ?= -std=c++2a -g3 -gdwarf-4 -gsplit-dwarf -O2

clean:
	$(RM) *.exe
	$(RM) *.dwo

lecture2.exe: lecture2.cpp
	$(CXX) $(CXXFLAGS) lecture2.cpp -o $@

lecture3.exe: lecture3.cpp
	$(CXX) $(CXXFLAGS) lecture3.cpp -o $@

lecture4.exe: lecture4.cpp
	$(CXX) $(CXXFLAGS) lecture4.cpp -o $@
