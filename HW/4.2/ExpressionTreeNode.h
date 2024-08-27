#ifndef INC_4_2_EXPRESSIONTREENODE_H
#define INC_4_2_EXPRESSIONTREENODE_H

template <typename T>
class ExpressionTreeNode {
public:

    explicit ExpressionTreeNode(T value, ExpressionTreeNode* l = nullptr, ExpressionTreeNode* r = nullptr) :
        val(value), left(l), right(r) {};


    T getValue() const { return val;}

    ExpressionTreeNode* getLeft() const { return left;}

    ExpressionTreeNode* getRight() const { return right;}


private:
    T val;
    ExpressionTreeNode* left;
    ExpressionTreeNode* right;
};



#endif //INC_4_2_EXPRESSIONTREENODE_H
