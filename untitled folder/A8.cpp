#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char name[50];
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() { head = NULL; }

    // 1. Add at Beginning
    void addAtBeg(char name[]) {
        Node* newNode = new Node();
        strcpy(newNode->name, name);
        newNode->next = head;
        head = newNode;
    }

    // 2. Append at End
    void append(char name[]) {
        Node* newNode = new Node();
        strcpy(newNode->name, name);
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 3. Add at Position
    void addAtPOS(char name[], int pos) {
        Node* newNode = new Node();
        strcpy(newNode->name, name);
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 4. Display
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // 5. Remove First Node
    void removeFirst() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // 6. Remove Last Node
    void removeLast() {
        if (head == NULL) return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // 7. Remove Node at Position
    void removePOS(int pos) {
        if (pos == 1) {
            removeFirst();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp != NULL && temp->next != NULL) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }
};

int main() {
    LinkedList list;
    list.addAtBeg("Alice");
    list.append("Bob");
    list.addAtPOS("Charlie", 2);
    list.display();
    list.removeFirst();
    list.display();
    list.removeLast();
    list.display();
    list.removePOS(1);
    list.display();
    return 0;
}
