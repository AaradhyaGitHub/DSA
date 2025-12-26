# Stack Implementation - LIFO Data Structure

**Last Updated:** December 25, 2025  
**Learning Time:** ~4 hours (vector implementation) + ~3 hours (linked list implementation)  
**Difficulty:** `LC-Easy` patterns  
**Status:** ✅ Complete

---

## 📚 What's a Stack?

A **stack** is a data structure that follows **LIFO (Last In, First Out)** ordering.

Think of it like:
- 🥞 A stack of pancakes - you can only add/remove from the top
- 📚 A pile of books - last book placed is the first one you take off
- 🪨 Dropping stones in a narrow tube - last stone in is first stone out

**The key constraint:** You can ONLY work at the top. You cannot access the middle or bottom directly. This restriction is the feature - it prevents bugs and makes behavior predictable.

---

## 🎯 Prerequisites

Before tackling stacks, you should have completed:
- ✅ **Recursion** - Understanding the call stack (LIFO behavior)
- ✅ **LinkedLists Basics** - Node structure, pointer manipulation, traversal
- ✅ **LinkedLists Delete** - Memory management with `new` and `delete`

**Connection to Recursion:** When you write recursive code, your computer literally uses a stack (the "call stack") to manage function calls. Understanding stacks deepens your understanding of how recursion works under the hood.

---

## 📁 What's in This Folder

| File | Description | Underlying Structure |
|------|-------------|---------------------|
| `array_implementation.cpp` | Stack using vectors (dynamic arrays) | `vector<string>` |
| `linked_list_implementation.cpp` | Stack using linked lists | `Planet* head` (singly linked) |
| `README.md` | This file - learning journey and insights | |

**Why TWO implementations?** Each has different trade-offs. Learning both helps you understand when to use which approach and how abstract data types can have multiple concrete implementations.

---

## 🏗️ Implementation 1: Vector-Based Stack

### Example: Cities Going West
```cpp
El Cerrito → Albany → Berkeley → Emeryville → San Francisco
(East)                                              (West)
```

**Mental Model:** 
- Bottom of stack = El Cerrito (eastmost)
- Top of stack = last city pushed (westmost)

### Core Structure
```cpp
class CityStack {
private:
    vector<string> cities;  // Vector = dynamic array
    
public:
    void push(string city) {
        cities.push_back(city);  // Add to back (top of stack)
    }
    
    string pop() {
        if (cities.empty()) return "";
        string top = cities.back();  // Get last element
        cities.pop_back();           // Remove it
        return top;
    }
    
    string peek() {
        return cities.empty() ? "" : cities.back();
    }
    
    bool isEmpty() {
        return cities.empty();
    }
};
```

### Key Operations & Time Complexity
- **push()** - O(1) amortized (occasionally resizes)
- **pop()** - O(1)
- **peek()** - O(1)
- **isEmpty()** - O(1)

### When to Use Vector-Based Stack
✅ **Pros:**
- Simple implementation (vector does most work)
- Cache-friendly (contiguous memory = fast)
- Auto-resizes as needed
- No manual memory management

❌ **Cons:**
- Occasional resize cost (copies entire array)
- Allocates extra space for future growth

**Real-world use:** 99% of situations. This is what `std::stack` uses internally.

---

## 🔗 Implementation 2: Linked List-Based Stack

### Example: Solar System (Distance from Sun)
```cpp
Mercury → Venus → Earth → Mars → Jupiter → Saturn
(Closest)                                   (Farthest)
```

**Mental Model:**
- Bottom of stack = Mercury (first pushed)
- Top of stack (head) = last planet pushed
- Each node points to the next node

### Core Structure
```cpp
struct Planet {
    string name;
    Planet* next;
    Planet(string n) : name(n), next(nullptr) {}
};

class LinkedListStack {
private:
    Planet* head;  // Top of stack
    
public:
    LinkedListStack() { head = nullptr; }
    
    void push(string planet_name) {
        Planet* newPlanet = new Planet(planet_name);
        newPlanet->next = head;  // Point to old head
        head = newPlanet;        // Update head to new node
    }
    
    string pop() {
        if (head == nullptr) return "";
        string name = head->name;  // Save BEFORE moving head
        Planet* temp = head;
        head = head->next;         // Move head to next
        delete temp;               // Free memory
        return name;
    }
    
    string peek() {
        return (head == nullptr) ? "" : head->name;
    }
    
    ~LinkedListStack() {
        while (head != nullptr) {
            Planet* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
```

### Key Operations & Time Complexity
- **push()** - O(1) always (no resizing)
- **pop()** - O(1)
- **peek()** - O(1)
- **isEmpty()** - O(1)

### When to Use Linked List Stack
✅ **Pros:**
- True O(1) push (never resizes)
- Only uses memory for actual elements
- No wasted space

❌ **Cons:**
- Cache-unfriendly (nodes scattered in memory)
- Extra memory per node (stores `next` pointer)
- Manual memory management required

**Real-world use:** When you can't afford resize delays or when memory is very tight.

---

## 💡 Key Learning Insights

### 1. JavaScript vs C++ - The Pop() Betrayal

**JavaScript:**
```javascript
let arr = [1, 2, 3];
let removed = arr.pop();  // Returns 3 ✅
```

**C++:**
```cpp
vector<int> vec = {1, 2, 3};
int removed = vec.pop_back();  // ❌ ERROR - pop_back() returns VOID!
```

**The C++ Way:**
```cpp
int removed = vec.back();  // Get value first
vec.pop_back();            // Then remove it
return removed;            // Then return it
```

C++ separates "get" and "remove" operations. You must combine them manually.

---

### 2. Understanding LIFO Order

**Common Confusion:** "If I push in this order: A → B → C, what's at the top?"

**Answer:** C is at the top!

```
Push order:     Stack structure:
A first         [C] ← top (head)
B second        [B]
C last          [A] ← bottom
```

**To get A → B → C order in the stack, push in REVERSE: C → B → A**

---

### 3. Memory Management - The new/delete Pairing

**Every `new` needs a `delete`**, but not immediately!

```cpp
// push() does new
void push(string planet) {
    Planet* newPlanet = new Planet(planet);  // ← Allocate memory
    // Don't delete here! We want this node in the stack!
}

// pop() does delete
string pop() {
    // ...
    delete temp;  // ← Free memory when removing from stack
}

// Destructor does delete for ALL remaining nodes
~LinkedListStack() {
    while (head != nullptr) {
        delete head;  // ← Cleanup everything at end
    }
}
```

**The destructor is your safety net** - it cleans up any nodes left in the stack when the program ends.

---

### 4. Why Implement Stacks Multiple Ways?

**They all provide the same interface (push, pop, peek)** but with different trade-offs:

| Aspect | Vector-Based | Linked List-Based |
|--------|-------------|------------------|
| **Speed (average)** | O(1) | O(1) |
| **Speed (worst case)** | O(n) resize | O(1) always |
| **Memory efficiency** | Wastes some space | Only what's needed |
| **Cache performance** | Fast (contiguous) | Slower (scattered) |
| **Complexity** | Simple | More complex |
| **Manual memory** | No | Yes (new/delete) |

**Interview Reality:** You'll be asked to implement stacks AND explain these trade-offs.

---

## ⚠️ Common Pitfalls & How to Avoid Them

### Pitfall 1: Confusing Push Logic (Linked List)

**WRONG:**
```cpp
void push(string value) {
    Planet* newPlanet = new Planet(value);
    newPlanet->next = nullptr;  // ❌ Breaks the chain!
    head = newPlanet;
}
```

**This orphans all previous nodes!** You lose the entire stack.

**RIGHT:**
```cpp
void push(string value) {
    Planet* newPlanet = new Planet(value);
    newPlanet->next = head;  // ✅ Connect to existing chain
    head = newPlanet;        // ✅ Update head
}
```

**Remember:** New node points to OLD head, not nullptr (unless stack is empty).

---

### Pitfall 2: Returning head->name After Moving Head (Pop)

**WRONG:**
```cpp
string pop() {
    Planet* temp = head;
    head = head->next;    // head now points to NEXT node
    delete temp;
    return head->name;    // ❌ Returns WRONG node!
}
```

**You're returning the NEW head, not the node you just popped!**

**RIGHT:**
```cpp
string pop() {
    string name = head->name;  // ✅ Save BEFORE moving
    Planet* temp = head;
    head = head->next;
    delete temp;
    return name;               // ✅ Return saved value
}
```

---

### Pitfall 3: Forgetting the Destructor

**Without destructor:**
```cpp
int main() {
    LinkedListStack stack;
    stack.push("A");
    stack.push("B");
    return 0;  // ❌ Memory leak! Nodes never deleted
}
```

**With destructor:**
```cpp
~LinkedListStack() {
    while (head != nullptr) {
        Planet* temp = head;
        head = head->next;
        delete temp;  // ✅ Clean up all nodes
    }
}
```

**The destructor runs automatically when the stack object is destroyed.**

---

### Pitfall 4: Not Handling Empty Stack

**WRONG:**
```cpp
string peek() {
    return head->name;  // ❌ CRASHES if stack is empty!
}
```

**RIGHT:**
```cpp
string peek() {
    if (head == nullptr) return "";  // ✅ Safe
    return head->name;
}
```

**Always check for empty before accessing head!**

---

## 🆚 Vector vs Linked List - When to Use Which?

### Use Vector-Based Stack When:
- ✅ You're building something quickly
- ✅ Performance matters (cache-friendly)
- ✅ You don't know the size upfront
- ✅ You want simple, clean code
- ✅ **Default choice** - use this 95% of the time

### Use Linked List Stack When:
- ✅ You can't afford resize delays (real-time systems)
- ✅ Memory is extremely tight
- ✅ You're learning pointer manipulation
- ✅ Interview specifically asks for LL-based stack

### Industry Reality:
**In production code:** Just use `std::stack` (built-in C++ stack)
```cpp
#include <stack>
stack<string> myStack;
myStack.push("value");
myStack.pop();
```

**In interviews/learning:** You'll implement from scratch to show understanding.

---

## 🔄 Connection to Other Topics

### Recursion → Stack
Your Session 7 notes mention the call stack. Here's the connection:

**When you write:**
```cpp
void recursiveFunction(int n) {
    if (n == 0) return;
    recursiveFunction(n - 1);
}
```

**The computer does:**
```
Call Stack (actual stack in memory):
[recursiveFunction(3)] ← pushed last
[recursiveFunction(2)]
[recursiveFunction(1)]
[recursiveFunction(0)] ← returns first (LIFO!)
```

Every function call pushes onto the stack. Every return pops from the stack.

### Stack → Queue
**Next topic:** Queues are similar to stacks but use FIFO (First In, First Out) instead of LIFO. Understanding stacks makes queues easier because the operations are similar, just the order changes.

---

## 📝 Practice Problems

Once you understand the implementation, try these:

1. **Valid Parentheses** (LC-Easy pattern)
   - Use stack to match opening/closing brackets
   - Push opening brackets, pop when you see closing

2. **Min Stack** (LC-Easy pattern)
   - Design a stack with O(1) min() operation
   - Hint: Track minimum at each level

3. **Reverse a String** (LC-Easy pattern)
   - Push all characters, then pop them (automatic reversal!)

4. **Evaluate Postfix Expression** (LC-Medium pattern)
   - Use stack to evaluate expressions like "2 3 + 5 *"

---

## 🚀 Next Steps

**After completing Stack:**
1. Move to `Queue/` folder (FIFO behavior)
2. Compare LIFO (stack) vs FIFO (queue) use cases
3. See how queue implementations differ (need head AND tail pointers)

**Optional Deep Dive:**
- Implement min stack (track minimum element)
- Implement stack using two queues (interview classic)
- Study how the C++ `std::stack` is implemented

---

## 🎓 Learning Philosophy Reflection

**What made this click:**
1. **Visualizing vertical vs horizontal** - Stack = vertical pile, LinkedList = horizontal chain
2. **Real examples** - Cities going west, solar system planets
3. **JavaScript comparison** - Understanding why C++ does things differently
4. **Multiple implementations** - Seeing the same behavior with different internals

**Key takeaway:** A stack is an **abstract data type** (a behavior contract). How you implement it (vector, LL, array) is an implementation detail. The LIFO behavior is what matters.

---

## 💭 Final Thoughts

Stacks seem simple, but they're everywhere:
- Function call management (recursion)
- Undo/Redo functionality
- Browser back button
- Expression evaluation
- Depth-first search (future topic)

Understanding stacks at this level - not just how to use them, but how they're built and why different implementations exist - is fundamental to computer science.

**Time invested:** ~7 hours  
**Concepts mastered:** LIFO, memory management, trade-off analysis, pointer manipulation  
**Ready for:** Queues, more complex data structures

---

*Learning documented by Aaradhya Poudyal*  
*Session date: December 25, 2025*