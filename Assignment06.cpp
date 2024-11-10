// Name: Arwa Salujiwala	Roll no: 23555	Batch: S3 
// DSA Assignment 06   
// Implement In-order Threaded Binary Tree and traverse it in In-order and Pre-order. 

#include <iostream>
using namespace std;

// Node structure for Threaded Binary Tree
struct ThreadedBinaryTreeNode {
    int data;
    ThreadedBinaryTreeNode* left;
    ThreadedBinaryTreeNode* right;
    bool leftThread;
    bool rightThread;

    ThreadedBinaryTreeNode(int val) : data(val), left(nullptr), right(nullptr), leftThread(false), rightThread(false) {}
};

// Threaded Binary Tree class
class ThreadedBinaryTree {
private:
    ThreadedBinaryTreeNode* root;

    // Helper function to insert a node
    void insert(ThreadedBinaryTreeNode* &node, int val) {
        if (node == nullptr) {
            node = new ThreadedBinaryTreeNode(val);
            return;
        }

        if (val < node->data) {
            if (!node->leftThread) {
                insert(node->left, val);
            } else {
                ThreadedBinaryTreeNode* temp = new ThreadedBinaryTreeNode(val);
                temp->left = node->left;
                temp->right = node;
                node->left = temp;
                node->leftThread = true;
            }
        } else {
            if (!node->rightThread) {
                insert(node->right, val);
            } else {
                ThreadedBinaryTreeNode* temp = new ThreadedBinaryTreeNode(val);
                temp->right = node->right;
                temp->left = node;
                node->right = temp;
                node->rightThread = true;
            }
        }
    }

    // In-order Traversal using threads
    void inOrder(ThreadedBinaryTreeNode* node) {
        if (node == nullptr) return;

        // Find the leftmost node
        while (node && !node->leftThread)
            node = node->left;

        // Traverse in-order using threads
        while (node) {
            cout << node->data << " ";

            // If there is a thread to the right, follow the thread
            if (node->rightThread)
                node = node->right;
            else
                break;
        }
    }

    // Pre-order Traversal (recursive method)
    void preOrder(ThreadedBinaryTreeNode* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        if (!node->leftThread)
            preOrder(node->left);
        if (!node->rightThread)
            preOrder(node->right);
    }

public:
    ThreadedBinaryTree() : root(nullptr) {}

    void insert(int val) {
        insert(root, val);
    }

    void inOrderTraversal() {
        inOrder(root);
        cout << endl;
    }

    void preOrderTraversal() {
        preOrder(root);
        cout << endl;
    }
};

// Main function
int main() {
    ThreadedBinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order Traversal (Threaded): ";
    tree.inOrderTraversal();

    cout << "Pre-order Traversal: ";
    tree.preOrderTraversal();

    return 0;
}
