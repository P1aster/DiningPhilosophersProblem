# Dining Philosophers Problem

## Description of the Problem

The Dining Philosophers Problem is a classic synchronization problem in computer
science. It involves five silent philosophers sitting at a round table, each with
a bowl of spaghetti. Forks are placed between each pair of adjacent philosophers.

### Key Points:

1. **Thinking and Eating**:  
   Each philosopher alternates between two activities: thinking and eating.
   However, a philosopher can only eat when they have both the fork on their left
   and the fork on their right.

2. **Fork Usage**:  
   - Each fork can only be held by one philosopher at a time.  
   - A philosopher can only use a fork if it is not being used by another
     philosopher.

3. **Releasing Forks**:  
   After finishing their meal, a philosopher must put down both forks so that
   they become available for others to use.

4. **Fork Availability**:  
   A philosopher can pick up the fork on their right or the fork on their left as
   they become available. However, they cannot start eating until they have
   acquired both forks.

5. **Infinite Resources**:  
   The problem assumes an infinite supply of spaghetti and an infinite demand for
   it. Eating is not limited by the amount of spaghetti or the philosophers'
   stomach capacity.

## Arbitrator Solution

I have used an Arbitrator solution that is presented as follows:

The Arbitrator approach guarantees that a philosopher can only pick up both forks
or none by introducing an arbitrator to replace circular waiting, e.g., a waiter.
In order to pick up the forks, a philosopher must ask permission of the waiter.
The waiter gives permission to only one philosopher at a time until the
philosopher has picked up both of his forks. Putting down a fork is always
allowed. The waiter can be implemented as a mutex. In addition to introducing a
new central entity (the waiter), this approach can result in reduced parallelism:
if a philosopher is eating and one of his neighbors is requesting the forks, all
other philosophers must wait until this request has been fulfilled even if forks
for them are still available.


## Key points

1. **Threads and What They Represent**
     * In this program, each thread represents a philosopher that is in one of two posibble states, he can eat or think.
     * The threads simulate the behavior of philosophers competing for shared resources (forks) to eat.
2. **Critical Sections and Their Solution**
     * Critical Sections are parts of the code where shared resources (forks) are accessed and modified. In this program, the critical sections are:

       * Picking up forks (acquiring locks on the forks).
       * Releasing forks (releasing locks on the forks).

   If not handled properly, critical sections can lead to ***deadlock*** (where all philosophers are stuck waiting for forks) or ***starvation*** (where some philosophers never get a chance to eat).

   * Solution: 
     * **Waiter**: A central authority (Waiter class) ensures that neighbour philosophers cannot eat simultaneously. This prevents ***deadlock*** and ***starvation***.
      * **Condition Variable**: Philosophers wait for permission from the waiter before attempting to pick up forks. The waiter uses a condition variable to notify philosophers when it’s safe to proceed.
     * **Mutexes**: Each fork is protected by a mutex to ensure exclusive access during critical sections.

       


## Main Issues

1. **Mutex and Lock**:  
   A mutex (short for "mutual exclusion") is a synchronization primitive used to
   protect shared resources from concurrent access by multiple threads. It
   ensures that only one thread can access the shared resource at a time,
   preventing race conditions.

   - **Lock**: A lock is an operation that a thread performs to acquire a mutex.
     If the mutex is already locked by another thread, the requesting thread will
     block (wait) until the mutex becomes available.  
   - **Unlock**: Unlock is the operation that releases the mutex, allowing other
     threads to acquire it.

2. **lock_guard and unique_lock**:  
   - **lock_guard**: A RAII (Resource Acquisition Is Initialization) wrapper for
     a mutex. It automatically locks the mutex when it is created and unlocks it
     when it goes out of scope. It does not allow manual locking or unlocking.  
   - **unique_lock**: Similar to lock_guard but provides more flexibility. It
     allows manual locking and unlocking and can be used with condition
     variables. It also supports deferred locking and transferring ownership.

3. **condition_variable**:  
   A *condition_variable* is a synchronization primitive used to block one or
   more threads until another thread modifies a shared variable (the condition)
   and notifies the condition_variable. It is often used with a mutex to avoid
   busy-waiting.

   - **wait**: Blocks the calling thread until the condition variable is
     notified. It automatically releases the associated mutex while waiting and
     re-acquires it before returning.  
   - **notify_one**: Wakes up one waiting thread.  
   - **notify_all**: Wakes up all waiting threads.
