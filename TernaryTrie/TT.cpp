/*
* Author: Mehmet KOC
* GitID: mehmettkocc
* Description: the implementation for TT class which represents a ternary trie
* with nodes from TTNode class
*/

#include "TT.hpp"

//TT implementation
void TT::insertRest(const string& remainingStr, TTNode* &restRoot) {
   int totalCount = remainingStr.length();
   restRoot = new TTNode(remainingStr[0], 0, 0, 0, false);
   //avoid changing restRoot (CAUTION: pointer passed by ref)
   nodeSize++;
   TTNode* curr = restRoot;
   for (int i = 1; i < totalCount; i++) {
      curr->middle = new TTNode(remainingStr[i], 0, 0, 0, false);
      nodeSize++;
      curr = curr->middle;
   }
   //when all letters are inserted, make the end bit of last letter true
   curr->end = true;
   wordSize++;
}

void TT::deleteAllNodes(TTNode* currRoot){
   if (currRoot) {
      //clear all subtries
      deleteAllNodes(currRoot->left);
      deleteAllNodes(currRoot->right);
      deleteAllNodes(currRoot->middle);
      //when recursion comes back, delete currRoot as well
      delete currRoot;
   }
}

void TT::getAllDepths(TTNode* curr, uint* &cumDepth){
   if (curr) {
      getAllDepths(curr->left, cumDepth);
      getAllDepths(curr->right, cumDepth);
      getAllDepths(curr->middle, cumDepth);
      (*cumDepth) += curr->depth;
   }
}


/*
* --------------------------------------------------------------------------
* PUBLIC
* --------------------------------------------------------------------------
*/

bool TT::find(const string& word) const {
   int bitCount = 0, totalCount = word.length();
   char currChar = word[0];
   //start from the root
   TTNode* curr = root;
   //search until a null TTNode is reached
   while (curr) {
      //if LESS
      if (currChar < curr->data)
         curr = curr->left;
      //if GREATER
      else if (curr->data < currChar)
         curr = curr->right;
      //if EQUAL
      else {
         bitCount++;
         if (bitCount == totalCount) {
            //make sure end bit is true
            if (curr->end)
               return true;
            else
               return false;
         }
         curr = curr->middle;
         currChar = word[bitCount];
      }
   }
   //a null node is reached -> NOT FOUND
   return false;
}

pair<bool, bool> TT::findPrefix(const TTNode* startNode, const string& subWord,
   TTNode* &nextNode) const {
      int bitCount = 0, totalCount = subWord.length();
      char currChar = subWord[0];
      //start from 'sNode' and search until a null TTNode is reached
      while (startNode) {
         //if LESS
         if (currChar < startNode->data)
            startNode = startNode->left;
         //if GREATER
         else if (startNode->data < currChar)
            startNode = startNode->right;
         //if EQUAL
         else {
            bitCount++;
            if (bitCount == totalCount) {
               //check the end bit
               if (startNode->end) {
                  //prefix found and also a word
                  nextNode = startNode->middle;
                  return pair<bool, bool> (true, true);
               }
               else {
                  //prefix found, but not a word
                  nextNode = startNode->middle;
                  return pair<bool, bool> (true, false);
               }
            }
            startNode = startNode->middle;
            currChar = subWord[bitCount];
         }
      }
      //a null node is reached -> NOT FOUND
      nextNode = 0;
      return pair<bool, bool> (false, false);
}

bool TT::insert(const string& word) {
   int bitCount = 0, totalCount = word.length();
   char currChar = word[0];
   //start searching from the root for a place to insert 'word' or its substr
   TTNode* curr = root;
   //if there is no root, create it
   if (!root) {
      insertRest(word, root);
      return true;
   }
   while (1) {
      //if LESS
      if (currChar < curr->data) {
         if (curr->left)
            curr = curr->left;
         else {
            insertRest(word.substr(bitCount), curr->left);
            return true;
         }
      }

      //if GREATER
      else if (curr->data < currChar) {
         if (curr->right)
            curr = curr->right;
         else {
            insertRest(word.substr(bitCount), curr->right);
            return true;
         }
      }

      //if EQUAL
      else {
         bitCount++;
         if (bitCount == totalCount) {
            //check if already in the trie
            if (curr->end)
               return false;
            else {
               curr->end = true;
			   wordSize++;
               return true;
            }
         }
         //bitCount < totalCount
         //still there are letters to search
         if (curr->middle)
            curr = curr->middle;
         else {
            insertRest(word.substr(bitCount), curr->middle);
            return true;
         }
         currChar = word[bitCount];
      }
   }
   //while loop always returns either true or false
}

void TT::clearTrie() {
   if (root) {
      deleteAllNodes(root);
   }
   root = 0;
   //everything in the trie is deleted
   nodeSize = wordSize = 0;
}

const TTNode* TT::getRoot() const {
   const TTNode* ptrToRoot = root;
   return ptrToRoot;
}

int TT::getNodeSize() const {
   return nodeSize;
}

int TT::getWordSize() const {
   return wordSize;
}

double TT::getAverageDepth() const {
   if (!root)
      return 0;
   uint cumDepth = 0;
   uint* cumDepthPtr = &cumDepth;
   getAllDepths(root, cumDepthPtr);
   return ((double) cumDepth) / nodeSize;
}

TT::~TT() {
   //remove all TTNode elements in the trie
   clearTrie();
}

