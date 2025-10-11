# Smart Pointers

### The Concept (Simple Explanation)
Remember the dangers of manual memory management (forgetting `delete`, memory leaks)? **Smart pointers** solve this problem. They are wrapper objects that hold a raw pointer. When the smart pointer object goes out of scope (e.g., at the end of a function), its destructor is automatically called, and it frees the memory for you. This principle is called **RAII (Resource Acquisition Is Initialization)**.

### Example: `std::unique_ptr`
A `std::unique_ptr` represents **exclusive ownership**. Only one `unique_ptr` can point to a given object at a time. You cannot copy it. This is the most common and efficient smart pointer.

```cpp
#include <iostream>
#include <memory> // Required for smart pointers

class Gizmo {
public:
    Gizmo() { std::cout << "Gizmo created\n"; }
    ~Gizmo() { std::cout << "Gizmo destroyed\n"; } // Destructor
};

void process_gizmo() {
    std::unique_ptr<Gizmo> p_gizmo = std::make_unique<Gizmo>();
    // ... use p_gizmo ...
} // p_gizmo goes out of scope here. Its destructor is called automatically,
  // which in turn calls delete on the Gizmo object. No memory leak!

int main() {
    std::cout << "Entering main\n";
    process_gizmo();
    std::cout << "Exiting main\n";
    return 0;
}
```
Output:
Entering main
Gizmo created
Gizmo destroyed
Exiting main

### Common Mistake ❌
Still using `new` and `delete` everywhere in new code. Another mistake is trying to have two `unique_ptr`s own the same object.

```cpp
// MISTAKE 1: Manually creating and then trying to assign
Gizmo* raw_ptr = new Gizmo();
std::unique_ptr<Gizmo> p1(raw_ptr);
std::unique_ptr<Gizmo> p2(raw_ptr); // ERROR! Now two unique_ptrs think they own the
                                  // same memory. Both will try to delete it, causing a crash.
```

### The Solution ✅
Adopt a "smart pointers first" policy. Use `std::make_unique` to create objects managed by a `unique_ptr`. If you need to share ownership (a rarer case), use `std::shared_ptr` and `std::make_shared`. This shift in mindset is the key to writing safe, modern C++.
