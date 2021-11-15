---
name: 'Task 2: Implement `LBinaryTree` `find()` Method'
about: Task 2 for Students
title: 'Task 2: Implement `LBinaryTree` `find()` Method'
labels: enhancement
assignees: ''

---

**Description**

Implement the missing `find()` member method for the `LBinaryTree`
class.  This function is similar to the `insert()` function from
task 1.  You will add two methods named `insert()`, a public method
that is called by users of the class, and a private method that is
recursive and does the actual work.  The `find()` method is basically
a search of the binary tree container.  It searches down the left or
right paths based on key comparisons until it either finds the `key`
in the tree and returns the `value` associated with that `key`, or it
fails in the search and throws an exception instead.

**Suggested Solution**

The recursive algorithm for the recursive private `find()` is as
follows:

**Base Case**: If you ever call the `find()` funciton with a `nullptr`
node as the first parameter, this means the search has failed.  In that
case, you should throw a `BinaryTreeKeyNotFoundException` to inform
the caller that the key they were expecting to find was not in the tree.

**General Case 1: key found**:  Otherwise, you should first test for the
case where the search succeeds.  The search succeeds when the key in this
node is the same as the key we were asked to find.  If the keys match, you
should return the `value` from the node where you found the `key`.

**General Case 2: keep searching**: Otherwise the search hasn't failed
yet, and you didn't find what you were looking for in this node.  So
search the left subtree if the key is less than the key of this node,
or search the right subtree if the key is greater.  In both cases you
will be calling the recursive `find()` recursively, and it will return
a result.  You need to return that result of calling `find()`
recursively as your own result.

**Additional Requirements**

- You are required to have two member functions named `find()` relying on function
  overloading and the difference in the function signatures for the C++ compiler to
  tell them apart.
- You are required to make the recursive member function be a `private` function of the
  class, it is not usable by code/users outside of this class.
- You are required to throw the `BinaryTreeKeyNotFoundException` in the case where
  a request is made to find a `key` that is not in the tree.
