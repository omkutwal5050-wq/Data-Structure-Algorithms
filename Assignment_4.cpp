#include <iostream>  
using namespace std;  
struct Node  
{  
int data;  
Node *next;  
};  
Node *head = NULL;  
// Insert at beginning  
void insertBeginning(int value)  
{  
Node *newNode = new Node;  
newNode->data = value;  
newNode->next = head;  
head = newNode;  
cout << "Book ID " << value << " inserted at beginning.\n";  
}  
// Insert at end  
void insertEnd(int value)  
{  
Node *newNode = new Node;  
newNode->data = value;  
newNode->next = NULL;  
if (head == NULL)  
{  
head = newNode;  
    }  
    else  
    {  
        Node *temp = head;  
        while (temp->next != NULL)  
        {  
            temp = temp->next;  
        }  
        temp->next = newNode;  
    }  
  
    cout << "Book ID " << value << " inserted at end.\n";  
}  
  
// Delete from beginning  
void deleteBeginning()  
{  
    if (head == NULL)  
    {  
        cout << "Library list is empty.\n";  
        return;  
    }  
  
    Node *temp = head;  
    cout << "Deleted Book ID: " << temp->data << endl;  
    head = head->next;  
    delete temp;  
}  
  
// Display list  
void display()  
{  
    if (head == NULL)  
    {  
        cout << "Library list is empty.\n";  
        return;  
    }  
  
    cout << "Book IDs in library: ";  
  
    Node *temp = head;  
    while (temp != NULL)  
    {  
        cout << temp->data;  
  
        if (temp->next != NULL)  
            cout << " -> ";  
  
        temp = temp->next;  
    }  
  
    cout << " -> NULL" << endl;  
}  
  
int main()  
{  
    int choice, value;  
  
    do  
    {  
        cout << "om kutwal sy-12 roll no.70"; 
        cout << "\n===== Library Book Management =====\n";  
        cout << "1. Insert at Beginning\n";  
        cout << "2. Insert at End\n";  
        cout << "3. Delete from Beginning\n";  
        cout << "4. Display\n";  
        cout << "5. Exit\n";  
        cout << "Enter your choice: ";  
  
        cin >> choice;  
  
        switch (choice)  
        {  
        case 1:  
            cout << "Enter Book ID: ";  
            cin >> value;  
            insertBeginning(value);  
            break;  
  
        case 2:  
            cout << "Enter Book ID: ";  
            cin >> value;  
            insertEnd(value);  
            break;  
  
        case 3:  
            deleteBeginning();  
            break;  
  
        case 4:  
            display();  
            break;  
  
        case 5:  
            cout << "Exi ng program...\n";  
            break;  
  
default:  
cout << "Invalid choice! Please enter a number between 1 and 5.\n";  
}  
} while (choice != 5);  
return 0;  
}