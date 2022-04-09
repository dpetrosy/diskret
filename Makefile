.PHONY: all re clear clean fclean debug gcov lcov clean_gcda clean_gcno fclean_glcov

FOLDER=src
SOURCES=$(wildcard $(FOLDER)/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
CC=g++
FLAGS=-Wall -Wextra -Werror
EXECUTABLE=graph.exe
LCOVTEST=$(EXECUTABLE:.exe=.info)

all : $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o :
	$(CC) $(FLAGS) -c $< -o $@

re : fclean all

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(EXECUTABLE)

debug :
	gdb $(EXECUTABLE)

gcov :
	$(CC) $(SOURCES) --coverage -o $(EXECUTABLE)
	./$(EXECUTABLE)

lcov :
	lcov -t "program" -o $(LCOVTEST) -c -d .
	genhtml -o report $(LCOVTEST)
	rm -f *.gcda
	rm -f *.gcno
	rm -f $(LCOVTEST)
	rm -f $(EXECUTABLE)
	open -a "Firefox" report/index.html

clean_gcda :
	rm -f *.gcda

clean_gcno :
	rm -f *.gcno

fclean_glcov : clean_gcda clean_gcno
	rm -f $(LCOVTEST)
	rm -rf report
	rm -f $(EXECUTABLE)
