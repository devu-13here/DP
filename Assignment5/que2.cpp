#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int countAndDeleteOccurrences(Node*& head, int key) {
    int count = 0;
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->data == key) {
            count++;
            if (prev == nullptr) { 
                head = temp->next;
                delete temp;
                temp = head;
            } else { 
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    return count;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(1);
    cout << "Original list: ";
    printList(head);
    int key = 1;
    int count = countAndDeleteOccurrences(head, key);
    cout << "Number of occurrences of " << key << ": " << count << endl;
    cout << "List after deletion of " << key << ": ";
    printList(head)
    
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
