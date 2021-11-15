/** @file LBinaryTree.cpp
 * @brief Concrete link listed based implementation of BinaryTree ADT.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Binarytrees
 * @date   June 1, 2021
 *
 * Implement the Binarytree abstraction using a pointer based set of
 * nodes of dynamically allocated node items.  The dynamic node based
 * implementation creates new nodes dynamically when items are inserted
 * into the tree, and deletes these nodes when the key/value pair is deleted
 * from the tree.  We use a binary search tree.  We support nodes with
 * key/value pairs.  The binary tree is organized by key values.  The
 * general rule is that keys must have an order defined by operator<().
 * When a key/value pair is inserted in tree, it will go to the left subtree
 * of any existing node where the key is less than ordering, and will got
 * to the right subtree where the key is greater than ordering.  Because
 * of the tree structure, assuming the tree does not become too balanced,
 * all operations such as search, insertion and removal should be O(n log_2 n)
 * in performance.
 */
#include "LBinaryTree.hpp"
#include "BinaryTreeException.hpp"
#include "Employee.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/**
 * @brief Default constructor
 *
 * Construct an initially empty binary tree.
 */
template<class Key, class Value>
LBinaryTree<Key, Value>::LBinaryTree()
{
  root = nullptr;
  BinaryTree<Key, Value>::size = 0;
}

/**
 * @brief Array based constructor
 *
 * Construct a tree from parallel lists of given keys and values.  We
 * simply reuse the insert method to iterate through and insert all of
 * the key/value pairs.  Key/value pairs are inserted into the tree in
 * the order they are passed in the arrays.  This constructor assumes
 * the arrays are parallel arrays, e.g. they are of the same size and
 * each indexed element corresponds to a key/value pair.
 *
 * @param size The size of the parallel input arrays of keys and values
 * @param keys An array of Key types to be inserted into newly constructed tree.
 * @param values An array of Value types to be inserted into newly
 *   constructed tree.
 */
template<class Key, class Value>
LBinaryTree<Key, Value>::LBinaryTree(int size, const Key keys[], const Value values[])
{
  // initialze the tree so it is initially empty
  root = nullptr;
  BinaryTree<Key, Value>::size = 0;

  // iterate through all of the key/value pairs in parallel arrays, inserting
  // them into the tree.
  for (int idx = 0; idx < size; idx++)
  {
    // need to uncomment this after implementing insert so that array
    // based constructor will now work
    insert(keys[idx], values[idx]);
  }
}

/**
 * @brief Class destructor
 *
 * Destroy the dynamically allocated nodes of this tree when the
 * instance object is going out of scope.  We (re)use the clear()
 * method here.
 */
template<class Key, class Value>
LBinaryTree<Key, Value>::~LBinaryTree()
{
  clear();
}

/**
 * @brief LBinaryTree to string
 *
 * Create a string representation of this tree.  This is the
 * public function, it calls the private recursive overloaded
 * str() to perform most of the work, though it does add in
 * the preamble and size of the tree.
 *
 * @returns string Returns the constructed string of the BinaryTree
 *   contents in ascending sorted order.
 */
template<class Key, class Value>
string LBinaryTree<Key, Value>::str() const
{
  ostringstream out;

  out << "<BinaryTree> size: " << BinaryTree<Key, Value>::size << " values: [ " << str(root) << "]";

  return out.str();
}

/**
 * @brief Clear the tree
 *
 * Clear the tree and return to an empty state.  Make sure we are
 * good managers of memory, and traverse the tree to delete all
 * dynamically allocated nodes currently in this tree.
 */
template<class Key, class Value>
void LBinaryTree<Key, Value>::clear()
{
  // actual work done in overloaded private clear() recursive function
  clear(root);

  // when we are done clearing, ensure tree is back to empty state
  root = nullptr;
  BinaryTree<Key, Value>::size = 0;
}

/**
 * @brief Private LBinaryTree to string
 *
 * This is the recursive private function that does the actual
 * work of creating a string representation of the LBinaryTree.
 * We perform a (recursive) inorder traversal, constructing a
 * string object, to be returned as a result of this function.
 *
 * @param node The BinaryTreeNode we are currently processing.
 *
 * @returns string Returns the constructed string of the BinaryTree
 *   contents in ascending sorted order.
 */
template<class Key, class Value>
string LBinaryTree<Key, Value>::str(BinaryTreeNode<Key, Value>* node) const
{
  // base case, if node is null, just return empty string, which
  // stops the recursing
  if (node == NULL)
  {
    return "";
  }
  // general case, do an inorder traversal and build string
  else
  {
    ostringstream out;

    // do an inorder traversal
    out << str(node->getLeft()) << node->getValue() << " " << str(node->getRight());

    return out.str();
  }
}

/**
 * @brief Private recursive clear tree
 *
 * Clear the tree and return to an empty state.  Make sure we are
 * good managers of memory, and traverse the tree to delete all
 * dynamically allocated nodes currently in this tree.
 *
 * This is the private recursive function that performs the actual
 * work of clearing the tree.  The public clear function simply calls
 * this function for the root of the tree to perform the clear operation
 * recursively.
 */
template<class Key, class Value>
void LBinaryTree<Key, Value>::clear(BinaryTreeNode<Key, Value>* node)
{
  // base case, when node is nullptr we are done clearing in this branch,
  // in which case we have nothing to doo
  if (node == nullptr)
  {
    return;
  }

  // otherwise first recursively clear our left and right subchildren
  clear(node->getLeft());
  clear(node->getRight());

  // now we can free up this node safely
  delete node;
}

/** @brief inserts given Key/Value pair into this tree
 * 
 * This function will add the given Key/Value pair in order to 
 * this tree.
 * 
 * @param key The Key value of the object to be inserted
 * 
 * @param value The value that the Key is associated with
 */
template<class Key, class Value>
void LBinaryTree<Key, Value>::insert(const Key& key, const Value& value)
{
  root = insert(root, key, value);
}

/** @brief private function that does the work of insert()
 *
 * This function will recusively find the correct place the given
 * Key/Value pair needs to be inserted onto this tree.
 *
 * @param root this is the pointer value of the node being compared to the
 *  given Key/Value pair
 *
 * @param key The Key value of the object to be inserted
 *
 * @param value The value that the Key is associated with
 */
template<class Key, class Value>
BinaryTreeNode<Key, Value>* LBinaryTree<Key, Value>::insert(BinaryTreeNode<Key, Value>* root, const Key& key, const Value& value)
{
  if (root == nullptr)
  {
    this->size++;
    return new BinaryTreeNode<Key, Value>(key, value); // make a new Node w/ null branches and return to original tree
  }

  if (key <= root->getKey())
  {
    root->setLeft(insert(root->getLeft(), key, value));
  }
  else
  {
    root->setRight(insert(root->getRight(), key, value));
  }

  return root;
}

/** @brief function will find and return a Value associated with given Key
 *
 * This function will find the given Key-value in this tree, and will return
 * the Value object stored in the Node with the found Key-value. if the Key-value
 * was not found then a BinaryTreeKeyNotFoundException will be thrown.
 *
 * @param key Key value associated with the actual Value to be found
 *
 * @throws BinaryTreeKeyNotFoundException if the given Key was not found
 */
template<class Key, class Value>
Value LBinaryTree<Key, Value>::find(const Key& key) const
{
  return find(root, key)->getValue();
}

/** @brief recusively finds the given key-value in the tree
 * 
 * This function will recursively find the given key-value in this tree.
 * 
 * @param root Node value holding the key-value to be compared
 * 
 * @param key Key-value being searched for
 */
template<class Key, class Value>
BinaryTreeNode<Key, Value>* LBinaryTree<Key, Value>::find(BinaryTreeNode<Key, Value>* root, const Key& key) const
{
  if (root == nullptr)
  {
    ostringstream out;

    out << "BinaryTreeKeyNotFoundException: could not find key-value of: " << key << ", in tree:\n\t" << this->str();

    throw BinaryTreeKeyNotFoundException(out.str());
  }
  else if (root->getKey() == key)
  {
    return root;
  }
  else if (key < root->getKey())
  {
    return find(root->getLeft(), key);
  }
  else
  {
    return find(root->getRight(), key);
  }
}

/**
 * @brief Cause specific instance compilations
 *
 * This is a bit of a kludge, but we can use normal make dependencies
 * and separate compilation by declaring template class
 * LBinaryTree<needed_key_type, needed_value_type> here of any types
 * we are going to be instantianting with the template.
 *
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 * https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
 */
template class LBinaryTree<int, int>;
template class LBinaryTree<string, double>;
