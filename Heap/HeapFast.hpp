/*
* Author: Mehmet KOC
* GitID: mehmettkocc
* Date: 01/14/14
* Description: The interface for HeapFast class which uses array representation
* and assumes a maximum number of elements in the heap
*/

#include <iostream>

#define maxHeapSize 1000

using namespace std;

typedef unsigned int uint;

template<typename T>
class HeapFast {
private:
   //The array allocated for the heap
   T allData[maxHeapSize-1];
   //The variable that keeps track of the current size of the heap
   uint currentSize;

   /*
   * Get the index of parent of a node. Returns -1 if the node passed is root
   */
   int getPInd(uint ind);

   /*
   * Get the index of left child of a node. Returns -1 if there is no left child
   */
   int getLCInd(uint ind);

   /*
   * Get the ind of right child of a node. Returns -1 if there is no right child
   */
   int getRCInd(uint ind);

   /*
   * Bubble up the elements at index ind until heap ordering is restored again
   */
   void bubbleUp(uint ind);

   /*
   * Bubble down the elements at index ind until heap ordering is restored again
   */
   void bubbleDown(uint ind);

   /*
   * Return the minimum value of two children and the index for that child.
   * Returns (-1, -1) if the node has no children
   */
   pair<int, int> getMinChild(uint ind);


   /*--------------------------------------------------------------------------
   * PUBLIC
   --------------------------------------------------------------------------*/

public:
   /*
   * The constructor1 for the heap
   */
   HeapFast() : currentSize(0) {}
   
   /*
   * Overloading the constructor1. This constructor creates the heap and put 
   * the elements passed in the heap
   */
   //HeapFast(T)

   /*
   * Populate the heap with the elements given
   */
   //bool makeHeap

   /*
   * Insert the element given into the heap. If currentSize exceeds maxHeapSize,
   * it returns false
   */
   bool insert(const T& data);

   /*
   * Return the min element in the heap without removing
   */
   T peekMin() const;

   /*
   * Remove the min element without returning
   */
   void popMin();

   /*
   * Return the number of spots left in the heap
   */
   uint returnRemaining() const;

   /*
   * The tester for HeapFast class
   */
   static void __HeapFastTester();

   
};