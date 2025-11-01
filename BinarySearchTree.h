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
    public:
        BinarySearchTree(){root = nullptr;}
        void insert(int key);
        bool search(Node* node, int key);
        void remove(Node* node, int key);
        void inorder();
        void preorder();
        void postorder();
        void display(Node* node, int indent);
};

#endif