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
    struct TreeNode
    {
        explicit TreeNode(T new_value) : value(new_value), left(NULL), right(NULL) {}
        T value;
        TreeNode *left;
        TreeNode *right;
    };
public:
    TreeNode *root;

    MyBinaryTree() : root(NULL) {} //Default Constructor

    MyBinaryTree(const MyBinaryTree &other) : root(NULL) //Copy Constructor
    {
        //TreeNode
    }

    ~MyBinaryTree() { //Destructor
        destroy(root);
    }

    void destroy(TreeNode *node);

    void push(T new_value);

    std::ostream& print(std::ostream &out, TreeNode *node) const;

    friend std::ostream& operator<<(std::ostream &out, const MyBinaryTree<T> &tree)
    {
        typename MyBinaryTree<T>::TreeNode *cur = tree.root;
        out << tree.print(out, cur);
        return out;
    }
};

template<typename T>
void MyBinaryTree<T>::destroy(TreeNode *node) {
    TreeNode *cur = node;
    if (cur != NULL) {
        destroy(cur->left);
        destroy(cur->right);
        delete cur;
    }
}

template<typename T>
void MyBinaryTree<T>::push(T new_value) {
    TreeNode *new_node = new TreeNode(new_value);
    TreeNode *cur = root;
    while (cur != NULL)
    {
        if (cur->value > new_value)
            cur = cur->left;
        else
            cur = cur->right;
    }
    cur = new_node;
    cur->left = cur->right = NULL;
}

template<typename T>
std::ostream& MyBinaryTree<T>::print(std::ostream &out, TreeNode *node) const
{
    TreeNode *cur = node;
    if (cur != NULL)
    {
        print(cur->left);
        print(cur->right);
        out << cur->value;
    }
    return out;
}

#endif //CPP_LAB_10_MYBINARYTREE_H
