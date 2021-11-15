---
name: 'Task 5: Implement `LBinaryTree` `remove()` Method'
about: Task 5 for Students
title: 'Task 5: Implement `LBinaryTree` `remove()` Method'
labels: enhancement
assignees: ''

---

**Description**

The fifth task is the trickiest task so far, we need to implement the `remove()` binary tree API method so that we can remove nodes from the binary tree structure.  What makes this method difficult is that in some cases, in order to maintain the correct binary tree property and structure, we have to
remove a node and rearrange values in the tree.

This function is similar to the task 1 and 2 functions, it is again really a pair of functions,  a public `remove()` function that is called by users of the `LBinaryTree` to perform actual removes, and a private `remove()` member function that does the real work of removing a value from the tree by recursively searching and modifying the tree.

**Suggested Solution**

The algorithm for `remove()` is a bit tricky.  It is suggested that if you need additional information, you need to read the Shaffer textbook discussion on implementing this method for the binary tree.

The general algorithm for remove is as follows:

**Base Case**: Failed Search

1. First we need to test for a request to delete a `key` that is not in the
   tree.  If the `node` we are currently testing is the `nullptr` this means
   the search failed.  In that case you should throw a
   `BinaryTreeKeyNotFoundException` to inform the caller the expected
   `key` was not in the tree.
   
**General Cases**: Key not yet found, continue searching left or right

2. Otherwise if the `key` we want to remove is less than this current
   `node`s key, call `remove()` recursively on the left subtree.  Again
   `remove()` returns a `node` result, which could be the result of
   deleting a node, so you should assign the return result from the 
   recursive call back to this nodes `left` pointer.
3. Likewise, if the `key` is greater then this nodes key we need to
   search the right subtree.  So call `remove()` recursive on the 
   `right` node, and assign the return result back to the `right` 
   pointer.
   
**General Case**: Key found, this is the node to delete

4. If we checked and the key was not less or greater then this nodes key,
   then we found the key so this is the node to delete.
   a. Make a temporary pointer and point it to this `node`.  This will hold the
      `node` to return, which might be this `node`.
   b. If this node does not have a `left` child subtree, it means this `node` is
      either a leaf node (no children) or it has a right subtree.  In either case we
	  want to set the node to return to be the `right` subtree of this `node` and then
	  delete this `node`.
   c. Else if this node does not have a `right` child, that means it only has a `left` child
      since we just check if it didn't have a `left` child.  In that case, we want to
	  get the `left` subtree and set it as the node to be returned, and then delete
	  this `node`.
   d. Otherwise, we checked and the tree has both a `left` and a `right` subtree.
      This is the difficult case.  When we have both subtrees, we want to find the
	  minimum node in the right subtree, and swap this nodes values with the values of
	  our minimum node.  So first use `findMinimum()` to find the minimum node of the
	  `right` subtree of this node.  Then use the `setKey()` and `setValue()`
	  methods to copy the value from the minimum node into the key and value of this node.
	  Then finally set our right node to the result of calling `deleteMinimum()` on our
	  `right` subtree.  The effect is as if we copied the minimum values in our right
	  subtree (which is the next closest value to this node) and then delete that minimum
	  node in the right subtree.  You should try this out by hand to convince yourself
	  this works correctly to delete the asked for node and maintain the binary
	  search tree structure. **NOTE**: The `deleteMinimum()` function removes the
	  node from the tree, but it should not actually deallocate the memory.  It is
	  better to deallocate the memory in `remove()`.  At this point, after calling
	  `deleteMinimum()` recursively, you should delete the minimum node's allocation
	  using the C++ `delete` command.


**Additional Requirements**

- You are required to have two member functions named `remove()` relying on function
  overloading and the difference in the function signatures for the C++ compiler to
  tell them apart.
- You are required to make the recursive member function be a `private` function of the
  class, it is not usable by code/users outside of this class.
- You are required to reuse your `getMinimum()` and `deleteMinimum()` private helper 
  functions in order to correctly manipulate the tree in the toughest case where the node
  to be removed has both `left` and `right` subtrees.
- You are required to correctly manage tree node memory in this function when removing
  a node.  Nodes are created in the `insert()` function by calling `new` to be inserted
  into the tree.  This function needs to have a single corresponding `delete` of the node
  that is being removed.  `delete` should not be called in the `deleteMinimum()`
  function.  Instead, you first need to call `getMinimum()` to get a pointer to the
  minimum node in the right subtree.  Then after going through the various cases, you
  will end up deleting either this minimum node in the hardest case, or you will delete
  this node, if you are replacing it with a single left or right child subtree.




