#include "stack.h"
StackNode::StackNode(int val) : data(val), next(nullptr) {}
Stack::Stack() : top(nullptr), count(0) {}
Stack::~Stack() {
    clear();
}
int Stack::topValue() const {
    if (isEmpty()) {
        throw "Stack is empty";
    }
    return top->data;
}

void Stack::print() {
    StackNode* current = top;
    cout << "Stack (top to bottom): ";
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void Stack::push(int value) {
    StackNode* newNode = new StackNode(value);
    newNode->next = top;
    top = newNode;
    count++;
}

bool Stack::pop() {
    if (isEmpty()) return false;
    
    StackNode* temp = top;
    top = top->next;
    delete temp;
    count--;
    return true;
}

bool Stack::search(int value) {
    StackNode* current = top;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

int Stack::size() const {
    return count;
}

bool Stack::isEmpty() const {
    return count == 0;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}
