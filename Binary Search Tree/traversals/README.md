# BST Traversals - DFS (Depth-First Search)

> **Last Updated:** January 10, 2026  
> **Learning Time:** ~1 hour total (all 3 traversals)  
> **Difficulty:** LC-Easy patterns  
> **Status:** ✅ Complete

---

## 📚 What Are Tree Traversals?

**Traversal** = visiting every node in the tree exactly once.

**DFS (Depth-First Search)** = go deep into one branch before exploring others.

### The Three Orders

- **In-order:** Left → Root → Right
- **Pre-order:** Root → Left → Right
- **Post-order:** Left → Right → Root

---

## 🎯 The Key Insight

**All three traversals use THE EXACT SAME pattern.**

**The ONLY difference:** When you print relative to the recursive calls.

```cpp
// In-order
traverse(left);
print(data);      // ← Print in the MIDDLE
traverse(right);

// Pre-order
print(data);      // ← Print FIRST
traverse(left);
traverse(right);

// Post-order
traverse(left);
traverse(right);
print(data);      // ← Print LAST
```

**Everything else is identical:**
- Same base case: `if (node == nullptr) return;`
- Same recursive calls: `helper(node->left)` and `helper(node->right)`
- Same structure: Base case → recursive exploration → return

---

## 📁 What's in This Folder

| File | Traversal Order | Output for BST | Use Case |
|------|----------------|----------------|----------|
| `inorder.cpp` | Left → Root → Right | **Sorted values** | Most common for BST |
| `preorder.cpp` | Root → Left → Right | Root first | Copy tree, serialize |
| `postorder.cpp` | Left → Right → Root | Root last | Delete tree, evaluate expressions |
| `README.md` | This file | Documentation | - |

---

## 🌳 Visual Example

**Tree:**
```
       5
      / \
     3   7
    / \
   1   4
```

**Output by Traversal:**
- **In-order (Left → Root → Right):** `1, 3, 4, 5, 7` ← **SORTED!**
- **Pre-order (Root → Left → Right):** `5, 3, 1, 4, 7` ← Root first
- **Post-order (Left → Right → Root):** `1, 4, 3, 7, 5` ← Root last

---

## 📝 Implementation Pattern

### The Public Function (Same for All Three)

```cpp
vector<int> inorder() {
    if (root == nullptr) {
        cout << "❌ Empty tree, cannot traverse!" << endl;
        return {};
    }
    
    vector<int> result;
    inorderHelper(root, result);
    return result;
}
```

**Key points:**
- Check if tree is empty BEFORE calling helper
- Create empty vector
- Pass vector by reference to helper (important!)
- Return filled vector

### The Helper Function (Differs Only in Print Timing)

#### In-order

```cpp
void inorderHelper(Node* node, vector<int>& result) {
    if (node == nullptr) return;  // Base case
    
    inorderHelper(node->left, result);   // Left
    result.push_back(node->data);        // Root ← Middle
    inorderHelper(node->right, result);  // Right
}
```

#### Pre-order

```cpp
void preorderHelper(Node* node, vector<int>& result) {
    if (node == nullptr) return;  // Base case
    
    result.push_back(node->data);        // Root ← First
    preorderHelper(node->left, result);  // Left
    preorderHelper(node->right, result); // Right
}
```

#### Post-order

```cpp
void postorderHelper(Node* node, vector<int>& result) {
    if (node == nullptr) return;  // Base case
    
    postorderHelper(node->left, result);  // Left
    postorderHelper(node->right, result); // Right
    result.push_back(node->data);         // Root ← Last
}
```

---

## 🔑 Critical Concepts

### 1. Pass by Reference (`&`)

```cpp
void inorderHelper(Node* node, vector<int>& result)
//                                         ↑
//                                    Ampersand = reference
```

**❌ Without `&`:**
```cpp
void inorderHelper(Node* node, vector<int> result)  // Pass by VALUE
```
- Creates a COPY of vector for each recursive call
- Changes don't persist
- Result: Empty vector returned

**✅ With `&`:**
```cpp
void inorderHelper(Node* node, vector<int>& result)  // Pass by REFERENCE
```
- All recursive calls work on SAME vector
- Changes persist across calls
- Result: Filled vector returned

**💡 Mnemonic:** *"One vector for all, shared via reference."*

### 2. Base Case is Mandatory

**❌ WRONG:**
```cpp
void inorderHelper(Node* node, vector<int>& result) {
    inorderHelper(node->left, result);   // What if node is nullptr?
    result.push_back(node->data);        // CRASH on nullptr->data!
    inorderHelper(node->right, result);
}
```

**✅ RIGHT:**
```cpp
void inorderHelper(Node* node, vector<int>& result) {
    if (node == nullptr) {  // BASE CASE - guard against nullptr
        return;
    }
    
    inorderHelper(node->left, result);
    result.push_back(node->data);
    inorderHelper(node->right, result);
}
```

**Why needed:** When you reach a leaf and call `helper(node->left)` where left is `nullptr`, you need to stop immediately. Without base case → segfault.

### 3. Empty Tree Check Goes in Public Function

**Public function:**
```cpp
vector<int> inorder() {
    if (root == nullptr) {  // ✅ Check ONCE here
        cout << "❌ Empty tree!" << endl;
        return {};
    }
    vector<int> result;
    inorderHelper(root, result);
    return result;
}
```

**Helper function:**
```cpp
void inorderHelper(Node* node, vector<int>& result) {
    if (node == nullptr) {  // ✅ This handles DEAD ENDS, not empty tree
        return;
    }
    // ...
}
```

**Why separate?**
- Public function: ONE check for empty tree (user-facing)
- Helper: MANY checks for dead ends during traversal (internal)
- Don't spam "Empty tree!" message at every leaf!

---

## 💡 Why Each Traversal Matters

### In-Order: Most Common for BST

**Output:** Sorted values (ascending order)

**Why it works:**
- Visit LEFT subtree first (all smaller values)
- Print ROOT (current value)
- Visit RIGHT subtree last (all larger values)
- Result: Ascending order!

**Use cases:**
- Verify BST property (should be sorted)
- Get sorted list from BST
- Print BST in order

### Pre-Order: Root First

**Output:** Root before its children

**Why useful:**
- Visiting/processing parents before children
- Copying a tree (create parent before children)
- Serializing tree to string
- Prefix expression evaluation

**Example use case:**
```cpp
// Copy tree structure
Node* copyTree(Node* node) {
    if (node == nullptr) return nullptr;
    
    Node* newNode = new Node(node->data);  // Process root FIRST
    newNode->left = copyTree(node->left);   // Then left
    newNode->right = copyTree(node->right); // Then right
    return newNode;
}
```

### Post-Order: Children First

**Output:** Root after its children

**Why useful:**
- Processing children before parent
- Deleting tree (delete children before parent)
- Postfix expression evaluation
- Computing values bottom-up

**Example use case:**
```cpp
// Delete tree (like destructor)
void destroyTree(Node* node) {
    if (node == nullptr) return;
    
    destroyTree(node->left);   // Delete left subtree first
    destroyTree(node->right);  // Delete right subtree
    delete node;               // THEN delete root (post-order!)
}
```

---

## ⚠️ Common Pitfalls & Solutions

### Pitfall 1: Forgetting Base Case

**Symptom:** Segmentation fault, program crashes

**❌ Cause:**
```cpp
void inorderHelper(Node* node, vector<int>& result) {
    // No base case!
    inorderHelper(node->left, result);   // Crashes when node is nullptr
    result.push_back(node->data);
}
```

**✅ Fix:** Always add base case first
```cpp
if (node == nullptr) return;  // Add this FIRST
```

### Pitfall 2: Not Using Reference (`&`) for Vector

**Symptom:** Empty vector returned, no values collected

**❌ Cause:**
```cpp
void inorderHelper(Node* node, vector<int> result)  // Missing &
```

**✅ Fix:** Add ampersand
```cpp
void inorderHelper(Node* node, vector<int>& result)  // Reference
```

### Pitfall 3: Printing "Empty Tree" in Helper

**❌ WRONG:**
```cpp
void inorderHelper(Node* node, vector<int>& result) {
    if (node == nullptr) {
        cout << "Empty tree!" << endl;  // Prints at EVERY leaf!
        return;
    }
    // ...
}
```

**Symptom:** "Empty tree!" message printed multiple times

**✅ RIGHT:**
```cpp
void inorderHelper(Node* node, vector<int>& result) {
    if (node == nullptr) {
        return;  // Silent return - hitting nullptr is normal
    }
    // ...
}
```

**Check for empty tree in PUBLIC function, not helper.**

### Pitfall 4: Wrong Order of Operations

**Example:** Trying to do post-order but wrote in-order

**❌ WRONG:**
```cpp
void postorderHelper(Node* node, vector<int>& result) {
    if (node == nullptr) return;
    
    postorderHelper(node->left, result);
    result.push_back(node->data);        // Printing in middle = in-order!
    postorderHelper(node->right, result);
}
```

**✅ Fix:** Move print to end
```cpp
void postorderHelper(Node* node, vector<int>& result) {
    if (node == nullptr) return;
    
    postorderHelper(node->left, result);
    postorderHelper(node->right, result);
    result.push_back(node->data);        // Print LAST = post-order
}
```

**💡 Mnemonic:**
- **In**-order = **In** the middle
- **Pre**-order = **Pre**fix = before (first)
- **Post**-order = **Post**fix = after (last)

### Pitfall 5: C++11 Flag Not Set

**Symptom:**
```
error: non-aggregate type 'vector<int>' cannot be initialized with an initializer list
return {};
```

**✅ Fix:** Compile with C++11 flag
```bash
g++ -std=c++11 inorder.cpp -o inorder
```

**Or change code:**
```cpp
return vector<int>();  // Instead of return {};
```

---

## 🆚 Comparison Table

| Traversal | Order | When Root Visited | Output for BST | Key Use Case |
|-----------|-------|-------------------|----------------|--------------|
| **In-order** | L → R → R | Middle (between children) | **Sorted** | Get sorted values |
| **Pre-order** | R → L → R | First (before children) | Root first | Copy tree |
| **Post-order** | L → R → R | Last (after children) | Root last | Delete tree |

> **Remember:** Only in-order gives sorted output for BST!

---

## 📊 Time & Space Complexity

**All three traversals:**

| Metric | Complexity | Why |
|--------|------------|-----|
| **Time** | O(n) | Visit each node exactly once |
| **Space (worst)** | O(n) | Call stack depth = tree height (n if unbalanced) |
| **Space (average)** | O(log n) | Call stack depth = tree height (log n if balanced) |
| **Vector space** | O(n) | Store all n values |

**Total space:** O(n) for vector + O(height) for call stack

---

## 🔄 Connection to Other Topics

### Recursion (Sessions 3-4)

**Everything from recursion transferred:**
- Base case (nullptr check)
- Recursive case (explore left, explore right)
- Trust the recursion (helper handles subtrees)
- Call stack (LIFO execution)

**Traversals ARE recursive tree exploration** - same patterns you already know.

### Stack (Session 7)

**The call stack during traversal IS a stack (LIFO):**

**In-order trace for node 3:**
```
1. inorder(3) pushed onto stack
2. inorder(1) pushed onto stack
3. inorder(1) finishes, pops off ← LAST in, FIRST out
4. Print 3
5. inorder(4) pushed onto stack
6. inorder(4) finishes, pops off
7. inorder(3) finishes, pops off ← FIRST in, LAST out
```

**This is why recursive calls "stack up" and return in reverse order.**

### Future: BFS vs DFS

**DFS (what you just learned):** Go deep first (use call stack)  
**BFS (coming later):** Go level by level (use queue)

**DFS is what ALL these traversals are** - different orders, but all depth-first.

---

## 🎓 Learning Reflection

### What Made It Click

**1. Pattern Recognition**
> *"These 3 ways of traversal are pretty much the exact same. The only difference is when do you print vs when do you traverse."*

**This was the key insight.** Once you saw the pattern, all three were trivial.

**2. One Mistake, Quick Correction**
- Forgot base case in inorder → segfault
- Immediately recognized the problem
- Added `if (node == nullptr) return;`
- Never made that mistake again in preorder or postorder

**This is learning through debugging** - make mistake, understand why, never repeat.

**3. Implementation Speed**
- Inorder: ~30 min (including fixing base case bug)
- Preorder: ~20 min (no mistakes, clean implementation)
- Postorder: ~25 min (implemented via deductive reasoning before coding)

**Getting faster = pattern becoming automatic.**

### Key Breakthroughs

**Breakthrough 1:** *"It's just the order in which you visit vs print!"*  
Abstracted the pattern before coding.

**Breakthrough 2:** *"Only in-order gives sorted output."*  
Understood WHY (visits left first, then root, then right).

**Breakthrough 3:** *"The base case handles dead ends, not empty tree."*  
Separated concerns: public function checks empty tree, helper handles nullptr during traversal.

### Time Investment

**Total: ~1 hour**
- Understanding concept: ~10 min
- Inorder implementation: ~30 min (including debugging)
- Preorder implementation: ~20 min
- Postorder implementation: ~20 min

**Why so fast?**
- Pattern is simple (only difference is print timing)
- BST core operations already mastered
- Recursion deeply understood from earlier sessions
- Self-corrected mistakes quickly

---

## 🚀 Next Steps

**After mastering all three traversals:**

1. **Practice LeetCode problems:**
   - Binary Tree Inorder Traversal (LC #94)
   - Binary Tree Preorder Traversal (LC #144)
   - Binary Tree Postorder Traversal (LC #145)
   - Validate Binary Search Tree (LC #98) - uses in-order
   
2. **Learn iterative versions** (without recursion)
   - Uses explicit stack instead of call stack
   - More complex but O(1) space if done right

3. **Learn BFS (Level-Order Traversal)**
   - Uses queue instead of recursion
   - Visits tree level by level

4. **Apply traversals to problems:**
   - Serialize/deserialize tree (pre-order)
   - Check if tree is balanced (post-order)
   - Find kth smallest element (in-order)

---

## 💭 Final Thoughts

Tree traversals seem intimidating at first, but they're actually **the simplest recursive patterns**.

### Key Insight

If you understand recursion, you understand traversals. The ONLY variable is when you print.

### The Pattern

```
1. Base case (always: if nullptr return)
2. Do something with node (print/process)
3. Recurse left
4. Recurse right
```

**Just rearrange steps 2, 3, 4 and you get different traversals.**

### The "Carpenter Test" Progress

1. ✅ **Verbal explanation** - Can explain all three orders and when each is used
2. ✅ **Visual modeling** - Can trace execution and predict output
3. ✅ **Implementation fluency** - All three implemented cleanly from scratch
4. ✅ **Pattern recognition** - Ready for traversal-based LeetCode problems

### What Makes This Knowledge Stick

- Simple pattern with clear differences
- Immediate visual feedback (see the different outputs)
- Connected to recursion (foundation already solid)
- Practical use cases (sorted output, copy tree, delete tree)
- Fast implementation (built muscle memory)

---

## 📚 Quick Reference

### The Three Patterns Side-by-Side

```cpp
// IN-ORDER (Left → Root → Right)
void inorderHelper(Node* node, vector<int>& result) {
    if (node == nullptr) return;
    inorderHelper(node->left, result);
    result.push_back(node->data);        // ← MIDDLE
    inorderHelper(node->right, result);
}

// PRE-ORDER (Root → Left → Right)
void preorderHelper(Node* node, vector<int>& result) {
    if (node == nullptr) return;
    result.push_back(node->data);        // ← FIRST
    preorderHelper(node->left, result);
    preorderHelper(node->right, result);
}

// POST-ORDER (Left → Right → Root)
void postorderHelper(Node* node, vector<int>& result) {
    if (node == nullptr) return;
    postorderHelper(node->left, result);
    postorderHelper(node->right, result);
    result.push_back(node->data);        // ← LAST
}
```

### Mnemonic Table

| Name | Print Timing | Mnemonic |
|------|--------------|----------|
| **In-order** | Middle | **In** the middle of children |
| **Pre-order** | First | **Pre**fix = before |
| **Post-order** | Last | **Post**fix = after |

### Expected Output Reference

**Tree:**
```
    5
   / \
  3   7
 / \
1   4
```

| Traversal | Output | Property |
|-----------|--------|----------|
| In-order | `1, 3, 4, 5, 7` | ✅ Sorted |
| Pre-order | `5, 3, 1, 4, 7` | Root first (5) |
| Post-order | `1, 4, 3, 7, 5` | Root last (5) |

---


**Learning documented by Aaradhya Poudyal**  
*Session date: January 10, 2026*  
*Total time invested: ~1 hour*  
*Status: ✅ Complete - All three DFS traversals mastered*

