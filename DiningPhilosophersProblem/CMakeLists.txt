# CMakeList.txt : CMake project for DiningPhilosophersProblem, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (
	DiningPhilosophersProblem
	"main.cpp"  
	 
	  
	 
	
 "Philosopher.h" "Philosopher.cpp"   "Fork.h"  "Fork.cpp"
 "Waiter.h" "Waiter.cpp")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DiningPhilosophersProblem PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
