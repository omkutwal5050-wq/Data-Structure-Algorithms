#include <iostream> 
#include <string> 
using namespace std; 
 
#define MAX 5 
 
class BookStack 
{ 
private: 
    string stack[MAX]; 
    int top; 
 
public: 
 
    BookStack() 
    { 
        top = -1; 
    } 
 
    void push(string book) 
    { 
        if (top == MAX - 1) 
        { 
            cout << "Shelf Overflow! No space available." << endl; 
            return; 
        } 
 
        top++; 
        stack[top] = book; 
 
        cout << "\"" << book << "\" inserted into shelf." << endl; 
    } 
 
    void pop() 
    { 
        if (top == -1) 
        { 
            cout << "Shelf Underflow! No books available." << endl; 
            return; 
        } 
 
        cout << "\"" << stack[top] << "\" removed from shelf." << endl; 
        top--; 
    } 
 
    void search(string book) 
    { 
        if (top == -1) 
        { 
            cout << "Shelf is Empty!" << endl; 
            return; 
        } 
 
        for (int i = top; i >= 0; i--) 
        { 
            if (stack[i] == book) 
            { 
                cout << "Book Found at Posi on " << i + 1 << endl; 
                return; 
            } 
        } 
 
        cout << "Book Not Found!" << endl; 
    } 
 
    void display() 
    { 
        if (top == -1) 
        { 
            cout << "Shelf is Empty!" << endl; 
            return; 
        } 
 
        cout << "\nBooks in Shelf (Top to Bo om):" << endl; 
 
        for (int i = top; i >= 0; i--) 
        { 
            cout << stack[i] << endl; 
        } 
    } 
}; 
 
int main() 
{ 
    BookStack shelf; 
 
    int choice; 
    string book; 
 
    do 
    { 
        cout << "om kutwal sy_12 roll 70 asg-2"; 
        cout << "\n===== BOOK SHELF USING STACK =====" << endl; 
        cout << "1. Insert Book" << endl; 
        cout << "2. Remove Book" << endl; 
        cout << "3. Search Book" << endl; 
        cout << "4. Display Shelf" << endl; 
        cout << "5. Exit" << endl; 
 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        cin.ignore(); 
 
        switch(choice) 
        { 
            case 1: 
 
                cout << "Enter Book Name: "; 
                getline(cin, book); 
 
                shelf.push(book); 
 
                break; 
 
            case 2: 
 
                shelf.pop(); 
 
                break; 
 
            case 3: 
 
                cout << "Enter Book Name to Search: "; 
                getline(cin, book); 
 
                shelf.search(book); 
 
                break; 
 
            case 4: 
 
                shelf.display(); 
 
                break; 
 
            case 5: 
 
                cout << "Exi ng Program..." << endl; 
 
                break; 
 
            default: 
 
                cout << "Invalid Choice!" << endl; 
        } 
 
    } while(choice != 5); 
 
    return 0; 
}