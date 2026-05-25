#ifndef QUEUE_H
#define QUEUE_H
struct QueueNode {
    int data;
    QueueNode* next;
    QueueNode(int val);
};
class Queue {
private:
    QueueNode* front;
    QueueNode* rear;
    int count;
    
public:
    Queue();
    ~Queue();
    void enqueue(int value);
    bool dequeue();
    bool search(int value);
    int size() const;
    bool isEmpty() const;
    void clear();
};
#endif
