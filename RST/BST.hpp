/*
* Author: Mehmet KOC
* GitID: mehmettkocc
* Date: 10/10/13
* Description: The implementation for the template class of BST which holds
* objects of BSTNode
*/

#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include "BSTNode.hpp"
#include "BSTIterator.hpp"

template<typename Data>
class BST {

protected:

   /** Pointer to the root of this BST, or 0 if the BST is empty */
   BSTNode<Data>* root;

   /** Number of Data items stored in this BST. */
   unsigned int isize;

public:

   /** define iterator as an aliased typename for BSTIterator<Data>. */
   typedef BSTIterator<Data> iterator;

   /** Default constructor.
   Initialize an empty BST.
   */
   BST() : root(0), isize(0) {  }


   /** Default destructor.
   Delete every node in this BST.
   */
   virtual ~BST() {
      deleteAll(root);
      root = 0;
   }

   //clear BST tree and delete all BST nodes
   virtual bool clear() {
      try {
         deleteAll(root);
         root = 0;
         isize = 0;
         return true;
      }
      catch (...) {
         return false;
      }
   }

   /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items.
   */
   virtual bool insert(const Data& item) {
      //if tree is empty, create the node with data=item and make it root
      if (!root){
         root = new BSTNode<Data>(item);
         isize++;
         return true;
      }
      /** if non-empty, go deeper until a leaf node is reached (return true) or
      *  a node with data=item is found (return false)
      */
      else {
         BSTNode<Data>* currNode = root;
         //iterate and go deeper until a node with data=item is found
         while (true) {
            //if item < currNode->data, go to the left subtree
            if (item < currNode->data) {
               //go deeper or insert when a leaf node is reached
               if (!currNode->left) {
                  currNode->left = new BSTNode<Data>(item);
                  currNode->left->parent = currNode;
                  isize++;
                  return true;
               }
               else
                  currNode = currNode->left;
            }
            //if item > currNode->data, go to the right subtree
            else if (currNode->data < item) {
               //go deeper or insert when a leaf node is reached
               if (!currNode->right) {
                  currNode->right = new BSTNode<Data>(item);
                  currNode->right->parent = currNode;
                  isize++;
                  return true;
               }
               else
                  currNode = currNode->right;
            }
            //a node with 'item' already exists
            else
               return false;
         }         
      }
   }


   /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items.
   */
   iterator find(const Data& item) const {
      /** if tree is empty, return iterator with pointing to null
      *  else look for the node with data=item
      */
      if (!root)
         return typename BST<Data>::iterator(0);
      else {
         //get-only pointer to the root
         BSTNode<Data>* currNode = root;
         /** iterate till currNode->data==item and
         *  go deeper at each step either in the left or right subtree
         *  by making comparisons
         */
         while (true) {
            if (item < currNode->data) {
               if (!currNode->left)
                  return typename BST<Data>::iterator(0);
               else
                  currNode = currNode->left;
            }
            else if (currNode->data < item) {
               if (!currNode->right)
                  return typename BST<Data>::iterator(0);
               else
                  currNode = currNode->right;
            }
            //if currNode contains 'item', return an iterator to it
            else
               return BSTIterator<Data>(currNode);
         }        
      }
   }


   /** Return the number of items currently in the BST.
   */
   unsigned int size() const {
      return isize;
   }

   /** Return true if the BST is empty, else false.
   */
   bool empty() const {
      return (isize == 0);
   }

   /** Return an iterator pointing to the first item in the BST.
   */
   iterator begin() const {
      return typename BST<Data>::iterator(first(root));
   }

   /** Return an iterator pointing past the last item in the BST.
   */
   iterator end() const {
      return typename BST<Data>::iterator(0);
   }

   /** Perform an inorder traversal of this BST.
   */
   void inorder() const {
      inorder(root);
   }


private:

   /** Recursive inorder traversal 'helper' function */
   void inorder(BSTNode<Data>* n) const {
      if (!n) 
         return;
      inorder(n->left);
      std::cout << *n << std::endl;
      inorder(n->right);
   }

   static BSTNode<Data>* first(BSTNode<Data>* root) {
      if (!root) 
         return 0;
      while (root->left) 
         root = root->left;
      return root;
   }

   // do a postorder traversal, deleting nodes
   static void deleteAll(BSTNode<Data>* n) {
      if (!n) 
         return;
      deleteAll(n->left);
      deleteAll(n->right);
      delete n;
   }

};


#endif //BST_HPP
