#include "../include/tree.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void showHelp() {
    cout << "\n=== Commands ===" << endl;
    cout << "PUSH <n> - insert number n" << endl;
    cout << "POP <n> - remove number n" << endl;
    cout << "FIND <n> - search for number n" << endl;
    cout << "PRINT - print inorder" << endl;
    cout << "PRE - print preorder" << endl;
    cout << "POST - print postorder" << endl;
    cout << "HELP - show this help" << endl;
    cout << "CLEAR - clear tree" << endl;
    cout << "EXIT - exit program" << endl;
}

int main() {
    BinaryTree tree;
    string line;
    
    cout << "Binary Tree Console" << endl;
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
        else if (cmd == "PUSH") {
            int n;
            if (ss >> n) {
                tree.insert(n);
                cout << "Inserted " << n << endl;
            } else {
                cout << "Usage: PUSH <number>" << endl;
            }
        }
        else if (cmd == "POP" || cmd == "REMOVE") {
            int n;
            if (ss >> n) {
                if (tree.remove(n)) {
                    cout << "Removed " << n << endl;
                } else {
                    cout << n << " not found" << endl;
                }
            } else {
                cout << "Usage: POP <number>" << endl;
            }
        }
        else if (cmd == "FIND" || cmd == "SEARCH") {
            int n;
            if (ss >> n) {
                cout << n << (tree.search(n) ? " found" : " not found") << endl;
            } else {
                cout << "Usage: FIND <number>" << endl;
            }
        }
        else if (cmd == "PRINT" || cmd == "INORDER") {
            cout << "Inorder: ";
            tree.printInorder();
        }
        else if (cmd == "PRE" || cmd == "PREORDER") {
            cout << "Preorder: ";
            tree.printPreorder();
        }
        else if (cmd == "POST" || cmd == "POSTORDER") {
            cout << "Postorder: ";
            tree.printPostorder();
        }
        else if (cmd == "SORT") {
            cout << "Sorted: ";
            tree.sort();
        }
        else if (cmd == "CLEAR") {
            tree.~BinaryTree();
            new (&tree) BinaryTree();
            cout << "Tree cleared" << endl;
        }
        else {
            cout << "Unknown command: " << cmd << ". Type HELP for commands" << endl;
        }
    }
    
    return 0;
}
