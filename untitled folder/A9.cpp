#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class OddEvenList {
public:
    Node* head;

    OddEvenList() { head = NULL; }

    // 1. Insert element at the correct position (odd or even)
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        if (value % 2 != 0) {
            // Add odd number at the beginning
            newNode->next = head;
            head = newNode;
        } else {
            // Add even number at the end
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // 2. Display the list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    OddEvenList list;
    list.insert(1);
    list.insert(4);
    list.insert(3);
    list.insert(2);
    list.insert(5);
    list.display();
    return 0;
}
