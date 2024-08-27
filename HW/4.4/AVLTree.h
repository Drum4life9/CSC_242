//
// Created by Brian Myers on 2/16/23.
//

#ifndef INC_4_4_AVLTREE_H
#define INC_4_4_AVLTREE_H

#include <functional>

template <typename T>
class AVLTree {
public:
    struct AvlNode {
        T element;
        AvlNode *left;
        AvlNode *right;
        AvlNode *parent;
        int height;

        AvlNode( const T & ele, AvlNode *lt, AvlNode *rt, int h = 0 )
        : element{ ele }, left{ lt }, right{ rt }, height{ h } { }

        AvlNode( T && ele, AvlNode *lt, AvlNode *rt, int h = 0 )
        : element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }
        };

    /**
    * Return the height of node t or -1 if nullptr.
    */
    int height( AvlNode *t ) const
    {return t == nullptr ? -1 : t->height;}



    void doubleWithLeftChild( AvlNode * & k3 )
    {
        AvlNode* k1 = k3->left;
        AvlNode* k2 = k3->left->right;

        //take care of k2's children
        k3->left = k2->right;
        k1->right = k2->left;
        //then update k2
        k2->left = k1;
        k2->right = k3;
        //update heights
        k1->height = max(height(k1->left), height(k1->right));
        k3->height = max(height(k3->left), height(k3->right));
        k2->height = max(k1->height, k3->height);
        //reset root node
        k3 = k2;
    }

    /**
    * Rotate binary tree node with left child.
    * For AVL trees, this is a single rotation for case 1.
    * Update heights, then set new root.
    */
    void rotateWithLeftChild( AvlNode* k2 ) {

        AvlNode* k1 = k2->left;
        //strip k1's right child, reset parent
        k2->left = k1->right;
        k2->left->parent = k2;
        //k1's right child now is k2
        k1->right = k2;
        //set k1's parent to k2's old parent
        k1->parent = k2->parent;
        //reset k2 parent to k1 as now k1 is root of this new AVL tree
        k2->parent = k1;
    }

    bool is_balanced() {
        bool isBal = true;
        privBalance(root, isBal);
        return isBal;
    }

private:
    void privBalance(AvlNode* n, bool& isBal) {
        if (!isBal) return;
        if (n == nullptr) return;
        if (abs(height(n->left) - height(n->right)) > 1) {
            isBal = false;
            return;
        }
        is_balanced(n->left, isBal);
        is_balanced(n->right, isBal);

    }

    AvlNode* root;
};

#endif //INC_4_4_AVLTREE_H
