#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class Node{
    private:
        int key;
        Node* left;
        Node* right;
        friend class BinarySearchTree;
    public:
        Node(int k);

};

class BinarySearchTree{
    private:
        Node* root;
        bool search(Node* node, int key);
        void display(Node* node, int indent);
    public:
        BinarySearchTree(){root = nullptr;}
        void insert(int key);
        bool search(int key);
        void remove(int key);
        void inorder();
        void preorder();
        void postorder();
        void display();
};

#endif