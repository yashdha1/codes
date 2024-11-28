#include <iostream>
 using namespace std;
 struct Node {
 int data;
 Node* next;
 };
 class Queue {
 private:
 Node* front;
 Node* rear;
 public:
 Queue() {
 front = nullptr;
 rear = nullptr;
 }
 void enqueue(int value) {
 Node* newNode = new Node();
 newNode->data = value;
 newNode->next = nullptr;
 if (rear == nullptr) {
 front = rear = newNode;
 cout << value << " enqueued to queue." << endl;
 return;
 }
 rear->next = newNode;
 rear = newNode;
 cout << value << " enqueued to queue." << endl;
 }
 void dequeue() {
 if (front == nullptr) {
 cout << "Queue Underflow! Cannot dequeue from empty queue." << endl;
 return;
 }
cout << front->data << " dequeued from queue." << endl;
 Node* temp = front;
 front = front->next;
 if (front == nullptr) {
 rear = nullptr;
 }
 delete temp;
 }
 void display() {
 if (front == nullptr) {
 cout << "Queue is empty." << endl;
 return;
 }
 Node* current = front;
 cout << "Queue elements: ";
 while (current != nullptr) {
 cout << current->data << " ";
 current = current->next;
 }
 cout << endl;
 }
 };
 int main() {
 Queue q;
 int choice, value;
 do {
 cout << "\nMenu:\n";
 cout << "1. Enqueue\n";
 cout << "2. Dequeue\n";
 cout << "3. Display\n";
 cout << "4. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << "Enter value to enqueue: ";
 cin >> value;
 q.enqueue(value);
 break;
 case 2:
 q.dequeue();
 break;
case 3:
 q.display();
 break;
 case 4:
 cout << "Exiting program." << endl;
 break;
 default:
 cout << "Invalid choice! Please try again." << endl;
 }
 } while (choice != 4);
 return 0;
 }