#include "../include/tree.h"
#include "../include/stack.h"
#include "../include/queue.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void showHelp() {
    cout << "\nTree (BST)" << endl;
    cout << "TREE PUSH <n> - insert to tree" << endl;
    cout << "TREE POP <n> - remove from tree" << endl;
    cout << "TREE FIND <n> - search in tree" << endl;
    cout << "TREE PRINT - print tree inorder" << endl;
    
    cout << "\nStack" << endl;
    cout << "STACK PUSH <n> - push to stack" << endl;
    cout << "STACK POP - pop from stack" << endl;
    cout << "STACK FIND <n> - search in stack" << endl;
    cout << "STACK PRINT - print stack (top to bottom)" << endl;
    
    cout << "\nQueue" << endl;
    cout << "QUEUE PUSH <n> - enqueue" << endl;
    cout << "QUEUE POP - dequeue" << endl;
    cout << "QUEUE FIND <n> - search in queue" << endl;
    cout << "QUEUE PRINT - print queue (front to rear)" << endl;
    
    cout << "\nGeneral" << endl;
    cout << "HELP - show this help" << endl;
    cout << "EXIT - exit program" << endl;

}

void printStack(Stack& s) {
    Stack temp;
    int value;
    
    while (s.size() > 0) {
        cout << "Stack printing not fully implemented" << endl;
        return;
    }
}

int main() {
    BinaryTree tree;
    Stack stack;
    Queue queue;
    string line;
    
    cout << "Data Structures Console (Tree, Stack, Queue)" << endl;
    showHelp();
    
    while (true) {
        cout << "> ";
        getline(cin, line);
        if (line.empty()) continue;
        for (char &c : line) c = toupper(c);
        stringstream ss(line);
        string structure, cmd;
        ss >> structure >> cmd;
        if (structure == "EXIT" || structure == "QUIT") {
            cout << "Goodbye!" << endl;
            break;
        }
        else if (structure == "HELP") {
            showHelp();
        }
        
        else if (structure == "TREE") {
            if (cmd == "PUSH") {
                int n;
                if (ss >> n) {
                    tree.insert(n);
                    cout << "Inserted " << n << " into tree" << endl;
                } else {
                    cout << "Usage: TREE PUSH <number>" << endl;
                }
            }
            else if (cmd == "POP") {
                int n;
                if (ss >> n) {
                    if (tree.remove(n)) {
                        cout << "Removed " << n << " from tree" << endl;
                    } else {
                        cout << n << " not found in tree" << endl;
                    }
                } else {
                    cout << "Usage: TREE POP <number>" << endl;
                }
            }
            else if (cmd == "FIND") {
                int n;
                if (ss >> n) {
                    cout << n << (tree.search(n) ? " found" : " not found") << " in tree" << endl;
                } else {
                    cout << "Usage: TREE FIND <number>" << endl;
                }
            }
            else if (cmd == "PRINT") {
                cout << "Tree (inorder): ";
                tree.printInorder();
            }
            else {
                cout << "Unknown tree command. Use: PUSH, POP, FIND, PRINT" << endl;
            }
        }
        
        else if (structure == "STACK") {
            if (cmd == "PUSH") {
                int n;
                if (ss >> n) {
                    stack.push(n);
                    cout << "Pushed " << n << " to stack" << endl;
                } else {
                    cout << "Usage: STACK PUSH <number>" << endl;
                }
            }
            else if (cmd == "POP") {
                if (stack.pop()) {
                    cout << "Popped from stack" << endl;
                } else {
                    cout << "Stack is empty" << endl;
                }
            }
            else if (cmd == "FIND") {
                int n;
                if (ss >> n) {
                    cout << n << (stack.search(n) ? " found" : " not found") << " in stack" << endl;
                } else {
                    cout << "Usage: STACK FIND <number>" << endl;
                }
            }
            else if (cmd == "PRINT") {
                cout << "Stack (top to bottom): ";
                stack.print();
            }
            else if (cmd == "SIZE") {
                cout << "Stack size: " << stack.size() << endl;
            }
            else {
                cout << "Unknown stack command." << endl;
            }
        }
        
        else if (structure == "QUEUE") {
            if (cmd == "PUSH") {
                int n;
                if (ss >> n) {
                    queue.enqueue(n);
                    cout << "Enqueued " << n << " to queue" << endl;
                } else {
                    cout << "Usage: QUEUE PUSH <number>" << endl;
                }
            }
            else if (cmd == "POP") {
                if (queue.dequeue()) {
                    cout << "Dequeued from queue" << endl;
                } else {
                    cout << "Queue is empty" << endl;
                }
            }
            else if (cmd == "FIND") {
                int n;
                if (ss >> n) {
                    cout << n << (queue.search(n) ? " found" : " not found") << " in queue" << endl;
                } else {
                    cout << "Usage: QUEUE FIND <number>" << endl;
                }
            }
            else if (cmd == "PRINT") {
                cout << "Queue (front to rear): ";
                queue.print();
            }
            else if (cmd == "SIZE") {
                cout << "Queue size: " << queue.size() << endl;
            }
            else {
                cout << "Unknown queue command." << endl;
            }
        }
        
        else {
            cout << "Unknown structure. << endl;
        }
    }
    
    return 0;
}
