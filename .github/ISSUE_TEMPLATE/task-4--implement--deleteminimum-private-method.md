---
name: 'Task 4: Implement `LBinaryTree` private `deleteMinimum()` Method'
about: Task 4 for Students
title: 'Task 4: Implement `LBinaryTree` private `deleteMinimum()` Method'
labels: enhancement
assignees: ''

---

**Description**

The fourth task is to implement another private helper function called `deleteMinimum()`.
This function will also be used by the tricky `remove()` to do its work.  This function
is similar to the previous task `getMinimum()`.  Its purpose is to search from some given
subtree/root for the minimum node, but instead of returning the node it will remove the node
from the tree structure.  This is done by recursively searching down the tree until we get to a
node with no left subtree, then returning the right subtree of this node. 

**Suggested Solution**

The `deleteMinimum()` function has the same signature as `getMinimum()`
it takes a pointer to a node as input and will return a pointer to the node
as its result.  The recursive algorithm for `deleteMinimum()` is as
follows:

**Base Case**: If the node has no left child subtree, it means we have
recursively traversed to the minimum node in the subtree.  In this case,
return the right subtree of this node.  We return the right subtree because
we are going to delete this node, so pointing the parent node to this nodes
right subtree is the correct thing to do to maintain the tree structure.

**General Case**: Otherwise continue searching left.  But unlike for
the `getMinimum()` we need to set our left subtree to what is returned
from calling ourself recursively.  This is because, if the left
subtree is not the node to be deleted it should return itself.  But if
the left node is the node being deleted, it will instead return its
right subtree, which if we set to our new left child will maintain the
tree structure.  Also once this method sets its left pointer to the
return from the recursive call, it should return itself as the result
of the general case.


**Additional Requirements**

- This function must be a private member function.  It is not useful or usable by
  any code outside of the `LBinaryTree` class.


