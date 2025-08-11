#include <iostream>
using namespace std;

// Structure for a binary tree node
struct Node
{
    int data;       // value of the node
    Node* left;     // pointer to left child
    Node* right;    // pointer to right child
    // Constructor to create a node with a given value
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Inorder Traversal: Left → Root → Right
void inorder(Node* root)
{
    if (!root) return;       // base case: if node is NULL, return
    inorder(root->left);     // visit left subtree
    cout << root->data << " "; // visit root
    inorder(root->right);    // visit right subtree
}

// Preorder Traversal: Root → Left → Right
void preorder(Node* root)
{
    if (!root) return;
    cout << root->data << " "; // visit root
    preorder(root->left);     // visit left subtree
    preorder(root->right);    // visit right subtree
}

// Postorder Traversal: Left → Right → Root
void postorder(Node* root)
{
    if (!root) return;
    postorder(root->left);    // visit left subtree
    postorder(root->right);   // visit right subtree
    cout << root->data << " "; // visit root
}

int main()
{
    /*
       Constructing a sample binary tree:
               1
              / \
             2   3
            / \
           4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Display results of each traversal
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
