//
// Created by teodor on 1/24/18.
//

#include "SkipList.h"
#include <bits/stdc++.h>

SkipList::SkipList(int maxLevel, float fraction) : maxLevel(maxLevel-1), curLevel(0), maxKey(99999), fraction(fraction) {

    end = new Node;
    head = new Node;

    end->key = maxKey;
    head->key = 0;

    //*head->data = (Node*)malloc(sizeof(Node) * maxLevel);
    //memset(head->data, 0, sizeof(Node*)*(maxLevel));
    head->data = new Node*[maxLevel+1];
    memset(head->data, 0, sizeof(Node*)*(maxLevel+1));

    end->data = new Node*[maxLevel+1];
    memset(end->data, 0, sizeof(Node*)*(maxLevel+1));

    for (int i = 0; i < maxLevel; i++){
        end->data[i] = NULL;
        head->data[i] = end;
    }
    //nil = end;
}

// create random level for node
int SkipList::randomLevel()
{
    float r = (float)rand()/RAND_MAX;
    int lvl = 0;
    while (r < fraction && lvl < maxLevel)
    {
        lvl++;
        r = (float)rand()/RAND_MAX;
    }
    return lvl;
};

void SkipList::insert(int key) {
    Node *current = head;

    Node *update[maxLevel];

    memset(update, 0, sizeof(Node*)*(maxLevel));

    for (int i = curLevel; i >= 0; i--)
    {
        while (current->data[i] != NULL && current->data[i]->key < key){
            current = current->data[i];
        }
        update[i] = current;
    }

    current = current->data[0];

    if (current == NULL || current->key != key)
    {
        // Generate a random level for node
        int randLevel = randomLevel();

        if (randLevel > curLevel)
        {
            for (int i=curLevel+1; i<=randLevel; i++){
                update[i] = head;
            }
            // Update the list current level
            curLevel = randLevel;
        }

        Node* n = new Node;
        n->key = key;

        n->data = new Node*[randLevel+1];
        memset(n->data, 0, sizeof(Node*)*(randLevel+1));

        //cout << "New key " << key << endl;
        //cout << "Rand lvl " << randLevel << endl;
        //cout << "Current lvl " << curLevel << endl;

        for (int i=0;i<=randLevel;i++)
        {
            n->data[i] = update[i]->data[i];
            update[i]->data[i] = n;
        }

        //cout << "Inserted key " << key << "\n";
    }
}

Node* SkipList::find(int key) {
    Node *current = head;

    for(int i = curLevel; i >= 0; i--)
    {
        while(current->data[i] && current->data[i]->key < key){
            current = current->data[i];
        }
    }

    current = current->data[0];

    if(current && current->key == key){
        return current;
    }
    return end;
}

void SkipList::deleteKey(int key) {
    Node *current = head;

    Node *update[maxLevel+1];
    memset(update, 0, sizeof(Node*)*(maxLevel+1));

    for(int i = curLevel; i >= 0; i--)
    {
        while(current->data[i] != NULL  && current->data[i]->key < key){
            current = current->data[i];
        }
        update[i] = current;
    }

    current = current->data[0];

    // If current node is target node
    if(current != NULL && current->key == key)
    {

        for(int i=0;i<=curLevel;i++)
        {

            if(update[i]->data[i] != current){
                break;
            }
            update[i]->data[i] = current->data[i];
        }

        // Remove levels having no elements
        while (curLevel>0 && head->data[curLevel]->data[0] == NULL){
            curLevel--;
        }
    }
    delete current;
}

void SkipList::display()
{
    cout<<"\n*****Skip List*****"<<"\n";
    for (int i=0;i<=curLevel;i++)
    {
        Node *node = head->data[i];
        cout << "Level " << i << ": ";
        while (node->data[0] != NULL)
        {
            cout << node->key<<" ";
            node = node->data[i];
        }
        cout << endl;
    }
}