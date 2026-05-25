#include "queue.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
QueueNode::QueueNode(int val) : data(val), next(nullptr) {}
Queue::Queue() : front(nullptr), rear(nullptr), count(0) {}
Queue::~Queue() {
    clear();
}
void Queue::print() {
    QueueNode* current = front;
    cout << "Queue (front to rear): ";
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void Queue::enqueue(int value) {
    QueueNode* newNode = new QueueNode(value);
    
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}

bool Queue::dequeue() {
    if (isEmpty()) return false;
    
    QueueNode* temp = front;
    front = front->next;
    delete temp;
    count--;
    
    if (isEmpty()) rear = nullptr;
    return true;
}

bool Queue::search(int value) {
    QueueNode* current = front;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

int Queue::size() const {
    return count;
}

bool Queue::isEmpty() const {
    return count == 0;
}

void Queue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}
