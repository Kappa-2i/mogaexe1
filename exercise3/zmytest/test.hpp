
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include <sstream>
#include <iostream>

#include "../container/container.hpp"

#include "../vector/vector.hpp"

#include "../list/list.hpp"

#include "../stack/vec/stackvec.hpp"

#include "../stack/lst/stacklst.hpp"

#include "../queue/vec/queuevec.hpp"

#include "../queue/lst/queuelst.hpp"

using namespace lasd;

/* ************************************************************************** */

void mytest();

void choiceVectorType(uint&, uint&, std::stringstream&);

void choiceListType(uint&, uint&, std::stringstream&);

void choiceStackType(uint&, uint&, std::stringstream&);

void choiceQueueType(uint&, uint&, std::stringstream&);

void choiceBinaryTreeType(uint&, uint&, std::stringstream&);

void choiceHashTableType(uint&, uint&, std::stringstream&);



void testVectorInt(uint&, uint&, std::stringstream&);

void testVectorDouble(uint&, uint&, std::stringstream&);

void testVectorString(uint&, uint&, std::stringstream&);



void testListInt(uint&, uint&, std::stringstream&);

void testListDouble(uint&, uint&, std::stringstream&);

void testListString(uint&, uint&, std::stringstream&);



void testStackVecFloat(uint&, uint&, std::stringstream&);

void testStackVecString(uint&, uint&, std::stringstream&);

void testStackListFloat(uint&, uint&, std::stringstream&);

void testStackListString(uint&, uint&, std::stringstream&);



void testQueueVecFloat(uint&, uint&, std::stringstream&);

void testQueueVecString(uint&, uint&, std::stringstream&);

void testQueueListFloat(uint&, uint&, std::stringstream&);

void testQueueListString(uint&, uint&, std::stringstream&);



void testBinaryTreeVecFloat(uint&, uint&, std::stringstream&);

void testBinaryTreeVecString(uint&, uint&, std::stringstream&);

void testBinaryTreeLnkFloat(uint&, uint&, std::stringstream&);

void testBinaryTreeLnkString(uint&, uint&, std::stringstream&);

// void testBSTFloat(uint&, uint&, std::stringstream&);

// void testBSTString(uint&, uint&, std::stringstream&);



void testHashTableClsAdrInt(uint&, uint&, std::stringstream&);

void testHashTableClsAdrString(uint&, uint&, std::stringstream&);

void testHashTableOpnAdrInt(uint&, uint&, std::stringstream&);

void testHashTableOpnAdrString(uint&, uint&, std::stringstream&);



template <typename Data>
void TraversePrint(const Data& dat) {
  std::cout << dat << " ";
}

template <typename Data>
Data FoldAdd(const Data& dat, const Data& acc) {
  return (acc + dat);
}





/* ************************************************************************** */

#endif