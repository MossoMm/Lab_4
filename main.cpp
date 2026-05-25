#include "binary_tree.h"
#include "stack.h"
#include "queue.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void showHelp() {
    cout << "\nTree (BST)" << endl;
    cout << "INSERT <n>  - insert to tree" << endl;
    cout << "DELETE <n> - remove from tree" << endl;
    cout << "FIND <n> - search in tree" << endl;
    cout << "PRINT - print tree inorder" << endl;
    cout << "TREESIZE - tree size" << endl;
    cout << "TREECLEAR - clear tree" << endl;
    
    cout << "\nStack" << endl;
    cout << "PUSH <n> - push to stack" << endl;
    cout << "POP - pop from stack" << endl;
    cout << "PEEK <n> - search in stack" << endl;
    cout << "SHOW - print stack (top to bottom)" << endl;
    cout << "STACKSIZE   - stack size" << endl;
    cout << "STACKCLEAR  - clear stack" << endl;
    
    cout << "\nQueue" << endl;
    cout << "ENQUEUE <n> - enqueue to queue" << endl;
    cout << "DEQUEUE - dequeue from queue" << endl;
    cout << "FRONT <n> - search in queue" << endl;
    cout << "DISPLAY - print queue (front to rear)" << endl;
    cout << "QUEUESIZE - queue size" << endl;
    cout << "QUEUECLEAR - clear queue" << endl;
    
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
        string cmd;
        ss >> cmd;
        
        if (cmd == "EXIT" || cmd == "QUIT") {
            cout << "Goodbye!" << endl;
            break;
        }
        else if (cmd == "HELP") {
            showHelp();
        }

        else if (cmd == "INSERT") {
            int n;
            if (ss >> n) {
                tree.insert(n);
                cout << "Inserted " << n << " into tree" << endl;
            } else {
                cout << "Usage: INSERT <number>" << endl;
            }
        }
        else if (cmd == "DELETE") {
            int n;
            if (ss >> n) {
                if (tree.remove(n)) {
                    cout << "Removed " << n << " from tree" << endl;
                } else {
                    cout << n << " not found in tree" << endl;
                }
            } else {
                cout << "Usage: DELETE <number>" << endl;
            }
        }
        else if (cmd == "FIND") {
            int n;
            if (ss >> n) {
                cout << n << (tree.search(n) ? " found" : " not found") << " in tree" << endl;
            } else {
                cout << "Usage: FIND <number>" << endl;
            }
        }
        else if (cmd == "PRINT") {
            cout << "Tree (inorder): ";
            tree.print();
        }
        else if (cmd == "TREESIZE") {
            cout << "Tree size: " << tree.size() << endl;
        }
        else if (cmd == "TREECLEAR") {
            tree.clear();
            cout << "Tree cleared" << endl;
        }

        else if (cmd == "PUSH") {
            int n;
            if (ss >> n) {
                stack.push(n);
                cout << "Pushed " << n << " to stack" << endl;
            } else {
                cout << "Usage: PUSH <number>" << endl;
            }
        }
        else if (cmd == "POP") {
            if (stack.pop()) {
                cout << "Popped from stack" << endl;
            } else {
                cout << "Stack is empty" << endl;
            }
        }
        else if (cmd == "PEEK") {
            int n;
            if (ss >> n) {
                cout << n << (stack.search(n) ? " found" : " not found") << " in stack" << endl;
            } else {
                cout << "Usage: PEEK <number>" << endl;
            }
        }
        else if (cmd == "SHOW") {
            cout << "Stack (top to bottom): ";
            stack.print();
        }
        else if (cmd == "STACKSIZE") {
            cout << "Stack size: " << stack.size() << endl;
        }
        else if (cmd == "STACKCLEAR") {
            stack.clear();
            cout << "Stack cleared" << endl;
        }
        
        else if (cmd == "ENQUEUE") {
            int n;
            if (ss >> n) {
                queue.enqueue(n);
                cout << "Enqueued " << n << " to queue" << endl;
            } else {
                cout << "Usage: ENQUEUE <number>" << endl;
            }
        }
        else if (cmd == "DEQUEUE") {
            if (queue.dequeue()) {
                cout << "Dequeued from queue" << endl;
            } else {
                cout << "Queue is empty" << endl;
            }
        }
        else if (cmd == "FRONT") {
            int n;
            if (ss >> n) {
                cout << n << (queue.search(n) ? " found" : " not found") << " in queue" << endl;
            } else {
                cout << "Usage: FRONT <number>" << endl;
            }
        }
        else if (cmd == "DISPLAY") {
            cout << "Queue (front to rear): ";
            queue.print();
        }
        else if (cmd == "QUEUESIZE") {
            cout << "Queue size: " << queue.size() << endl;
        }
        else if (cmd == "QUEUECLEAR") {
            queue.clear();
            cout << "Queue cleared" << endl;
        }
        
        else {
            cout << "Unknown command. Type HELP" << endl;
        }
    }
    
    return 0;
}