CXX = g++11
INCLUDES= -Iinclude/
CXXFLAGS = -std=c++11 -g $(INCLUDES)  --coverage
SRC= src
TESTS=test
OBJ = $(SRC:.cpp=.o)
LINKFLAGS= -lcppunit

PROGRAM_TEST = tests

GCOV = gcov11
COVERAGE_RESULTS = result.coverage

all: clean coverage

$(PROGRAM_TEST): $(TESTS) $(SRC) main.cpp
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(TESTS)/* $(SRC)/* main.cpp $(LINKFLAGS)
	./$(PROGRAM_TEST)

# Default compile

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf objs bin $(PROGRAM_TEST) $(COVERAGE_RESULTS) 

coverage: $(PROGRAM_TEST)	
	mv *.gc* $(SRC)
	$(GCOV) $(SRC)/*		
	grep -r "####" *.cpp.gcov > $(COVERAGE_RESULTS)
	more $(COVERAGE_RESULTS)
	rm -f *.gcov  $(SRC)/*.gc*
