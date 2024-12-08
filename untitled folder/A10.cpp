#include <iostream>
#include <cstring>
using namespace std;

struct Contact {
    char name[50];
    char mobile[15];
    Contact* next;
};

class ContactList {
public:
    Contact* head;

    ContactList() { head = NULL; }

    // 1. Add Contact at the Beginning
    void addContact(char name[], char mobile[]) {
        Contact* newContact = new Contact();
        strcpy(newContact->name, name);
        strcpy(newContact->mobile, mobile);
        newContact->next = head;
        head = newContact;
    }

    // 2. Display Contacts
    void displayContacts() {
        Contact* temp = head;
        while (temp != NULL) {
            cout << "Name: " << temp->name << ", Mobile: " << temp->mobile << endl;
            temp = temp->next;
        }
    }

    // 3. Remove Contact from Beginning
    void removeFirstContact() {
        if (head == NULL) return;
        Contact* temp = head;
        head = head->next;
        delete temp;
    }

    // 4. Remove Contact from End
    void removeLastContact() {
        if (head == NULL) return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Contact* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // 5. Remove Contact at Position
    void removeContactAtPos(int pos) {
        if (pos == 1) {
            removeFirstContact();
            return;
        }
        Contact* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp != NULL && temp->next != NULL) {
            Contact* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }
};

int main() {
    ContactList contacts;
    contacts.addContact("Alice", "1234567890");
    contacts.addContact("Bob", "9876543210");
    contacts.addContact("Charlie", "4567891230");
    contacts.displayContacts();
    contacts.removeFirstContact();
    contacts.displayContacts();
    contacts.removeLastContact();
    contacts.displayContacts();
    contacts.removeContactAtPos(1);
    contacts.displayContacts();
    return 0;
}
