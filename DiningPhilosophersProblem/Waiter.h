#pragma once
#include <mutex>
#include <vector>


class Waiter {
private:
	std::mutex mutex; // mutex to lock access to the eating vector
	std::condition_variable cv; // condition variable to wait for the neighbors to finish eating
	std::vector<bool> eating; // vector to store the eating status of each philosopher
	int numberOfPhilosophers; // number of philosophers
public:
    Waiter(int numPhilosophers);
    void requestEatPermission(int philosopherId);
	void declareFinishedEating(int philosopherId);

};