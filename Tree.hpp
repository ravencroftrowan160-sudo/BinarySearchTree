#ifndef TREE_HPP
#define TREE_HPP

#include <string>

struct Node{
    int value;
    bool flag;
    Node* leftc;
    Node* rightc;
};

class Tree{
private:
    Node* root;

    void destroy(Node* n);
    std::string preOrder(Node* n);
    std::string inOrder(Node* n);
    std::string postOrder(Node* n);   
public:
    //constructor/destructor
    Tree();
    ~Tree();

    void insertValue(int v);
    bool findValue(int v);
    bool removeValue(int v);
    std::string preOrder();
    std::string inOrder();
    std::string postOrder();

    int findLarger(int v);
    int removeLarger(int v);
};
#endif