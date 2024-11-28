#include <iostream>
#define MAX 5
using namespace std;

class Queue {
    int data[MAX];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0; // Initialize for the first element
        } else {
            rear++;
        }
        data[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued: " << data[front] << endl;
        front++;
        if (front > rear) { // Reset when queue becomes empty
            front = rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60); // Attempt to enqueue beyond MAX
    q.display();

    return 0;
}
