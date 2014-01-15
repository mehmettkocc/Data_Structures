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
   T allData[maxHeapSize];
   //The variable that keeps track of the current size of the heap
   uint currentSize;

   /*
   * Get the index of parent of a node
   */
   static uint getPInd(uint ind);

   /*
   * Get the index of left child of a node
   */
   static uint getLCInd(uint ind);

   /*
   * Get the index of right child of a node
   */
   static uint getRCInd(uint ind);

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
   * Return the min element in the heap with removing
   */
   T popMin();

   /*
   * Return the number of spots left in the heap
   */
   uint returnRemaining() const;

   /*
   * The tester for HeapFast class
   */
   static void HeapFastTester(){

   }

   
};