//
// Created by teodor on 1/24/18.
//

#ifndef SKIPLIST_SKIPLIST_H
#define SKIPLIST_SKIPLIST_H

#include "Node.h"
#include <iostream>
using namespace std;

class SkipList {
public:
    explicit SkipList(int maxLevel, float fraction);
    void insert(int key);
    Node * find(int key);
    void deleteKey(int key);
    void display();

private:
    int maxLevel;
    int curLevel;
    int maxKey;
    float fraction;
    //Node * nil;
    Node * end;
    Node * head;
    int randomLevel();
};


#endif //SKIPLIST_SKIPLIST_H
