#pragma once
#include <string>
#include <mutex>
#include <random>
#include "Fork.h"
#include "Waiter.h"

class Philosopher
{
private:
	int id; // id of the philosopher
	std::string name; // name of the philosopher
	size_t cicles; // number of cicles
	Fork* leftFork; // left fork
	Fork* rightFork; // right fork
	Waiter* waiter; // waiter
	std::mutex* printMutex; // mutex for printing
	int min_thinking_time; // minimum thinking time
	int max_thinking_time; // maximum thinking time
	int min_eating_time; // minimum eating time
	int max_eating_time; // maximum eating time
	std::mt19937 random{ std::random_device{}() }; // random number generator

public:
	Philosopher(int, std::string, Fork*, Fork*, Waiter*, int, int, int, int, size_t, std::mutex*);
	~Philosopher();
	void eat();
	void think();
	void start();
	void print(std::string);

};