/*
* Author: Mehmet KOC
* GitID: mehmettkocc
* Date: 10/11/13
* Description: The implementation for BST iterator class
*/

#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP

#include <list>
#include <iterator>
#include "BSTNode.hpp"

template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag, Data> {

private:

   BSTNode<Data>* curr;

public:

   /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */
   BSTIterator(BSTNode<Data>* node) {
      curr = node;
   }

   /** Dereference operator. */
   Data operator*() const {
      return curr->data;
   }

   /** Pre-increment operator. */
   BSTIterator<Data>& operator++() {
      curr = curr->successor();
      return *this;
   }

   /** Post-increment operator. */
   BSTIterator<Data> operator++(int) {
      BSTIterator before = BSTIterator(curr);
      ++(*this);
      return before;
   }

   /** Equality test operator. */
   bool operator==(BSTIterator<Data> const& other) const {
      return (curr == other.curr);
   }

   /** Inequality test operator. */
   bool operator!=(BSTIterator<Data> const & other) const {
      return (curr != other.curr);
   }

};

#endif //BSTITERATOR_HPP
