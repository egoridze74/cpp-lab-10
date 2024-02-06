#include <iostream>
#include <string>
#include "MyBinaryTree.h"

int main()
{
    MyBinaryTree tree(3);
    MyBinaryTree int_tree(tree);
    int_tree.push(1);
    int_tree.push(2);
    int_tree.push(3);
    int_tree.push(4);
    std::cout << int_tree << std::endl;

    MyBinaryTree<std::string> string_tree("123");
    string_tree.push("111");
    string_tree.push("99");
    string_tree.push("100");
    string_tree.push("567");
    std::cout << string_tree << std::endl;
    return 0;
}
