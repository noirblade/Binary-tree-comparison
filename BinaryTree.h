//
// Created by teodor on 2/7/18.
//

#ifndef SKIPLIST_BINARYTREE_H
#define SKIPLIST_BINARYTREE_H

#include <iostream>
#include "BNode.h"

using namespace std;

class BinaryTree {
public:
    BinaryTree(): root(nullptr){};
    ~BinaryTree(){destroyTree();};

    void insert(int key);
    BNode *find(int key);
    void destroyTree();
    void display();
    void deleteKey(int key);

private:
    void destroyTree(BNode *leaf);
    void insert(int key, BNode *leaf);
    void display(BNode * node, int lvl);
    BNode *minValueNode(BNode *node);
    BNode *deleteKey(BNode *node, int key);
    BNode *find(int key, BNode *leaf);
    BNode *root;
};


#endif //SKIPLIST_BINARYTREE_H
