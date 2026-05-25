#ifndef STACK_H
#define STACK_H

struct StackNode {
    int data;
    StackNode* next;
    StackNode(int val);
};

class Stack {
private:
    StackNode* top;
    int count;
    
public:
    Stack();
    ~Stack();  
    void push(int value);
    bool pop();
    bool search(int value);
    int size() const;
    bool isEmpty() const;
    void clear();
};

#endif
