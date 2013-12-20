/*
* Author: Mehmet KOC
* GitID: mehmettkocc
* Date: 10/10/13
* Description: The implementation for the template node class in a binary
* search tree (BST)
*/

#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include <iostream>
#include <iomanip>


template<typename Data>
class BSTNode {

public:

   /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
   BSTNode(const Data & d, const int& p = -1) : data(d), priority(p) {
      left = right = parent = 0;
   }

   BSTNode<Data>* left;
   BSTNode<Data>* right;
   BSTNode<Data>* parent;
   Data const data;   // the const Data in this node.
   int const priority;

   /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */ // TODO
   BSTNode<Data>* successor() {
      //if (this) has a right subtree, go to its leftmost element
      BSTNode<Data>* nextNode;
      if (this->right) {
         nextNode = this->right;
         while (nextNode->left != 0)
            nextNode = nextNode->left;
         return nextNode;
      }
      /** else got to its parent and check if (this) is in the left or
      *  right subtree of its parent
      */
      nextNode = this;
      while (nextNode->parent) {
         //if nextNode is its parent's left child, return nextNode->parent		
         if (nextNode == nextNode->parent->left)
            return nextNode->parent;
         //else nextNode is the right child of its parent
         else
            //go to parent and continue until nextNode is the left child 
            nextNode = nextNode->parent;
      }
      //if no element returned yet, no successor found, return 0
      return 0;

   }

};

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
   stm << '[';
   stm << std::setw(10) << &n;                 // address of the BSTNode
   stm << "; p:" << std::setw(10) << n.parent; // address of its parent
   stm << "; l:" << std::setw(10) << n.left;   // address of its left child
   stm << "; r:" << std::setw(10) << n.right;  // address of its right child
   stm << "; d:" << n.data;                    // its data field
   stm << ']';
   return stm;
}

#endif // BSTNODE_HPP
