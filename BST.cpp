#include <iostream>
#include "BinarySearchTree.h"

int main(){
    BinarySearchTree bst;

    bst.insert(20);
    bst.insert(49);
    bst.insert(12);
    bst.insert(80);
    bst.insert(4);
    bst.insert(30);

    bst.inorder();
    bst.preorder();
    bst.postorder();
    std::cout << "----------------------\n";
    std::cout << bst.search(49) << "\n";
    std::cout << bst.search(50) << "\n";
    std::cout << bst.search(4) << "\n";
    std::cout << "----------------------\n";
    bst.display();
    std::cout << "----------------------\n";
    bst.remove(20);
    bst.remove(80);
    bst.display();
    std::cout << "----------------------\n";
    bst.remove(49);
    bst.insert(50);
    bst.display();
    std::cout << "----------------------\n";
}