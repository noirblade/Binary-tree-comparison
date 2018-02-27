//
// Created by teodor on 2/20/18.
//

#ifndef SKIPLIST_RBTREE_H
#define SKIPLIST_RBTREE_H


#include "RBNode.h"

class RBTree {
public:
    RBTree() : root(nullptr) {}

private:
    RBNode *root;

};


#endif //SKIPLIST_RBTREE_H
