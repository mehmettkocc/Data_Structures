/*
* Author: Mehmet KOC
* GitID: mehmettkocc
* Date: 10/21/13
* Description: The implementation for RST class which inherits from BST class
*/

#ifndef RST_HPP
#define RST_HPP

#include <iostream>
#include <stdlib.h>
#include "BST.hpp"

template <typename Data>
class RST : public BST<Data> {

public:
   //redefine insert method for subclass RST
   virtual bool insert(const Data& item) {
      // pointer to new prospective node
      BSTNode<Data>* newNode = 0;

      //if tree is empty, create the node with data=item and make it root
      if (!BST<Data>::root) {
         BST<Data>::root = newNode = new BSTNode<Data>(item, rand());
         BST<Data>::isize++;
         return true;
      }
      /** if non-empty, go deeper until a leaf node is reached
      * (return true) or
      *  a node with data=item is found (return false)
      */
      else {
         BSTNode<Data>* currNode = BST<Data>::root;
         //iterate and go deeper until a node with data=item is found
         while (true) {
            //if item < currNode->data, go to the left subtree
            if (item < currNode->data) {
               //go deeper or insert when a leaf node is reached
               if (currNode->left)
                  currNode = currNode->left;
               else {
                  currNode->left = newNode = new BSTNode<Data>(item, rand());
                  currNode->left->parent = currNode;
                  BST<Data>::isize++;
                  while (newNode->parent->priority < newNode->priority) {
                     if (newNode == newNode->parent->left)
                        rightSingleRotation(newNode->parent);
                     else
                        leftSingleRotation(newNode->parent);
                     if (!newNode->parent) {
                        BST<Data>::root = newNode;
                        break;
                     }
                  }
                  return true;
               }

            }
            //if item > currNode->data, go to the right subtree
            else if (currNode->data < item) {
               //go deeper or insert when a leaf node is reached
               if (currNode->right)
                  currNode = currNode->right;
               else {
                  currNode->right = newNode = new BSTNode<Data>(item, rand());
                  currNode->right->parent = currNode;
                  BST<Data>::isize++;
                  while (newNode->parent->priority < newNode->priority) {
                     if (newNode == newNode->parent->left)
                        rightSingleRotation(newNode->parent);
                     else
                        leftSingleRotation(newNode->parent);
                     if (!newNode->parent) {
                        BST<Data>::root = newNode;
                        break;
                     }
                  }
                  return true;
               }
            }
            else
               return false;
         }
      }
   }

private:
   //Make a single right AVL rotation on a disconnected tree...
   //with root=oldRoot and return the new root=newRoot
   BSTNode<Data>* rightSingleRotation(BSTNode<Data>* oldRoot) {
      BSTNode<Data>* newRoot = oldRoot->left;
      oldRoot->left = newRoot->right;
      newRoot->right = oldRoot;
      if (oldRoot->parent) {
         if (oldRoot == oldRoot->parent->left)
            oldRoot->parent->left = newRoot;
         else
            oldRoot->parent->right = newRoot;
      }
      newRoot->parent = oldRoot->parent;
      oldRoot->parent = newRoot;
      if (oldRoot->left)
         oldRoot->left->parent = oldRoot;

      return newRoot;
   }

   //Make a single left AVL rotation on a disconnected tree...
   //with root=oldRoot and return the new root=newRoot
   BSTNode<Data>* leftSingleRotation(BSTNode<Data>* oldRoot) {
      BSTNode<Data>* newRoot = oldRoot->right;
      oldRoot->right = newRoot->left;
      newRoot->left = oldRoot;
      if (oldRoot->parent) {
         if (oldRoot == oldRoot->parent->left)
            oldRoot->parent->left = newRoot;
         else
            oldRoot->parent->right = newRoot;
      }
      newRoot->parent = oldRoot->parent;
      oldRoot->parent = newRoot;
      if (oldRoot->right)
         oldRoot->right->parent = oldRoot;

      return newRoot;
   }

};

#endif //RST_HPP
