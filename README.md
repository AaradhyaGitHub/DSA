# Data Structures & Algorithms Learning Path

**Last Updated:** December 25, 2024  
**Status:** Active Development - More topics coming soon!

---

## 👋 Welcome!

This repository documents my journey learning Data Structures and Algorithms in C++. Whether you're a professor checking out my work, a friend looking to practice DSA, or future me coming back for a refresher - this guide will help you navigate everything.

**Philosophy:** Concept-first, syntax-second. Understanding *why* before *how*. Building mental models through struggle and breakthrough moments.

---

## 🎯 Who Is This For?

- **Professors:** See my understanding of fundamental CS concepts and implementation skills
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

## 🗺️ The Complete Learning Path

Follow this order - each section builds on the previous one:

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

### **Phase 6: Queues (FIFO)**
📁 **Folder:** `Queue/`

Learn FIFO behavior and advanced queue variants.

**Order:**
1. `linked_list_implementation.cpp` - Basic queue with LL
2. `circular_array_implementation.cpp` - Efficient array-based queue
3. `deque_implementation.cpp` - Double-ended queue (add/remove from both ends)

**Key Concepts:**
- FIFO (First In, First Out) behavior
- Circular buffer logic
- Head AND tail pointers
- Deque use cases

📖 *Detailed notes available in `Queue/README.md`*

---

### **Phase 7: Binary Search Trees**
📁 **Folder:** `Binary Search Tree/`

Non-linear data structure with hierarchical relationships.

**Order:**

**Part 1: Structure & Basic Operations**
1. `bst_structure.cpp` - Node definition + BST class skeleton
2. `insert.cpp` - Add nodes while maintaining BST property
3. `search.cpp` - Find elements efficiently

**Part 2: Tree Traversals**  
📁 **Subfolder:** `traversals/`
1. `inorder.cpp` - Left → Root → Right (gives sorted order!)
2. `preorder.cpp` - Root → Left → Right
3. `postorder.cpp` - Left → Right → Root

**Key Concepts:**
- BST property: left < parent < right
- Why in-order traversal gives sorted output
- Recursive tree operations
- When to use each traversal type

📖 *Detailed notes available in `Binary Search Tree/README.md`*  
📖 *Traversal notes in `Binary Search Tree/traversals/README.md`*

---

## 🚧 What's Next?

This repository is actively growing as I continue learning DSA. Topics coming soon:
- More tree operations (delete, balance)
- Heaps & Priority Queues
- Hash Tables
- Graphs
- Dynamic Programming
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

**Example:** We learn recursion first because it teaches LIFO thinking, which makes stacks intuitive. Then stacks use linked lists, which we already mastered. Each concept reinforces the others.

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
*Last updated: December 25, 2024*