//
// Created by teodor on 2/12/18.
//

#include "SplayTree.h"

void SplayTree::destroyTree() {
    destroyTree(root);
}

void SplayTree::destroyTree(BNode *leaf) {
    if(leaf != nullptr)
    {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
    }
}

void SplayTree::insert(int key) {

    if (root == nullptr){
        root = new BNode;
        root->key = key;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }

    root = splay(key, root);

    if (root->key == key) {
        return;
    }

    BNode *node  = new BNode;
    node->key = key;

    if (root->key > key)
    {
        node->right = root;
        node->left = root->left;
        root->left = nullptr;
    }
    else
    {
        node->left = root;
        node->right = root->right;
        root->right = nullptr;
    }
    root = node;
}

BNode *SplayTree::rightRotate(BNode *x)
{
    BNode *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
BNode *SplayTree::leftRotate(BNode *x)
{
    BNode *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

BNode *SplayTree::splay(int key, BNode *node){

    if (node == nullptr || node->key == key)
        return node;

    if (node->key > key){
        if (node->left == nullptr){
            return node;
        }
        if (node->left->key > key){
            node->left->left = splay(key, node->left->left);
            node = rightRotate(node);
        } else if (node->left->key < key){
            node->left->right = splay(key, node->left->right);

            if (node->left->right != nullptr){
                node->left = leftRotate(node->left);
            }
        }
        return (node->left == nullptr) ? node : rightRotate(node);
    } else {

        if (node->right == nullptr){
            return node;
        }

        if (node->right->key > key)
        {
            // Bring the key as root of right-left
            node->right->left = splay(key, node->right->left);

            // Do first rotation for root->right
            if (node->right->left != nullptr)
                node->right = rightRotate(node->right);
        }
        else if (node->right->key < key)// Zag-Zag (Right Right)
        {
            // Bring the key as root of right-right and do first rotation
            node->right->right = splay(key, node->right->right);
            node = leftRotate(node);
        }

        // Do second rotation for root
        return (node->right == nullptr) ? node : leftRotate(node);
    }
}

BNode* SplayTree::find(int key) {
    BNode * found = splay(key, root);
    root = found;
    return found;
}

/*BNode* SplayTree::find(int key, BNode *leaf) {

    if(leaf != nullptr)
    {
        if(key == leaf->key){
            return leaf;
        }

        path.push_back(leaf);
        if(key < leaf->key){
            return find(key, leaf->left);
        } else {
            return find(key, leaf->right);
        }
    } else {
        return nullptr;
    }
}*/

void SplayTree::deleteKey(int key) {

    root = deleteKey(root, key);
}

BNode *SplayTree::deleteKey(BNode *curRoot, int key) {

    if (curRoot == nullptr){
        return curRoot;
    }

    if (key < curRoot->key){
        curRoot->left = deleteKey(curRoot->left, key);
    } else if (key > curRoot->key){
        curRoot->right = deleteKey(curRoot->right, key);
    } else {
        if (curRoot->left == nullptr && curRoot->right == nullptr){
            delete curRoot;
            curRoot = nullptr;
        } else if (curRoot->right == nullptr){
            BNode *temp = curRoot;
            curRoot = curRoot->left;
            delete temp;
        } else if (curRoot->left == nullptr){
            BNode *temp = curRoot;
            curRoot = curRoot->right;
            delete temp;
        } else {
            BNode *temp = minValueNode(curRoot->right);
            curRoot->key = temp->key;

            curRoot->right = deleteKey(curRoot->right, temp->key);
        }
    }
    return curRoot;
}

BNode *SplayTree::minValueNode(BNode *node)
{
    BNode* current = node;

    while (current->left != nullptr){
        current = current->left;
    }
    return current;
}

void SplayTree::display()
{
    int lvl = 0;
    display(root, lvl);
}

void SplayTree::display(BNode * node, int lvl)
{
    if (!node) {
        return;
    }

    display (node->right, lvl+3);

    for( int i = 0; i < lvl; i++ ){
        cout <<' ';
    }
    cout << node->key << endl;

    display (node->left, lvl+3);
}