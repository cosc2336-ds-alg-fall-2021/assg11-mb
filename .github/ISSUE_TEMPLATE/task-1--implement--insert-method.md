---
name: 'Task 1: Implement `LBinaryTree` `insert()` Method'
about: Task 1 for Students
title: 'Task 1: Implement `LBinaryTree` `insert()` Method'
labels: enhancement, good first issue
assignees: ''

---

**Description**

For task 1 implement the missing `insert()` API method.  This method
will insert a new key/value pair into the binary tree.  You actually need
to add two methods for this task, a public `insert()` method, and a 
private `insert()` method which is the recursive method that does the
actual work of inserting the key/value pair.


**Suggested Solution**

The general recursive algorithm that you need to implement in the
private `insert()` method is as follows:

**Base Case**: If the node we are evaluating is the `nullptr`, create
a new node and return this new node.  The `BinaryTreeNode` class is a
full class this time, and it has defined constructors and helper
function in order to use it.  So for example, when creating a new
node, you should use the standard constructor, and do something like
the following:

```c++
BinaryTreeNode<Key, Value>* newNode = new BinaryTreeNode<Key, Value>(key, value);
```

and return this `newNode` as the result of the base case of the `insert()`.

**General Case**:  If the node is not null, you need to perform a recursive search.

1. If `key <= node->getKey()` then you need to search in the left
   subtree.
2. Otherwise the `key` should be greater than current nodes `key` so
   you need to search to the right subtree.
3. in both cases you should return this `node` as the result, since the recursive
   `insert()` function returns a node as the result.

**Additional Requirements**

- You are required to have two member functions named `insert()` relying on function
  overloading and the difference in the function signatures for the C++ compiler to
  tell them apart.
- You are required to make the recursive member function be a `private` function of the
  class, it is not usable by code/users outside of this class.
