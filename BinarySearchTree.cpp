#include <iostream>
#include "BinarySearchTree.h"
#include <stack>

Node::Node(int k){
    key = k;
    left = nullptr;
    right = nullptr;
}

void BinarySearchTree::insert(int key){
    Node* newNode = new Node(key);

    if (root == nullptr){
        root = newNode;
        return;
    }   

    Node* current = root;
    Node* parent = nullptr;

    while(current != nullptr){
        parent = current;
        if (key < current->key){
            current = current->left;
        }else if (key > current->key){
            current = current->right;
        }else return;
    }
    
    if (key < parent->key) parent->left = newNode;
    else parent->right = newNode;

}

bool BinarySearchTree::search(int key){
    return search(root, key);
}

bool BinarySearchTree::search(Node* node, int key){
    // para usar la recursion tenemos que llamar a este metodo con root como el node
    if (node == nullptr) return false;
    if (node->key == key) return true;

    if (key < node->key){
        return search(node->left, key);
    }else{
        return search(node->right, key);
    }

}

void BinarySearchTree::remove(int key){
    if (!search(root, key)) return;

    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr && current->key != key) {
        parent = current;

        if (key < current->key) current = current->left;
        else current = current->right;
    }

    if (current == nullptr) return;

    //Caso 1 - No hijos
    if (!current->left && !current->right) {
        if (current == root)
            root = nullptr;
        else if (parent->left == current)
            parent->left = nullptr;
        else
            parent->right = nullptr;
        delete current;
    }
    else if (!current->left || !current->right) { // Caso 2 - Un hijo
        Node* child = (current->left) ? current->left : current->right;
        if (current == root)
            root = child;
        else if (parent->left == current)
            parent->left = child;
        else
            parent->right = child;
        delete current;
    }
    else { // Caso 3 - Dos hijos
        Node* nextParent = current;
        Node* next = current->right;
        while (next->left != nullptr) {
            nextParent = next;
            next = next->left;
        }

        current->key = next->key;

        if (nextParent->left == next)
            nextParent->left = next->right;
        else
            nextParent->right = next->right;

        delete next;
    }

}

void BinarySearchTree::inorder() {
    std::stack<Node*> stack;
    Node* current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();

        std::cout << current->key << " ";

        current = current->right;
    }

    std::cout << std::endl;
}


void BinarySearchTree::preorder() {
    if (root == nullptr) return;

    std::stack<Node*> stack;
    stack.push(root);

    while (!stack.empty()) {
        Node* current = stack.top();
        stack.pop();

        std::cout << current->key << " ";

        if (current->right) stack.push(current->right);
        if (current->left) stack.push(current->left);
    }

    std::cout << std::endl;
}



void BinarySearchTree::postorder() {
    if (root == nullptr) return;

    std::stack<Node*> stack1, stack2;
    stack1.push(root);

    while (!stack1.empty()) {
        Node* current = stack1.top();
        stack1.pop();
        stack2.push(current);

        if (current->left) stack1.push(current->left);
        if (current->right) stack1.push(current->right);
    }

    while (!stack2.empty()) {
        std::cout << stack2.top()->key << " ";
        stack2.pop();
    }

    std::cout << std::endl;
}

void BinarySearchTree::display(){
    display(root, 0);
    return;
}

void BinarySearchTree::display(Node* node, int indent){ 
    // para usar la recursion ocupamos llamarlo con el nodo root e indenatacion de 0
    if (node == nullptr) return;

        display(node->right, indent + 4);

        for (int i = 0; i < indent; i++)
            std::cout << ' ';
        std::cout << node->key << std::endl;

        display(node->left, indent + 4);

}