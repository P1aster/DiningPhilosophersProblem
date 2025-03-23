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
