CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

SRCS = task.cpp main.cpp
OBJS = task.o main.o
.DEFAULT_GOAL = cli-task-manager

cli-task-manager: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o cli-task-manager

task.o: task.h task.cpp
	$(CXX) $(CXXFLAGS) -c task.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(OBJS) cli-task-manager