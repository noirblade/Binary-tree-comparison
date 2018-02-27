#include <iostream>
#include <chrono>
#include <random>

#include "SkipList.h"
#include "BinaryTree.h"
#include "SplayTree.h"

using namespace std;
#define MAX_NODES 99999
#define MAX_FIND_KEYS 99999
#define MAX_DELETE_KEYS 99999

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);

int getRandomInt(){
    uniform_int_distribution<int> distribution(0,MAX_NODES);
    return distribution(generator);
}

void testSkipList(bool random, int levels, float fraction){

    cout << "Random " << random << " Levels: " << levels << " Fraction: " << fraction << endl;
    SkipList skList(levels, fraction);

    int randomInts[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++){
        if (random){
            randomInts[i] = getRandomInt();
        } else {
            randomInts[i] = i;
        }
    }

    auto t0 = chrono::high_resolution_clock::now();
    for (int i = 0; i < MAX_NODES; i++){
        skList.insert(randomInts[i]);
    }
    auto t1 = chrono::high_resolution_clock::now();
    cout << "Time insert SkipList: " << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << endl;
    //skList.display();

    auto tf0 = chrono::high_resolution_clock::now();
    for (int i = 0; i < MAX_FIND_KEYS; i++){
        Node *found = skList.find(randomInts[i]);
    }
    auto tf1 = chrono::high_resolution_clock::now();
    cout << "Time find SkipList: " << chrono::duration_cast<chrono::microseconds>(tf1 - tf0).count() << endl;

    //skList.display();
    /*if (found->data[0] == NULL){
        // Should point to end
        cout << "Key not found " << found->key << endl;
    } else {
        cout << "Found key " << found->data[3]->key << endl;
    }*/

    auto td0 = chrono::high_resolution_clock::now();
    for (int i = 0; i < MAX_DELETE_KEYS; i++) {
        skList.deleteKey(randomInts[i]);
    }
    auto td1 = chrono::high_resolution_clock::now();
    cout << "Time delete SkipList: " << chrono::duration_cast<chrono::microseconds>(td1 - td0).count() << endl;

    cout << "_______________________" << endl;
    //skList.display();
}

void testBTree(bool random){
    BinaryTree bTree;

    int randomInts[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++){
        if (random){
            randomInts[i] = getRandomInt();
        } else {
            randomInts[i] = i;
        }
    }

    auto t0 = chrono::high_resolution_clock::now();
    for (int i = 0; i < MAX_NODES; i++){
        bTree.insert(randomInts[i]);
    }
    auto t1 = chrono::high_resolution_clock::now();
    cout << "Time insert Binary Tree: " << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << endl;

    //bTree.display();

    auto tf0 = chrono::high_resolution_clock::now();
    for (int i = 0; i < MAX_FIND_KEYS; i++){
        BNode *found = bTree.find(randomInts[i]);
    }
    auto tf1 = chrono::high_resolution_clock::now();

    /*if (found == NULL){
        // Should point to end
        cout << "Key not found " << found << endl;
    } else {
        cout << "Found key " << found->key << endl;
    }*/
    cout << "Time find BinaryTree: " << chrono::duration_cast<chrono::microseconds>(tf1 - tf0).count() << endl;

    auto td0 = chrono::high_resolution_clock::now();
    for (int i = 0; i < MAX_DELETE_KEYS; i++) {
        bTree.deleteKey(randomInts[i]);
    }
    auto td1 = chrono::high_resolution_clock::now();
    cout << "Time delete BinaryTree: " << chrono::duration_cast<chrono::microseconds>(td1 - td0).count() << endl;

    cout << "_______________________" << endl;
    //bTree.display();
}

void testSplayTree(bool random){
    SplayTree bTree;

    int randomInts[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++){
        if (random){
            randomInts[i] = getRandomInt();
        } else {
            randomInts[i] = i;
        }
    }

    auto t0 = chrono::high_resolution_clock::now();
    for (int i = 0; i < MAX_NODES; i++){
        bTree.insert(randomInts[i]);
    }

    auto t1 = chrono::high_resolution_clock::now();
    cout << "Time insert Splay Tree: " << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << endl;

    auto tf0 = chrono::high_resolution_clock::now();
    for (int i = 0; i < MAX_FIND_KEYS; i++){
        BNode *found = bTree.find(randomInts[i]);
    }
    //bTree.display();

    auto tf1 = chrono::high_resolution_clock::now();

    /*if (found == NULL){
        // Should point to end
        cout << "Key not found " << found << endl;
    } else {
        cout << "Found key " << found->key << endl;
    }*/
    cout << "Time find Splay Tree: " << chrono::duration_cast<chrono::microseconds>(tf1 - tf0).count() << endl;

    /*for (int i = 0; i < MAX_NODES; i++){
        randomInts[i] = getRandomInt();
    }*/

    auto td0 = chrono::high_resolution_clock::now();
    for (int i = 0; i < MAX_DELETE_KEYS; i++){
        bTree.deleteKey(randomInts[i]);
    }
    auto td1 = chrono::high_resolution_clock::now();
    cout << "Time delete Splay Tree: " << chrono::duration_cast<chrono::microseconds>(td1 - td0).count() << endl;

    cout << "_______________________" << endl;
    //bTree.display();
}

int main() {

    //testSkipList(false, 4, 0.5);
    //testSkipList(true, 4, 0.5);

    //testSkipList(false, 6, 0.5);
    //testSkipList(true, 6, 0.5);

    //testSkipList(false, 6, 0.3);
    //testSkipList(true, 6, 0.3);

    //testSkipList(false, 2, 0.5);
    //testSkipList(true, 2, 0.5);

    //testSkipList(false, 4, 0.7);
    //testSkipList(true, 4, 0.7);

    //testBTree(false);
    //testBTree(true);

    testSplayTree(false);
    testSplayTree(true);

    return 0;
}