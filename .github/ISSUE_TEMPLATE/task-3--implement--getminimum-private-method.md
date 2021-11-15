---
name: 'Task 3: Implement `LBinaryTree` private `getMinimum()` Method'
about: Task 3 for Students
title: 'Task 3: Implement `LBinaryTree` private `getMinimum()` Method'
labels: enhancement
assignees: ''

---

**Description**

Implement a private helper function named `getMinimum()`.  This
function will be useful to implement some of the tricky bits of the
`remove()` function in task 5.  This function is probably the simplest
of the ones you are to implement in this assignment.  This function
should search for and return a pointer to the node with the minimum
value from some beginning subtree/root node of the tree.

**Suggested Solution**

The recursive algorithm for `getMinimum()` is fairly simple:

**Base Case**: If the node does not have a left subtree pointer, then just return
this node.

**General Case**: Otherwise the node has a left subtree, so recursive call
`getMinimum()` on the left subtree and return whatever this recursive call returns
as your result.

**Additional Requirements**

- This function must be a private member function.  It is not useful or usable by
  any code outside of the `LBinaryTree` class.

