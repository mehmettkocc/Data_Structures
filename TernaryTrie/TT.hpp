/*
* Author: Mehmet KOC
* Date: 12/4/13
* GitID: mehmettkocc
* Description: The interface for TT class which represents a ternary trie 
* with nodes from TTNode class
*/

#ifndef TT_H
#define TT_H

#include <string>
#include "TTNode.hpp"

/*
* Ternary trie class
*/
class TT {
private:
   //the pointer to the root of the trie
   TTNode* root;
   //number of word in the trie
   uint wordSize;
   //the number of nodes in the trie
   uint nodeSize;

   /*
   * The method inserts the rest of the string in insertion operation when
   * a null TTNode* is reached. Called from the public insert(...) method
   */
   void insertRest(const string& remainingStr, TTNode* &restRoot);

   /*
   * Deletes all TTNodes in the trie starting from currRoot
   */
   static void deleteAllNodes(TTNode* currRoot);

   /*
   * Traverse the trie to get the cumulative depth of the trie nodes
   */
   static void getAllDepths(TTNode* curr, uint* &cumDepth);

   /*
   * --------------------------------------------------------------------------
   * PUBLIC
   * --------------------------------------------------------------------------
   */

public:
   /*
   * The constructor for ternary trie
   * root set to NULL and trie is initially empty
   */
   TT() : root(0), wordSize(0), nodeSize(0) {}

   /*
   * Searches for 'word' in the trie
   * Return true if 'word' is found
   */
   bool find(const string& word) const;

   /*
   * Search for 'subWord' starting from 'startNode'. Updates pointer with
   * the pointer to the node past 'subword' if found, otherwise null. Returns
   * a pair of two bool values: first one indicates if the prefix is found and
   * second one indicates if a valid word in the lexicon has been found
   */
   pair<bool, bool> findPrefix(const TTNode* startNode, const string& subWord,
      TTNode* &nextNode) const;

   /*
   * Inserts 'word' in the trie
   * Returns false if 'word' is already in the trie
   */
   bool insert(const string& word);

   /*
   * Clears the trie from all TTNodes and resets root to null
   */
   void clearTrie();

   /*
   * Get a pointer to the root of the trie that cannot be used to change it
   */
   const TTNode* getRoot() const;

   /*
   * Get the nodeSize of the trie (number of TTNodes)
   */
   int getNodeSize() const;

   /*
   * Get the wordSize of the trie (number of words)
   */
   int getWordSize() const;

   /*
   * Returns the average depth of the nodes in the trie. If root=0, then it
   * returns 0 as avg depth
   */
   double getAverageDepth() const;

   /*
   * The destructor for ternary trie
   */
   ~TT();

};


#endif //TT_H