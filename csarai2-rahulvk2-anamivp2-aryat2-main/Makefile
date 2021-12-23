# This defines our compiler and linker, as we've seen before.
CXX = clang++
LD = clang++

# These are the options we pass to the compiler.
# -std=c++1y means we want to use the C++14 standard (called 1y in this version of Clang).
# -stdlib=libc++ specifies that we want to use the standard library implementation called libc++
# -c specifies making an object file, as you saw before
# -g specifies that we want to include "debugging symbols" which allows us to use a debugging program.
# -O0 specifies to do no optimizations on our code.
# -Wall, -Wextra, and -pedantic tells the compiler to look out for common problems with our code. -Werror makes it so that these warnings stop compilation.
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -Werror -pedantic

# These are the options we pass to the linker.
# The first two are the same as the compiler flags.
# -l<something> tells the linker to go look in the system for pre-installed object files to link with.
# Here we want to link with the object files from libpng (since we use it in our code) and libc++. Remember libc++ is the standard library implementation.
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

project : dfs.o scc.o edge.o vertex.o graph.o parsing_utils.o draw_utils.o PNG.o HSLAPixel.o lodepng.o main.o
	$(LD) dfs.o scc.o edge.o vertex.o graph.o parsing_utils.o draw_utils.o PNG.o HSLAPixel.o lodepng.o main.o $(LDFLAGS) -o project

dfs.o : src/dfs.cpp src/dfs.h
	$(CXX) $(CXXFLAGS) src/dfs.cpp

scc.o : src/scc.cpp src/scc.h
	$(CXX) $(CXXFLAGS) src/scc.cpp

edge.o : src/edge.cpp src/edge.h
	$(CXX) $(CXXFLAGS) src/edge.cpp

vertex.o : src/vertex.cpp src/vertex.h
	$(CXX) $(CXXFLAGS) src/vertex.cpp

graph.o : src/graph.cpp src/graph.h
	$(CXX) $(CXXFLAGS) src/graph.cpp

parsing_utils.o : src/parsing_utils.cpp src/parsing_utils.h
	$(CXX) $(CXXFLAGS) src/parsing_utils.cpp

PNG.o: src/cs225/PNG.cpp src/cs225/PNG.h src/cs225/HSLAPixel.h src/cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) src/cs225/PNG.cpp

HSLAPixel.o: src/cs225/HSLAPixel.cpp src/cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) src/cs225/HSLAPixel.cpp

lodepng.o: src/cs225/lodepng/lodepng.cpp src/cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) src/cs225/lodepng/lodepng.cpp

draw_utils.o : src/draw_utils.cpp src/draw_utils.h
	$(CXX) $(CXXFLAGS) src/draw_utils.cpp

main.o : main.cpp src/dfs.h src/edge.h src/graph.h src/parsing_utils.h src/draw_utils.h src/vertex.h src/cs225/PNG.h 
	$(CXX) $(CXXFLAGS) main.cpp

test: catchmain.o test_draw.o test_scc.o test_dfs.o test_parser.o test_vertex.o test_edge.o test_graph.o scc.o dfs.o parsing_utils.o edge.o vertex.o graph.o draw_utils.o PNG.o HSLAPixel.o lodepng.o
	$(LD) catchmain.o test_draw.o test_scc.o test_dfs.o test_parser.o test_vertex.o test_edge.o test_graph.o scc.o dfs.o parsing_utils.o edge.o vertex.o graph.o draw_utils.o PNG.o HSLAPixel.o lodepng.o $(LDFLAGS) -o test

catchmain.o : src/cs225/catch/catchmain.cpp src/cs225/catch/catch.hpp
	$(CXX) $(CXXFLAGS) src/cs225/catch/catchmain.cpp

test_dfs.o : tests/test_dfs.cpp src/cs225/catch/catch.hpp src/dfs.h src/parsing_utils.h src/edge.h src/vertex.h src/graph.h 
	$(CXX) $(CXXFLAGS) tests/test_dfs.cpp

test_parser.o : tests/test_parser.cpp src/cs225/catch/catch.hpp src/parsing_utils.h src/edge.h src/vertex.h
	$(CXX) $(CXXFLAGS) tests/test_parser.cpp

test_vertex.o : tests/test_vertex.cpp src/cs225/catch/catch.hpp src/vertex.h 
	$(CXX) $(CXXFLAGS) tests/test_vertex.cpp	

test_edge.o : tests/test_edge.cpp src/cs225/catch/catch.hpp src/edge.h 
	$(CXX) $(CXXFLAGS) tests/test_edge.cpp	

test_graph.o : tests/test_graph.cpp src/cs225/catch/catch.hpp src/graph.h 
	$(CXX) $(CXXFLAGS) tests/test_graph.cpp	

test_scc.o : tests/test_scc.cpp src/cs225/catch/catch.hpp src/scc.h
	$(CXX) $(CXXFLAGS) tests/test_scc.cpp	

test_draw.o : tests/test_draw.cpp src/cs225/catch/catch.hpp src/draw_utils.h
	$(CXX) $(CXXFLAGS) tests/test_draw.cpp	

clean :
	-rm -f *.o $(EXENAME) test project