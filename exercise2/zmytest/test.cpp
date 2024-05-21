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
  lasd::SortableVector<int> vec(4);
  for(unsigned long i = 0; i<vec.Size(); i++){
    vec[i] = i;
  }
  // lasd::BinaryTreeLnk<int>::NodeLnk node(10);
  // lasd::BinaryTreeLnk<int>::NodeLnk node2(20);
  // lasd::BinaryTreeLnk<int>::NodeLnk node3(30);
  // lasd::BinaryTreeLnk<int>::NodeLnk node4(40);

  // node2.left = &node3;
  // node2.right = &node4;

  // cout << node.elem << endl;
  // node = node2;
  // cout << node.elem;
  // cout << node.LeftChild().Element() << endl;
  // cout << node.RightChild().Element() << endl;

  lasd::BST<int> bst(vec);
  bst.Traverse(&TraversePrint<int>);

}
