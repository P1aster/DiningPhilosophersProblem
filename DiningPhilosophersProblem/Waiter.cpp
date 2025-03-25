#include "Waiter.h"

Waiter::Waiter(int numberOfPhilosophers) : numberOfPhilosophers(numberOfPhilosophers) {
	eating.resize(numberOfPhilosophers, false);
}

void Waiter::requestEatPermission(int philosopherId) {
	std::unique_lock<std::mutex> lock(mutex);
	cv.wait(lock, [this, philosopherId]() { // Wait until neighbors are not eating
        // Check if neighbors are eating
        bool leftNeighbor = (philosopherId + numberOfPhilosophers - 1) % numberOfPhilosophers;
        bool rightNeighbor = (philosopherId + 1) % numberOfPhilosophers;
        return !eating[leftNeighbor] && !eating[rightNeighbor];
    });
}

void Waiter::declareFinishedEating(int philosopherId) {
	std::lock_guard<std::mutex> lock(mutex); // Lock the mutex to access the eating vector 
	eating[philosopherId] = false; // Set the philosopher as not eating
	cv.notify_all(); // Notify all philosophers that the philosopher has finished eating
	
}

