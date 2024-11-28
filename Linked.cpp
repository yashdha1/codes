#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Singly Linked List class
class SinglyLinkedList {
    Node* head;

public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
    }

    // Function to create a new node
    Node* createNode(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to insert a node at the front
    void insertFront(int value) {
        Node* newNode = createNode(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a node at the rear
    void insertRear(int value) {
        Node* newNode = createNode(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to insert a node after a specific location
    void insertAfter(int value, int location) {
        Node* temp = head;
        while (temp != nullptr && temp->data != location) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Location not found." << endl;
            return;
        }
        Node* newNode = createNode(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete the first node
    void deleteFirst() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to delete the last node
    void deleteLast() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Function to delete a node after a specific location
    void deleteAfter(int location) {
        Node* temp = head;
        while (temp != nullptr && temp->data != location) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Location not found or no node to delete after." << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }};

int main() {
    SinglyLinkedList list;
    list.insertRear(10);
    list.insertRear(20);
    list.insertRear(30);
    list.display();
    list.insertFront(5);
    list.display();
    list.insertAfter(15, 10);
    list.display();
    list.deleteFirst();
    list.display();
    list.deleteLast();
    list.display();
    list.deleteAfter(10);
    list.display();
    return 0;
}