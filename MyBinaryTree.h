//
// Created by Egor on 23.01.2024.
//

#ifndef CPP_LAB_10_MYBINARYTREE_H
#define CPP_LAB_10_MYBINARYTREE_H

#include <iostream>

template<typename T>
class MyBinaryTree
{
private:
    T field;
public:
    MyBinaryTree *left;
    MyBinaryTree *right;

    MyBinaryTree() : field(NULL), left(NULL), right(NULL) {} //Default Constructor

    MyBinaryTree(const MyBinaryTree &other) : field(NULL), left(NULL), right(NULL) //Copy Constructor
    { /* надо реализовать */}

    ~MyBinaryTree() //Destructor
    {
        destroy(this);
    }

    void destroy(MyBinaryTree *node);

    void push(T new_value);

    friend std::ostream &operator<<(std::ostream &o, const MyBinaryTree<T> &tree)
    { /* надо реализовать */}
};

template<typename T>
void MyBinaryTree<T>::destroy(MyBinaryTree *node)
{
    if (node != NULL)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

template<typename T>
void MyBinaryTree<T>::push(T new_value)
{
    MyBinaryTree current = this;
    while(this != NULL)
    {
        if (new_value < this->right)
            current = this->left;
        else if (new_value > this-> left)
            current = this->right;
    }
    this->value = new_value;
}

#endif //CPP_LAB_10_MYBINARYTREE_H
