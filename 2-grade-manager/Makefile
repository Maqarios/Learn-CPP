CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

SRCS = student.cpp course.cpp main.cpp
OBJS = student.o course.o main.o
.DEFAULT_GOAL = grade-manager

grade-manager: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o grade-manager

student.o: student.h student.cpp
	$(CXX) $(CXXFLAGS) -c student.cpp

course.o: course.h course.cpp
	$(CXX) $(CXXFLAGS) -c course.cpp

main.o: student.h course.h main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(OBJS) grade-manager