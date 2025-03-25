#pragma once
#include <mutex>
#include <condition_variable>

class Fork
{
private: 

public:	
	std::mutex mutex; // mutex to lock the fork when a philosopher is eating with it 
	Fork();
	~Fork();
};