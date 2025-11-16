#include <iostream>
#include <queue>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

/*
    For a DFS traversal, there are three main types:
    1. Pre-order:  Process the current node, then go to the left child, then the right child. (Node -> Left -> Right)
    2. In-order:   Go to the left child, process the current node, then go to the right child. (Left -> Node -> Right)
                     For a Binary Search Tree, this gives you the nodes in sorted order.
    3. Post-order: Go to the left child, then the right child, then process the current node. (Left -> Right -> Node)
                     This is often used for deleting nodes in a tree.
*/

void preorder_dfs(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder_dfs(root->left);
    preorder_dfs(root->right);
}

void inorder_dfs(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder_dfs(root->left);
    cout << root->data << " ";
    inorder_dfs(root->right);
}

void postorder_dfs(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder_dfs(root->left);
    postorder_dfs(root->right);
    cout << root->data << " ";
}

void bfs(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}



int main() {
    /*
        Let's create a simple tree:
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

    cout << "Pre-order traversal (Node-Left-Right): ";
    preorder_dfs(root);
    cout << endl;

    cout << "In-order traversal (Left-Node-Right):  ";
    inorder_dfs(root);
    cout << endl;

    cout << "Post-order traversal (Left-Right-Node):";
    postorder_dfs(root);
    cout << endl;

    cout << "BFS (Level-Order) traversal:       ";
    bfs(root);
    cout << endl;

    return 0;
}
