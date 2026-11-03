/* Student Admission Record Management using Binary Search Tree */
#include<iostream>
#include<string>
using namespace std;

// Structure for a tree node (student record)
struct Node {
    int rollNo;
    string name;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int roll, string studentName) {
    Node* newNode = new Node;
    newNode->rollNo = roll;
    newNode->name = studentName;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert record into Binary Search Tree (based on roll number)
Node* insert(Node* root, int roll, string studentName) {
    if (root == NULL) {
        return createNode(roll, studentName);
    }
    if (roll < root->rollNo) {
        root->left = insert(root->left, roll, studentName);
    } else if (roll > root->rollNo) {
        root->right = insert(root->right, roll, studentName);
    } else {
        cout << "Roll number already exists. Duplicate not allowed.\n";
    }
    return root;
}

// ---------- Simple stack of Node pointers (array based) ----------
#define MAX 100

struct Stack {
    Node* arr[MAX];
    int top;
};

void initStack(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}

void push(Stack &s, Node* n) {
    if (s.top == MAX - 1) {
        cout << "Stack Overflow!\n";
        return;
    }
    s.arr[++s.top] = n;
}

Node* pop(Stack &s) {
    if (isEmpty(s)) {
        return NULL;
    }
    return s.arr[s.top--];
}

// ---------- Non-recursive Inorder Traversal (Left -> Root -> Right) ----------
void inorderNonRecursive(Node* root) {
    if (root == NULL) {
        cout << "No records available.\n";
        return;
    }
    Stack s;
    initStack(s);
    Node* curr = root;

    while (curr != NULL || !isEmpty(s)) {
        // Go to the leftmost node
        while (curr != NULL) {
            push(s, curr);
            curr = curr->left;
        }
        // Visit the node
        curr = pop(s);
        cout << "Roll No: " << curr->rollNo << "  Name: " << curr->name << endl;
        // Move to right subtree
        curr = curr->right;
    }
}

// ---------- Non-recursive Preorder Traversal (Root -> Left -> Right) ----------
void preorderNonRecursive(Node* root) {
    if (root == NULL) {
        cout << "No records available.\n";
        return;
    }
    Stack s;
    initStack(s);
    Node* curr = root;

    while (curr != NULL || !isEmpty(s)) {
        // Visit node and keep going left
        while (curr != NULL) {
            cout << "Roll No: " << curr->rollNo << "  Name: " << curr->name << endl;
            push(s, curr);
            curr = curr->left;
        }
        // Backtrack and move to right subtree
        curr = pop(s);
        curr = curr->right;
    }
}

// Main Function
int main() {
    Node* root = NULL;
    int choice, roll;
    string name;

    do {
        cout << "om kutwal sy-12 roll no.70";
        cout << "\n===== Student Admission Record Management =====\n";
        cout << "1. Insert Student Record\n";
        cout << "2. Inorder Traversal (Non-Recursive)\n";
        cout << "3. Preorder Traversal (Non-Recursive)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> roll;
                cout << "Enter Student Name: ";
                cin >> name;
                root = insert(root, roll, name);
                cout << "Record processed successfully.\n";
                break;
            case 2:
                cout << "\nInorder Traversal (sorted by roll number):\n";
                inorderNonRecursive(root);
                break;
            case 3:
                cout << "\nPreorder Traversal:\n";
                preorderNonRecursive(root);
                break;
            case 4:
                cout << "Program Terminated.\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 4);

    return 0;
}