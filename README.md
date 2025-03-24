# Dining Philosophers Problem

## Description of the Problem

The Dining Philosophers Problem is a classic synchronization problem in computer science. It involves five silent philosophers sitting at a round table, each with a bowl of spaghetti. Forks are placed between each pair of adjacent philosophers.

### Key Points:
1. **Thinking and Eating**:  
   Each philosopher alternates between two activities: thinking and eating. However, a philosopher can only eat when they have both the fork on their left and the fork on their right.

2. **Fork Usage**:  
   - Each fork can only be held by one philosopher at a time.  
   - A philosopher can only use a fork if it is not being used by another philosopher.

3. **Releasing Forks**:  
   After finishing their meal, a philosopher must put down both forks so that they become available for others to use.

4. **Fork Availability**:  
   A philosopher can pick up the fork on their right or the fork on their left as they become available. However, they cannot start eating until they have acquired both forks.

5. **Infinite Resources**:  
   The problem assumes an infinite supply of spaghetti and an infinite demand for it. Eating is not limited by the amount of spaghetti or the philosophers' stomach capacity.



## Chandy/Misra solution

I have used a Chandy/Misra solution that is presented as follows:

   1. For every pair of philosophers contending for a resource, create a fork and give it to the philosopher with the lower ID (n for agent Pn). Each fork can either be dirty or clean. Initially, all forks are dirty.
   2. When a philosopher wants to use a set of resources (i.e. eat), said philosopher must obtain the forks from their contending neighbors. For all such forks the philosopher does not have, they send a request message.
   3. When a philosopher with a fork receives a request message, they keep the fork if it is clean, but give it up when it is dirty. If the philosopher sends the fork over, they clean the fork before doing so.
   4. After a philosopher is done eating, all their forks become dirty. If another philosopher had previously requested one of the forks, the philosopher that has just finished eating cleans the fork and sends it.
