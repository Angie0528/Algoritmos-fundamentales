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

    std::cout << "Inorder: ";
    bst.inorder();
    std::cout << "\n";
    std::cout << "Preorder: ";
    bst.preorder();
    std::cout << "\n";
    std::cout << "Postorder: ";
    bst.inorder();
    std::cout << "\n";

    std::cout << "----------------------\n";
    std::cout << bst.search(49) << " - Si existe\n";
    std::cout << bst.search(50) << " - No existe\n";
    std::cout << bst.search(4) << " - Si existe\n";

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