CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

testbst: intbst.cpp testbst.cpp
	$(CXX) $(CXXFLAGS) intbst.cpp testbst.cpp -o testbst

clean:
	rm -f testbst


