//
// Created by Brian Myers on 2/13/23.
//

#include <iostream>
#include <sstream>

#ifndef INC_4_3_BINARYSEARCHTREE_H
#define INC_4_3_BINARYSEARCHTREE_H


template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree( );

    int numNodes(BinarySearchTree* t) const {
        return numNodesInternal(t->root, 0);
    }


    int numLeaves(BinarySearchTree* t) const {
        //Run time N, has to look through every node
        return numLeavesInternal(t->root, 0);
    }


    int numFullNodes(BinarySearchTree* t) const {
        //Run time N, has to look through every node
        return numFullNodesInternal(t->root, 0);
    }

    //4.32
    bool isBinSearchTree(BinarySearchTree* t) const {
        bool isTrue = true;
        isBinMiniTree(t->root, isTrue);

        return isTrue;
    }

private:
    struct BinaryNode {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
                : element{ theElement }, left{ lt }, right{ rt } { }
        BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt )
                : element{ std::move( theElement ) }, left{ lt }, right{ rt } { }
    };

    BinaryNode *root;


    int numNodesInternal(BinaryNode* n, int sum) const {
        //Run time N, has to look through every node
        if (n->left == nullptr && n->right == nullptr) return sum + 1;
        if (n->left != nullptr) return numNodesInternal(n->left, sum + 1);
        if (n->right != nullptr) return numNodesInternal(n->right, sum + 1);

        return sum;
    }

    int numLeavesInternal(BinaryNode* n, int sum) const {
        //Run time N, has to look through every node
        if (n->left == nullptr && n->right == nullptr) return sum + 1;
        if (n->left != nullptr) return numLeavesInternal(n->left, sum);
        if (n->right != nullptr) return numLeavesInternal(n->right, sum);

        return sum;
    }

    int numFullNodesInternal(BinaryNode* n, int sum) const {
        //Run time N, looks through every node
        if (n->left != nullptr && n->right != nullptr) return numFullNodesInternal(n->left, sum + 1);
        if (n->left != nullptr) return numFullNodesInternal(n->left, sum);
        if (n->right != nullptr) return numFullNodesInternal(n->right, sum);


        return sum;
    }

    void isBinaryMiniTree(BinaryNode* n, bool& isTrue) const {
        if (!isTrue) return;
        if (n->left == nullptr && n->right == nullptr) return;
        if (n->left != nullptr) {
            if (n->left > n->element) {
                isTrue = false;
                return;
            } else isBinaryMiniTree(n->left, isTrue);
        }

        if (n->right != nullptr) {
            if (n->right < n->element) {
                isTrue = false;
                return;
            } else isBinaryMiniTree(n->right, isTrue);
        }
    }
};
#endif //INC_4_3_BINARYSEARCHTREE_H
