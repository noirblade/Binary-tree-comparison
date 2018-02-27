//
// Created by teodor on 2/7/18.
//

#ifndef SKIPLIST_BNODE_H
#define SKIPLIST_BNODE_H


class RBNode {
public:
    int key;
    RBNode *left;
    RBNode *right;
    RBNode *parent;
};


#endif //SKIPLIST_BNODE_H
