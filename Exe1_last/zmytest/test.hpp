
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

void testVectorInt(uint&, uint&, std::stringstream&);

void testVectorDouble(uint&, uint&, std::stringstream&);

void testVectorString(uint&, uint&, std::stringstream&);

void testListInt(uint&, uint&, std::stringstream&);




template <typename Data>
void TraversePrint(const Data & dat) {
  std::cout << dat << " ";
}

template <typename Data>
Data FoldAdd(const Data & dat, const Data & acc) {
  return (acc + dat);
}



/* ************************************************************************** */

#endif
