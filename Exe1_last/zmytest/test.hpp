
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include <sstream>

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

void testVectorInt(Vector<int>&, uint&, uint&, std::stringstream&);

Vector<int> intVector(const unsigned long);

Vector<double> doubleVector(const unsigned long);

Vector<std::string> stringVector(const unsigned long);


/* ************************************************************************** */

#endif
