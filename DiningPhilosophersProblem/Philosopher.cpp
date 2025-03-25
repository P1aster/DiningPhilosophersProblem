#include "Philosopher.h"
#include <iostream>
#include <random>

Philosopher::Philosopher(
	int id,
	std::string name,
	Fork* leftFork,
	Fork* rightFork,
	Waiter* waiter,
	int min_thinking_time,
	int max_thinking_time,
	int min_eating_time,
	int max_eating_time,
	size_t cicles,
	std::mutex* printMutex
)
	: 
	id(id),
	name(name),
	leftFork(leftFork),
	rightFork(rightFork),
	waiter(waiter),
	min_thinking_time(min_thinking_time),
	max_thinking_time(max_thinking_time),
	min_eating_time(min_eating_time),
	max_eating_time(max_eating_time),
	cicles(cicles),
	printMutex(printMutex)

{
}

Philosopher::~Philosopher()
{
}



void Philosopher::eat()
{
	waiter->requestEatPermission(this->id); // Request permission to eat

	std::lock(leftFork->mutex, rightFork->mutex);
	std::lock_guard<std::mutex> leftForkLock(leftFork->mutex, std::adopt_lock);
	std::lock_guard<std::mutex> rightForkLock(rightFork->mutex, std::adopt_lock);


	print("is eating");
	std::uniform_int_distribution<> randValue(min_eating_time, max_eating_time);
	std::this_thread::sleep_for(std::chrono::milliseconds(randValue(random)));
	print("has finished eating");

	waiter->declareFinishedEating(this->id); // Declare finished eating	
}

void Philosopher::think()
{
	print("is thinking");
	std::uniform_int_distribution<> randValue(min_thinking_time, max_thinking_time);
	std::this_thread::sleep_for(std::chrono::milliseconds(randValue(random))); 
	print("has finished thinking");
}

void Philosopher::print(std::string message)
{
	printMutex->lock();
	std::cout << name << ": " << message << std::endl;
	printMutex->unlock();
}

void Philosopher::start()
{
	int c = 0;
	while (c < cicles)
	{
		think();
		eat();
		c++;
	}
}

