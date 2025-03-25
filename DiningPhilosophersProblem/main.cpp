#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <vector>
#include <queue>
#include "Philosopher.h"
#include "Fork.h"
#include "Waiter.h"


int main(int argc, char* argv[])
{

	if (argc != 7) {
		std::cerr << "Usage: " << argv[0] << " <PhilosopherNum> <min_thinking_time> <max_thinking_time> <min_eating_time> <max_eating_time> <cicles>" << std::endl;
		return 1;
	}

	int PhilosopherNum = std::stoi(argv[1]);
	int min_thinking_time = std::stoi(argv[2]);
	int max_thinking_time = std::stoi(argv[3]);
	int min_eating_time = std::stoi(argv[4]);
	int max_eating_time = std::stoi(argv[5]);
	size_t cicles = std::stoul(argv[6]);

	Waiter* waiter = new Waiter(PhilosopherNum);
	std::mutex printMutex;
	std::vector<Fork*> forks;
	std::vector<std::thread> threads;

	for (int i = 0; i < PhilosopherNum; i++)
	{
		auto fork = new Fork();
		forks.push_back(fork);
	}

	for (int i = 0; i < PhilosopherNum; i++)
	{
		auto philosopher = new Philosopher(
			i,
			"Philosopher-" + std::to_string(i),
			forks[i],
			forks[(i + 1) % PhilosopherNum],
			waiter,
			100, 1000, 100, 1000,
			10,
			&printMutex
		);
		std::thread t(&Philosopher::start, philosopher); // create a thread for the philosopher
		threads.push_back(std::move(t)); // move the thread to the team vector
	}

	for (auto& thread : threads)
	{
		thread.join(); // join the threads
	} // wait for the threads to finish before exiting the program

}