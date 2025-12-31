# Data Structures & Algorithms Learning Path

**Last Updated:** December 30, 2025  
**Status:** Active Development - More topics coming soon!

---

## 📊 LeetCode Pattern Coverage

> **Note:** These are NOT direct LeetCode problems, but they follow similar patterns and difficulty levels found on LeetCode. Solving these builds the foundation for tackling actual LeetCode questions.

```
┌─────────────────────────────────┐
│  📗 Easy Patterns:      13      │
│  📙 Medium Patterns:     3      │
│  📕 Hard Patterns:       0      │
├─────────────────────────────────┤
│  Total Problems:        16      │
└─────────────────────────────────┘
```

---

## 👋 Welcome!

This repository documents my journey learning Data Structures and Algorithms in C++. This guide will help you navigate everything.

---

## 🎯 Who Is This For?

- **Professors/Employers:** See my understanding of fundamental CS concepts and implementation skills
- **Friends:** Learn DSA with clear progression and documented pitfalls  
- **Future Me:** Remember the key insights that made concepts click

---

## 📋 Prerequisites

Before starting, you should know:
- Basic C++ syntax (variables, functions, loops, conditionals)
- How to compile and run C++ programs (`g++` command)
- Comfort with pointers (basic level - we'll go deeper in LinkedLists)

**Reference Files:**
- `Pointers.cpp` - Pointer concepts and examples
- `cheat_sheet.cpp` - Quick C++ syntax reference
- `Syllabus-update.md` - Course alignment notes

---

## 🗺️ Visual Study Path

```
START HERE
    ↓
[Recursion] → 4 problems
    ↓
[LinkedLists Basics] → 4 operations
    ↓
[Recursion Practice] → 2 problems  ← (Come back!)
    ↓
[LinkedLists Delete] → 3 operations
    ↓
[Stack] → 2 implementations
    ↓
[Queue] → 2 implementations
    ↓
MORE COMING SOON...
(BST, Heaps, and beyond)
```

---

## 📑 Quick Navigation Table

| # | Topic | Files to Complete | Difficulty | Folder |
|---|-------|-------------------|------------|--------|
| **1** | **Recursion Basics** | 4 files | | [`Recursion/`](./Recursion/) |
| | └─ [palindrome.cpp](./Recursion/palindrome.cpp) | Check if string is palindrome | `LC-Easy` | |
| | └─ [count_occurences.cpp](./Recursion/count_occurences.cpp) | Count element occurrences | `LC-Easy` | |
| | └─ [largest_in_the_list.cpp](./Recursion/largest_in_the_list.cpp) | Find max value | `LC-Easy` | |
| | └─ [reverse_list.cpp](./Recursion/reverse_list.cpp) | Reverse elements | `LC-Easy` | |
| **2** | **LinkedLists Basics** | 4 files | | [`LinkedLists/`](./LinkedLists/) |
| | └─ [LL_Implementation.cpp](./LinkedLists/LL_Implementation.cpp) | Build linked list from scratch | | |
| | └─ [head_insert_LL.cpp](./LinkedLists/head_insert_LL.cpp) | Insert at beginning | `LC-Easy` | |
| | └─ [search_LL.cpp](./LinkedLists/search_LL.cpp) | Traverse and find | `LC-Easy` | |
| | └─ [Reverse_LL.cpp](./LinkedLists/Reverse_LL.cpp) | Reverse entire list | `LC-Easy` | |
| **3** | **Recursion Practice** | 2 files | | [`Recursion/practice/`](./Recursion/practice/) |
| | └─ [reverse_list.cpp](./Recursion/practice/reverse_list.cpp) | Reverse recursively | `LC-Medium` | |
| | └─ [sum_list.cpp](./Recursion/practice/sum_list.cpp) | Calculate sum | `LC-Easy` | |
| **4** | **LinkedLists Delete** | 3 files | | [`LinkedLists/Delete/`](./LinkedLists/Delete/) |
| | └─ [head_delete_LL.cpp](./LinkedLists/Delete/head_delete_LL.cpp) | Delete from front | `LC-Easy` | |
| | └─ [middle_delete_LL.cpp](./LinkedLists/Delete/middle_delete_LL.cpp) | Delete from middle | `LC-Medium` | |
| | └─ [tail_delete_LL.cpp](./LinkedLists/Delete/tail_delete_LL.cpp) | Delete from end | `LC-Medium` | |
| **5** | **Stacks (LIFO)** | 2 files | | [`Stack/`](./Stack/) |
| | └─ [array_implementation.cpp](./Stack/array_implementation.cpp) | Vector-based stack | `LC-Easy` | |
| | └─ [linked_list_implementation.cpp](./Stack/linked_list_implementation.cpp) | LL-based stack | `LC-Easy` | |
| **6** | **Queue (FIFO)** | 2 files | | [`Queue/`](./Queue/) |
| | └─ [linked_list_implementation.cpp](./Queue/linked_list_implementation.cpp) | LL-based queue | `LC-Easy` | |
| | └─ [circular_array_implementation.cpp](./Queue/circular_array_implementation.cpp) | Circular array queue | `LC-Easy` | |

**Completed:** 16 implementation files across 6 major topics  
**Coming Next:** Binary Search Trees, Heaps, and more...

---

## 📖 Detailed Breakdown by Phase

### **Phase 1: Recursion Foundations**
📁 **Folder:** `Recursion/`

Master recursive thinking before diving into data structures. Understanding the call stack here is crucial for everything that follows.

**Order:**
1. `palindrome.cpp` - Check if a string reads the same forwards and backwards
2. `count_occurences.cpp` - Count how many times an element appears
3. `largest_in_the_list.cpp` - Find max value using recursion
4. `reverse_list.cpp` - Reverse elements recursively

**Key Concepts:**
- Base cases and recursive cases
- Call stack visualization (LIFO behavior)
- How function calls "stack up" and return

**⏸️ STOP HERE** - Take a break and move to LinkedLists

📖 *Detailed notes available in `Recursion/README.md`*

---

### **Phase 2: LinkedLists Basics**
📁 **Folder:** `LinkedLists/`

Now that you understand recursive thinking, learn how to build and manipulate linked structures.

**Important:** Several files use `Node.h` (a header file defining the Node structure). Understanding this is part of the learning - see `LinkedLists/README.md` for OOP and header file explanations.

**Order:**
1. `LL_Implementation.cpp` - Build a linked list from scratch
2. `head_insert_LL.cpp` - Insert at the beginning (O(1) operation)
3. `search_LL.cpp` - Traverse and find elements
4. `Reverse_LL.cpp` - Reverse the entire list

**Key Concepts:**
- Pointer manipulation (`->` operator)
- Node structure (data + next pointer)
- Traversal patterns
- Why we use header files (`Node.h`)

📖 *Detailed notes available in `LinkedLists/README.md`*

---

### **Phase 3: Back to Recursion Practice**
📁 **Folder:** `Recursion/practice/`

Now that you understand linked lists, these recursive problems will make more sense.

**Order:**
1. `reverse_list.cpp` - Reverse a list recursively (connects recursion + LL knowledge)
2. `sum_list.cpp` - Calculate sum using recursion

**Why come back now?** LinkedList traversal uses the same patterns as recursion. This reinforces both concepts.

📖 *Practice notes available in `Recursion/practice/README.md`*

---

### **Phase 4: LinkedLists Delete Operations**
📁 **Folder:** `LinkedLists/Delete/`

Deletion is trickier than insertion - you need to track previous nodes and handle edge cases.

**Order (by difficulty):**
1. `head_delete_LL.cpp` - Delete from beginning (easiest - no traversal)
2. `middle_delete_LL.cpp` - Delete from middle (requires traversal)
3. `tail_delete_LL.cpp` - Delete from end (trickiest - need prev pointer)

**Bonus:** `Barca_Substitution_Tracker.cpp` - Fun project applying delete operations

**Key Concepts:**
- Memory cleanup (`delete` keyword)
- Edge cases (empty list, single node, last node)
- Tracking previous pointers

📖 *Detailed notes available in `LinkedLists/Delete/README.md`*

---

### **Phase 5: Stacks (LIFO)**
📁 **Folder:** `Stack/`

Build stacks using TWO different underlying implementations to understand trade-offs.

**Order:**
1. `array_implementation.cpp` - Stack using vectors (dynamic arrays)
2. `linked_list_implementation.cpp` - Stack using linked lists

**Key Questions Answered:**
- Why implement stacks multiple ways?
- Vector vs LinkedList trade-offs (speed, memory, flexibility)
- When to use which implementation
- Memory management (`new`/`delete` pairing)

**Key Concepts:**
- LIFO (Last In, First Out) behavior
- Abstraction as constraint (only work at top)
- Connection to recursion (call stack)
- Destructor for cleanup

📖 *Detailed notes available in `Stack/README.md`*

---

### **Phase 6: Queue (FIFO)**
📁 **Folder:** `Queue/`

Build queues using TWO different underlying implementations to understand trade-offs and contrast with Stack.

**Order:**
1. `linked_list_implementation.cpp` - Queue using linked lists (naturally suited for queues)
2. `circular_array_implementation.cpp` - Queue using circular array/vector (fixed capacity)

**Key Questions Answered:**
- How is Queue different from Stack? (FIFO vs LIFO)
- Why do queues need TWO pointers instead of one?
- What is a circular array and why use it?
- When to use LinkedList vs Array-based queue?

**Key Concepts:**
- FIFO (First In, First Out) behavior
- Two-pointer management (head and tail)
- Circular wrap-around with modulo arithmetic
- The "lost slot" tradeoff in circular arrays
- Memory management differences (LL vs vector)

📖 *Detailed notes available in `Queue/README.md`*

---

## 🚧 What's Next?

This repository is actively growing as I continue learning DSA. Topics coming soon:
- **Binary Search Tree** - Tree structures and traversals
- **Heaps & Priority Queues** - Special tree structures
- **Hash Tables** - O(1) lookup structures
- **Graphs** - Network structures and algorithms
- **Dynamic Programming** - Optimization techniques
- ...and more!

---

## 📚 How Each Folder Is Organized

Every folder contains:
- **Implementation files** (`.cpp`) - The actual code
- **README.md** - Concepts, pitfalls, insights specific to that topic
- **Subfolders** (when applicable) - Advanced or related topics, each with their own README

**Note:** Some folders reference `Node.h` or other header files - explanations for these are in the folder's README.

---

## 🎓 Learning Philosophy

This repository reflects a specific learning approach:

1. **Concept before code** - Understand *what* and *why* before *how*
2. **Mental models matter** - Visualize data structures before implementing
3. **Document struggles** - Mistakes and breakthroughs are learning opportunities
4. **Multiple implementations** - See trade-offs by building the same structure different ways
5. **Connect the dots** - Each topic builds on previous knowledge

**Example:** We learn recursion first because it teaches LIFO thinking, which makes stacks intuitive. Stacks then contrast with queues (LIFO vs FIFO). Both use linked lists and arrays, which we already mastered. Each concept reinforces the others.

---

## 🤔 More Info

**Q: Skipping around?**  
A: Not recommended. Each phase builds on the previous one. Skipping ahead will leave gaps.

**Q: Get stuck?**  
A: Check the README in that specific folder - common pitfalls are documented. Also reference earlier topics you might have forgotten.

**Q: Why so many README files?**  
A: Each topic has unique insights worth documenting. The main README (this file) is for navigation; individual READMEs are for deep understanding.

**Q: JavaScript / Python background - will this help?**  
A: Yes! Many READMEs document JS→C++ translation differences (especially for arrays, memory, and destructors).

---

*Created by Aaradhya Poudyal*  
*Last updated: December 30, 2025*