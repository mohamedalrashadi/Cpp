# Dynamic Programming (DP)

### The Concept (Simple Explanation)
Think of DP as "solving a problem by **remembering your past work**." It's used for problems that can be broken down into smaller, overlapping sub-problems. Instead of solving the same sub-problem over and over, you solve it once and store the answer in a table (or "memo"). When you need the answer again, you just look it up.

### Example: Fibonacci Sequence
The Fibonacci sequence is . A naive recursive solution is incredibly slow because it re-calculates the same values many times.

```cpp
// Naive, slow version. Calculating fib(5) will call fib(3) twice.
int fib_naive(int n) {
    if (n <= 1) return n;
    return fib_naive(n - 1) + fib_naive(n - 2);
}
```

### Common Mistake ❌
Writing a recursive solution that solves the exact same sub-problem multiple times. This leads to an exponential time complexity (very, very slow) for what should be a fast problem.

### The Solution ✅
Use **Memoization**! This is the top-down DP approach. We use a map or an array to store the results of sub-problems as we solve them. Before computing, we check if we've already stored the answer.

```cpp
#include <map>

// A "memo" to store results we've already calculated
std::map<int, int> memo;

int fib_dp(int n) {
    if (n <= 1) return n;

    // Before computing, check if the answer is already in our memo
    if (memo.count(n)) {
        return memo[n];
    }

    // If not, compute it, STORE it, then return it.
    int result = fib_dp(n - 1) + fib_dp(n - 2);
    memo[n] = result;
    return result;
}
```
This DP version is dramatically faster!
