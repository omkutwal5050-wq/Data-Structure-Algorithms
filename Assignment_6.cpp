#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// Node structure
struct Node {
    int employeeID;
    Node* left;
    Node* right;

    Node(int id) {
        employeeID = id;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int id) {
    if (root == nullptr) {
        return new Node(id);
    }

    if (id < root->employeeID) {
        root->left = insert(root->left, id);
    }
    else if (id > root->employeeID) {
        root->right = insert(root->right, id);
    }
    else {
        cout << "Duplicate Employee ID " << id
             << " is not allowed.\n";
    }

    return root;
}

// Display tree level-wise
// Om kutwal SY-12 Roll No. 70
void levelOrder(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    int level = 0;

    while (!q.empty()) {
        int size = q.size();

        cout << "Level " << level << ": ";

        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();

            cout << current->employeeID << " ";

            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }

        cout << endl;
        level++;
    }
}

// Find height of BST
int height(Node* root) {
    if (root == nullptr)
        return -1;

    return 1 + max(height(root->left),
                   height(root->right));
}

// Display leaf nodes
void displayLeafNodes(Node* root) {
    if (root == nullptr)
        return;

    // A node with no left and right child is a leaf node
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->employeeID << " ";
        return;
    }

    displayLeafNodes(root->left);
    displayLeafNodes(root->right);
}

// Main function
int main() {
    Node* root = nullptr;

    int n, id;

    // Input number of employees
    cout << "Enter number of employees: ";
    cin >> n;

    // Input employee IDs
    cout << "Enter " << n << " Employee IDs:\n";

    for (int i = 0; i < n; i++) {
        cin >> id;
        root = insert(root, id);
    }

    // Display original tree
    cout << "\n===== ORIGINAL BST =====\n";

    cout << "\nOriginal Tree Level-wise:\n";
    levelOrder(root);

    // Insert new employee
    int newID;

    cout << "\nEnter new Employee ID to insert: ";
    cin >> newID;

    root = insert(root, newID);

    // Display new tree
    cout << "\n===== NEW BST =====\n";

    cout << "\nNew Tree Level-wise:\n";
    levelOrder(root);

    // Display height
    cout << "\nHeight of the tree: "
         << height(root) << " edges\n";

    // Display leaf nodes
    cout << "\nLeaf Nodes (Employees with no subordinates): ";
    displayLeafNodes(root);

    cout << endl;
}