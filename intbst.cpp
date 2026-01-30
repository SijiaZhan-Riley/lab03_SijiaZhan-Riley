// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
    root=nullptr;


}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);

}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if(n==nullptr)
        return;

    clear(n->left);
    clear(n->right);
    delete n;

}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    if(!root){
        root=new Node(value);
        return true;}
    return insert(value, root);

    // REPLACE THIS NON-SOLUTION
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if(value==n->info)
        return false;
    if(value < n->info){
        if(n->left==nullptr){
        n->left=new Node(value);
        return true;
        }
        return insert(value, n->left);
    }
    else{

        if(n->right==nullptr){
        n->right=new Node(value);
        return true;
    }
        return insert(value, n->right);
    }

 // REPLACE THIS NON-SOLUTION
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    if(!root)
        return;
    printPreOrder(root);


    
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if(!n) 
        return;
    cout << n->info <<" "; // IMPLEMENT HERE
    printPreOrder(n->left);
    printPreOrder(n->right);
    
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    if(!root)
        return;
    printInOrder(root);
    
}
void IntBST::printInOrder(Node *n) const {
    if(!n)
        return;
    printInOrder(n->left);
    cout<<n->info<<" ";
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {

    if(!root)
        return;
    printPostOrder(root);
    
}

void IntBST::printPostOrder(Node *n) const {
    if(!n)
        return;
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info<<" ";// IMPLEMENT HERE
}

// return sum of values in tree
int IntBST::sum() const {
    if(!root)
        return 0;
    return sum(root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if(!n)
        return 0;
    return sum(n->left)+n->info+sum(n->right);
    // REPLACE THIS NON-SOLUTION
}

// return count of values
int IntBST::count() const {
    if(!root)
        return 0;
    return count(root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if(!n)
        return 0;
    return 1+count(n->left)+count(n->right);

     // REPLACE THIS NON-SOLUTION
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if(!n)
        return nullptr;
    if(value==n->info)
        return n;
    
    if(value<n->info)
        return getNodeFor(value, n->left);
    else{
        return getNodeFor(value, n->right);
    }  
    
// REPLACE THIS NON-SOLUTION
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    if(!root)
        return false;
    return contains(value, root);
    
}
bool IntBST::contains(int value, Node* n) const{
    if(!n)
        return false;
    if(n->info==value)
        return true;
    if(n->info>value)
         return contains(value, n->left);
    else
        return contains(value, n->right);
    }





// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    if(!root)
        return nullptr;
    return getPredecessorNode(value, root);
    // REPLACE THIS NON-SOLUTION
}

IntBST::Node* IntBST::getPredecessorNode(int value, Node* n) const{
    if(!n) 
        return nullptr;
    if(value<=n->info)
        return getPredecessorNode(value, n->left);
    else{
        Node* pred=getPredecessorNode(value, n->right);
        if(pred)
            return pred;
        else
            return n;
    }

    

    
}



// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    if(!contains(value))
        return 0;

    Node* n=getPredecessorNode(value);
    if(!n)
        return 0;
    return n->info;
    
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    if(!root)
        return nullptr;
    return getSuccessorNode(value, root);
     // REPLACE THIS NON-SOLUTION
}
IntBST::Node* IntBST::getSuccessorNode(int value, Node* n) const{
    if(!n)
        return nullptr;
    if(value>=n->info)
        return getSuccessorNode(value, n->right);
    else{
        Node* succ=getSuccessorNode(value, n->left);
        if(succ)
            return succ;
        else
            return n;
    }

 // REPLACE THIS NON-SOLUTION
}
// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    if(!contains(value))
        return 0;
    Node* n=getSuccessorNode(value, root);
    if(!n)
        return 0;
    return n->info; // REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
    bool IntBST::remove(int value){
        if(!root)
            return false;
        
        return remove(value, root);
    }

    bool IntBST::remove(int value, Node*& n){
        if(!n)
            return false;
        if(value< n->info)
            return remove(value,n->left);
        else if(value> n->info)
            return remove(value, n->right);
        else {
            if(!n->left&&!n->right){
                delete n;
                n=nullptr;}
            else if(!n->left){
                Node* curr=n;
                n=n->right;
                delete curr;}
            else if(!n->right){
                Node* curr=n;
                n=n->left;
                delete curr;}
            else{
                Node* pred = getPredecessorNode(n->info, n->left);
                n->info = pred->info;                
                remove(pred->info, n->left);
            }

            return true;

        }


        
        // REPLACE THIS NON-SOLUTION
    }   

