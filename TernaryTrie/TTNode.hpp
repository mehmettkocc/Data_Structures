/*
* Author: Mehmet KOC
* Date: 12/4/13
* GitID: mehmettkocc
* Description: The interface for TTNode class which represents one node a 
* ternary trie used to store strings
*/

#ifndef TTNODE_H
#define TTNODE_H

#include <string>

using namespace std;

typedef unsigned int uint;
typedef unsigned char byte;

/*
* The class for ternary trie node
* The class for ternary trie included at the bottom
*/
class TTNode {
public:
   //data (lowercase char)
   byte data;
   //pointers to left, right, middle children
   TTNode* left;
   TTNode* right;
   TTNode* middle;
   //flag to indicate if the node is the last letter of a word in the lexicon
   bool end;
   //depth of the node
   uint depth;

   /*
   * The constructor for TTNode
   * All public fields are set in the constructor
   */
   TTNode(byte d, TTNode* L, TTNode* R, TTNode* M, bool e, uint dep) :
      data(d), left(L), right(R), middle(M), end(e), depth(dep) {}
};

#endif //TTNODE_H