#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = NULL; }

    void addAtBeg(char x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    }

    void append(char x) { 
        // Implementation here 
    }

    void addAtPOS(char x, int pos) { 
        // Implementation here 
    }

    void display() { 
        // Implementation here 
    }

    void removeFirst() { 
        // Implementation here 
    }

    void removeLast() { 
        // Implementation here 
    }

    void removePOS(int pos) { 
        // Implementation here 
    }
};

int main() {
    LinkedList list;
    list.addAtBeg('A');
    list.append('B');
    list.display();
    return 0;
}
