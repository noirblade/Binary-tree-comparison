cmake_minimum_required(VERSION 3.9)
project(SkipList)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-O2")

add_executable(SkipList main.cpp SkipList.cpp SkipList.h Node.cpp Node.h BinaryTree.cpp BinaryTree.h BNode.cpp BNode.h SplayTree.cpp SplayTree.h RBNode.h RBNode.cpp RBTree.cpp RBTree.h)