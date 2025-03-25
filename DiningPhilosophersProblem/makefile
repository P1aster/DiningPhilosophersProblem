CXX = g++
CXXFLAGS = -std=c++20 -Wall -pthread

SRCS = main.cpp Philosopher.cpp Fork.cpp Waiter.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = DiningPhilosophers

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)