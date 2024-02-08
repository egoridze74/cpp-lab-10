//
// Created by Egor on 23.01.2024.
//

#ifndef CPP_LAB_10_MYBINARYTREE_H
#define CPP_LAB_10_MYBINARYTREE_H

#include <iostream>
#include <string>

template<typename T>
class MyBinaryTree {
private:
    struct TreeNode {
        T value;
        TreeNode *left;
        TreeNode *right;

        explicit TreeNode(T new_value) : value(new_value), left(NULL), right(NULL) {}
    };

    void print_node(const TreeNode *cur, size_t depth, std::ostream& out) const {
        if (cur == NULL) {
            for (size_t i = 0; i < depth; ++i)
                out << '\t';
            out << "none" << std::endl;
            return;
        }
        print_node(cur->right, depth + 1, out);
        for (size_t i = 0; i < depth; ++i)
            out << '\t';
        out << cur->value << std::endl;
        print_node(cur->left, depth + 1, out);
    }


    void destroy(TreeNode* node) {
        if (node != NULL) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

public:
    TreeNode *root;

    MyBinaryTree() : root(NULL) {} //Default Constructor

    explicit MyBinaryTree(T value) { root = new TreeNode(value); }

    MyBinaryTree(const MyBinaryTree &other) //Copy Constructor
    {
        this->root = other.root;
    }

    ~MyBinaryTree() { //Destructor
        destroy(root);
    }

    void push(T new_value);

    friend std::ostream &operator<<(std::ostream &out, const MyBinaryTree<T> &tree) {
        tree.print_node(tree.root, 0, out);
        return out;
    }

    MyBinaryTree<T>& operator=(const MyBinaryTree<T>& other)
    {
        MyBinaryTree tree();
        this->root = other.root;
        return *this;
    }
};


template<typename T>
void MyBinaryTree<T>::push(T new_value) {
    TreeNode *cur = root;
    TreeNode *new_node = new TreeNode(new_value);
    while (true) {
        if (cur->value > new_value) {
            if (cur->left == NULL) {
                cur->left = new_node;
                break;
            } else
                cur = cur->left;
        } else {
            if (cur->right == NULL) {
                cur->right = new_node;
                break;
            } else
                cur = cur->right;
        }
    }
}

#endif //CPP_LAB_10_MYBINARYTREE_H
