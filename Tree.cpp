#include "Tree.hpp"

void Tree::destroy(Node* n){
    if(!n){
        //can be shortened to if(!n) return; but I like this better(it's neater but more lines)
        return;
    }

    //recurse to left child if left child isn't null
    destroy(n->leftc);

    //recurse to right child
    destroy(n->rightc);

    delete n;
}

std::string Tree::preOrder(Node* n){
    if(!n) return "";

    std::string out = std::to_string(n->value);

    if(!n->flag) out += "D";

    return out + " " + preOrder(n->leftc) + preOrder(n->rightc);
    
}

std::string Tree::inOrder(Node* n){
    if(!n) return "";

    std::string out = inOrder(n->leftc);

    out += std::to_string(n->value);
    if(!n->flag) out += "D";
    out += " ";

    out += inOrder(n->rightc);

    return out;
}

std::string Tree::postOrder(Node* n){
    if(!n) return "";

    std::string out = postOrder(n->leftc) + postOrder(n->rightc);

    out += std::to_string(n->value);
    if(!n->flag) out += "D";
    out += " ";

    return out;
}

Tree::Tree(){
    root = nullptr;
}

Tree::~Tree(){
    destroy(root);
}

void Tree::insertValue(int v){
    if(!root){
        Node* newNode = new Node;
        newNode->value = v;
        newNode->flag = true;
        newNode->leftc = nullptr;
        newNode->rightc = nullptr;

        root = newNode;
        return;
    }

    Node* curr = root;

    while(true){
        if(v == curr->value){
            curr->flag = true;
            return;
        }
        else if(v < curr->value){
            if(curr->leftc == nullptr){
                Node* newNode = new Node;
                newNode->value = v;
                newNode->flag = true;
                newNode->leftc = nullptr;
                newNode->rightc = nullptr;

                curr->leftc = newNode;
                return;
            }
            curr = curr->leftc;
        }
        else {
            if(curr->rightc == nullptr){
                Node* newNode = new Node;
                newNode->value = v;
                newNode->flag = true;
                newNode->leftc = nullptr;
                newNode->rightc = nullptr;

                curr->rightc = newNode;  
                return;
            }
            curr = curr->rightc;
        }
    }
}  

bool Tree::findValue(int v){
    Node* curr = root;

    while(curr){
        if(v == curr->value){
            return curr->flag;
        }
        else if(v < curr->value){
            curr = curr->leftc;
        }
        else {
            curr = curr->rightc;
        }
    }

    return false;
}

bool Tree::removeValue(int v){
    Node* curr = root;

    while(curr){
        if(v == curr->value){
            if(curr->flag){
                curr->flag = false;   // mark as deleted
                return true;
            }
            else{
                return false;         // already deleted
            }
        }
        else if(v < curr->value){
            curr = curr->leftc;
        }
        else{
            curr = curr->rightc;
        }
    }

    return false;   // not found
}

std::string Tree::preOrder(){
    return preOrder(root);
}

std::string Tree::inOrder(){
    return inOrder(root);
}

std::string Tree::postOrder(){
    return postOrder(root);
}

int Tree::findLarger(int v){
    // If v exists and is not deleted, return it
    if(findValue(v)){
        return v;
    }

    Node* curr = root;
    Node* candidate = nullptr;

    while(curr){
        if(v < curr->value){
            // curr is a possible successor
            if(curr->flag){
                candidate = curr;
            }
            curr = curr->leftc;
        }
        else{
            curr = curr->rightc;
        }
    }

    if(candidate){
        return candidate->value;
    }

    return -1; // or whatever your lab requires
}

int Tree::removeLarger(int v){
    int target = findLarger(v);

    if(target == -1){
        return -1;
    }

    removeValue(target);
    return target;
}