//
// Created by teodor on 2/7/18.
//

#include "BinaryTree.h"

void BinaryTree::destroyTree() {
    destroyTree(root);
}

void BinaryTree::destroyTree(BNode *leaf) {
    if(leaf != nullptr)
    {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
    }
}

void BinaryTree::insert(int key) {
    if(root != nullptr)
        insert(key, root);
    else
    {
        root = new BNode;
        root->key = key;
        root->left = nullptr;
        root->right = nullptr;
    }
}

void BinaryTree::insert(int key, BNode *leaf) {
    if(key < leaf->key)
    {
        if(leaf->left != nullptr)
            insert(key, leaf->left);
        else
        {
            leaf->left = new BNode;
            leaf->left->key = key;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    }
    else if(key >= leaf->key)
    {
        if(leaf->right != nullptr)
            insert(key, leaf->right);
        else
        {
            leaf->right = new BNode;
            leaf->right->key = key;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
        }
    }
}

BNode* BinaryTree::find(int key) {
    return find(key, root);
}

BNode* BinaryTree::find(int key, BNode *leaf) {

    if(leaf != nullptr)
    {
        if(key == leaf->key){
            return leaf;
        }

        if(key < leaf->key){
            return find(key, leaf->left);
        } else {
            return find(key, leaf->right);
        }
    } else {
        return nullptr;
    }
}

void BinaryTree::deleteKey(int key) {

    deleteKey(root, key);
}

BNode *BinaryTree::deleteKey(BNode *curRoot, int key) {
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

BNode *BinaryTree::minValueNode(BNode *node)
{
    BNode* current = node;

    while (current->left != nullptr){
        current = current->left;
    }
    return current;
}

void BinaryTree::display()
{
    int lvl = 0;
    display(root, lvl);
}

void BinaryTree::display(BNode * node, int lvl)
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