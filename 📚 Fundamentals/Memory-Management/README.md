# Memory Management

### The Concept (Simple Explanation)
Your program has two main places to store data: the **Stack** and the **Heap**.
* **Stack:** Fast, automatic, and temporary. Local variables in functions go here. When the function ends, the memory is automatically cleaned up.
* **Heap:** A large, open space for data that needs to live longer than a single function. You must manage this memory **manually** using `new` (to request memory) and `delete` (to give it back).

### Example
We need an array, but we don't know the size until the program runs. This is a perfect job for the Heap.

```cpp
#include <iostream>

int main() {
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    // Request memory from the Heap
    int* my_array = new int[size];

    // ... use the array ...
    my_array[0] = 10;

    // IMPORTANT: Give the memory back when you're done!
    delete[] my_array;

    return 0;
}
```

### Common Mistake ❌
Forgetting to `delete` the memory you allocated with `new`. This is called a **memory leak**. If your program keeps requesting memory without ever giving it back, it will eventually run out of memory and crash.

Another common mistake is using `delete` for an array allocated with `new[]`. You must match them correctly!

```cpp
// MISTAKE 1: Memory Leak
void some_function() {
    int* data = new int[500];
    // Function ends, but we never called delete[]. The memory is now lost forever.
}

// MISTAKE 2: Mismatch
int* numbers = new int[10];
delete numbers; // WRONG! Should be delete[] numbers. This is undefined behavior.
```

### The Solution ✅
For every `new`, have a corresponding `delete`. For every `new[]`, have a corresponding `delete[]`. The modern C++ solution is even better: **avoid manual memory management altogether** by using smart pointers (which you'll learn about in `Advanced-Topics`). They handle `delete` for you automatically!
