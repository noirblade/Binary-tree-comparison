//
// Created by teodor on 2/12/18.
//

#ifndef SKIPLIST_SPLAYTREE_H
#define SKIPLIST_SPLAYTREE_H

#include <iostream>
#include "BNode.h"

using namespace std;

class SplayTree {
public:
    SplayTree(): root(nullptr){};
    ~SplayTree(){destroyTree();};

    void insert(int key);
    BNode *find(int key);
    void destroyTree();
    void display();
    void deleteKey(int key);

private:
    void destroyTree(BNode *leaf);
    void display(BNode * node, int lvl);
    BNode *minValueNode(BNode *node);
    BNode *deleteKey(BNode *node, int key);
    BNode *splay(int key, BNode * node);
    BNode *rightRotate(BNode *x);
    BNode *leftRotate(BNode *x);
    BNode *root;
};


#endif //SKIPLIST_SPLAYTREE_H
