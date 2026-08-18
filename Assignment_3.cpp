#include <iostream> 
using namespace std; 
#define MAX 5 
class Queue{ 
private: 
   int queue[MAX]; 
   int front, rear; 
public: 
   Queue() 
   { 
       front = rear = -1; 
   } 
   void enqueue(int value) 
   { 
       if (rear == MAX - 1) 
       { 
           cout << "Queue Overflow!" << endl; 
           return; 
       } 
       if (front == -1) 
           front = 0; 
       rear++; 
       queue[rear] = value; 
       cout << value << " added to the queue." << endl; 
   } 
   void dequeue() 
   { 
       if (front == -1 || front > rear) 
       { 
           cout << "Queue Underflow!" << endl; 
           return; 
       } 
       cout << queue[front] << " served and removed from the queue." << endl; 
       front++; 
       if (front > rear) 
       { 
           front = rear = -1; 
       } 
   } 
   void display() 
   { 
       if (front == -1) 
       { 
           cout << "Queue is Empty!" << endl; 
           return; 
       } 
       cout << "Customers in Queue: "; 
       for (int i = front; i <= rear; i++) 
       { 
           cout << queue[i] << " "; 
       } 
       cout << endl; 
   } 
}; 
int main() 
{ 
   Queue q; 
   int choice, customer; 
   do 
   { 
       cout << " om kutwal sy-12 roll no=70"; 
       cout << "\n===== Ticket Booking Queue ====="; 
       cout << "\n1. Enqueue Customer"; 
       cout << "\n2. Dequeue Customer"; 
       cout << "\n3. Display Queue"; 
       cout << "\n4. Exit"; 
       cout << "\nEnter your choice: "; 
       cin >> choice; 
       switch (choice) 
       { 
       case 1: 
           cout << "Enter Customer ID: "; 
           cin >> customer; 
           q.enqueue(customer); 
           break; 
       case 2: 
           q.dequeue(); 
           break; 
       case 3: 
           q.display(); 
           break; 
       case 4: 
           cout << "Exi ng Program..." << endl; 
           break; 
       default: 
           cout << "Invalid Choice!" << endl; 
       } 
   } while (choice != 4); 
   return 0; 
} 