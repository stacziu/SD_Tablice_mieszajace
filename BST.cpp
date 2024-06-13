//
// Created by stasi on 02.06.2024.
//

#include "BST.h"


//PRIVATE (helpers)
Node* BST::insertionHelper(Node* root, Node* node) {
    if (root == nullptr) {
        return node;
    }
    if (node->key > root->key) {
        root->right = insertionHelper(root->right, node);
    } else if (node->key < root->key) {
        root->left = insertionHelper(root->left, node);
    }
    return root; // Ensure the current root is returned
}

Node* BST::removeHelper(Node* root, int key) {
    if(root == nullptr) {
        return root;
    }

    if(key > root->key) {
        root->right = removeHelper(root->right, key);
    } else if(key < root->key) {
        root->left = removeHelper(root->left, key);
    }

    else{   //node found
        if(root->left == nullptr && root->right == nullptr) { //no children
            delete root;
            root = nullptr;
        } else if(root->right != nullptr) { // there is a successor
            root = successor(root);
            root->right = removeHelper(root->right, root->key);
        } else { // there is a predecessor
            root = predecessor(root);
            root->left = removeHelper(root->left, root->key);
        }
    }
    return root;
}

Node* BST::successor(Node* root){ //right child
    root = root->right;
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* BST::predecessor(Node *root) { //left child
    root = root->left;
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

void BST::printHelper(Node *root) {
    if(root != nullptr){
        printHelper(root->left);
        std::cout << root->val << ", ";
        printHelper(root->right);
    }
}

Node* BST::getHelper(Node *root, int key) {
    if(root == nullptr) {
        return root;
    }
    if(key == root->key) {
        return root;
    } else if(key < root->key) {
        return getHelper(root->left, key);
    } else{
        return getHelper(root->right, key);
    }
}

//PUBLIC
BST::BST(){
    root = nullptr;
}

BST::~BST(){
    delete root;
}

void BST::insert(int key, int val) {
    root = insertionHelper(root, new Node(key, val));
}

void BST::remove(int key) {
    root = removeHelper(root, key);
}

int BST::get(int key){
    Node* node = getHelper(root, key);
    if (node != nullptr) {
        return node->val;
    } else {
        std::cout << "There is no key of that value in this BST !\n";
        return -1;
    }
}

void BST::print() {
    printHelper(root);
}

bool BST::isEmpty() {
    if(root == nullptr){
        return true;
    }
    else return false;
}