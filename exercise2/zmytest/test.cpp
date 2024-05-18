/* ************************************************************************** */

#include <iostream>
#include "test.hpp"
#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"

#include "../list/list.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../bst/bst.hpp"

#include "../zlasdtest/binarytree/binarytree.hpp"
#include "../zlasdtest/bst/bst.hpp"

using namespace std;

/* ************************************************************************** */

void mytest() {
  lasd::Vector<int> vec(4);
  for(unsigned long i = 0; i < vec.Size(); i++){
    vec[i] = i;
  }

  // lasd::BinaryTreeVec<int> btvec(vec);
  // btvec.BreadthTraverse(&TraversePrint<int>);
  // cout << endl;

  // lasd::BST<int> bst(move(btvec));
  // bst.BreadthTraverse(&TraversePrint<int>);
  // cout << endl;

  lasd::BST<int> bst2;
  bst2.Insert(0);
  bst2.Insert(1);
  bst2.Insert(2);
  bst2.Insert(3);
  bst2.BreadthTraverse(&TraversePrint<int>);
  cout << endl;

  uint a = 1;
  uint b = 1;
  Predecessor(a, b, bst2, true, 3, 2);
  cout << endl;
  bst2.BreadthTraverse(&TraversePrint<int>);
  cout << endl;
  cout << bst2.Predecessor(3);


  // lasd::BinaryTreeLnk<int> btlnk(vec);
  // btlnk.BreadthTraverse(&TraversePrint<int>);
  // cout << endl;
  // uint a = 1;
  // uint b = 1;
  // IsLeaf(a, b, btlnk.Root(), true);
  // GetElement(a, b, btlnk.Root(), true, 0);

  
}
