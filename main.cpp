#include <iostream>
#include "MyBinaryTree.h"

int main()
{
    MyBinaryTree<int> tree;
    for (int i = 0; i < 10; ++i)
        tree.push(i);
    std::cout << tree;
    return 0;
}
