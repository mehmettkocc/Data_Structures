/*
* Author: Mehmet KOC
* GitID: mehmettkocc
* Date: 01/14/14
* Description: The implementation for HeapFast class which uses array 
* representation and assumes a maximum number of elements in the heap
*/

#include "HeapFast.hpp"

template <typename T>
int HeapFast<T>::getPInd(uint childInd){
   //check if child is the root
   if (childInd == 0)
      return -1;
   //if not, return 0-based indices
   if (childInd % 2)
      return (childInd - 1) / 2;
   else
      return childInd / 2 - 1;
}

template <typename T>
int HeapFast<T>::getLCInd(uint parentInd){
   //if the corresponding 0-based index is in the heap, return it
   if ((2 * parentInd + 1) <= currentSize)
      return 2 * parentInd + 1;
   else
      return -1;
}

template <typename T>
int HeapFast<T>::getRCInd(uint parentInd){
   //if the corresponding 0-based index is in the heap, return it
   if ((2 * parentInd + 2) <= currentSize)
      return 2 * parentInd + 2;
   else
      return -1;
}

template <typename T>
void HeapFast<T>::bubbleUp(uint ind) {
   //if the node is the root, nowhere to bubble up
   if (ind == 0)
      return;
   int parentInd = getPInd(ind);
   T temp, currentData = allData[ind];
   //bubble up until reaching the root or the heap ordering is restored
   while (parentInd != -1 && allData[parentInd] > currentData) {
      temp = allData[parentInd];
      allData[parentInd] = currentData;
      allData[ind] = temp;
      ind = parentInd;
      parentInd = getPInd(ind);
   }
}

template <typename T>
void HeapFast<T>::bubbleDown(uint ind) {
   pair<int, int> minChildStats = getMinChild(ind);
   T currentData = allData[ind];
   //bubble down until a leaf node is reached or heap ordering is restored
   while (minChildStats.first != -1 && minChildStats.first < currentData) {
      allData[minChildStats.second] = currentData;
      allData[ind] = minChildStats.first;
      ind = minChildStats.second;
      minChildStats = getMinChild(ind);
   }
}

template <typename T>
pair<int, int> HeapFast<T>::getMinChild(uint ind) {
   int LCInd = getLCInd(ind), RCInd = getRCInd(ind);
   if ( LCInd != -1 && RCInd != -1) {
      if (allData[LCInd] < allData[RCInd])
         return pair<int, int>(allData[LCInd], LCInd);
      return pair<int, int>(allData[RCInd], RCInd);
   }
   if (LCInd == -1)
      return pair<int, int>(allData[RCInd], RCInd);
   if (RCInd == -1)
      return pair<int, int>(allData[LCInd], LCInd);
   return pair<int, int>(-1, -1);
}


/*-----------------------------------------------------------------------------
* PUBLIC
-----------------------------------------------------------------------------*/

template <typename T>
uint HeapFast<T>::returnRemaining() const {
   return maxHeapSize - currentSize;
}

template <typename T>
T HeapFast<T>::peekMin() const {
   return allData[0];
}

template <typename T>
void HeapFast<T>::popMin() {
   if (currentSize == 0) {
      cout << "Nothing to pop" << endl;
      return;
   }
   allData[0] = allData[currentSize - 1];
   bubbleDown(0);
   currentSize--;
}
