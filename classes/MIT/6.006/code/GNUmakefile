all: lecture3.exe lecture4.exe

CXXFLAGS ?= -std=c++2a -fsanitize=memory -O2 -g3 -gdwarf-4 -gsplit-dwarf

clean:
	$(RM) *.exe
	$(RM) *.dwo

lecture3.exe: lecture3.cpp
	$(CXX) $(CXXFLAGS) lecture3.cpp -o $@

lecture4.exe: lecture4.cpp
	$(CXX) $(CXXFLAGS) lecture4.cpp -o $@
