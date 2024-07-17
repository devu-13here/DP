#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertBeforeNode(Node*& head, int target, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) return;
    
    if (head->data == target) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != target) {
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAfterNode(Node* head, int target, int value) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }

    if (temp != nullptr) {
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFromBeginning(Node*& head) {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd(Node*& head) {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

void deleteSpecificNode(Node*& head, int target) {
    if (head == nullptr) return;

    if (head->data == target) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != target) {
        temp = temp->next;
    }
    if (temp->next != nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
}
int searchNode(Node* head, int value) {
    int position = 1;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1; // Not found
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main() {
    Node* head = nullptr;
    int choice, value, target;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert before a node\n";
        cout << "4. Insert after a node\n";
        cout << "5. Delete from the beginning\n";
        cout << "6. Delete from the end\n";
        cout << "7. Delete a specific node\n";
        cout << "8. Search for a node\n";
        cout << "9. Display all nodes\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;
            case 2:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                insertAtEnd(head, value);
                break;
            case 3:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter value to insert before " << target << ": ";
                cin >> value;
                insertBeforeNode(head, target, value);
                break;
            case 4:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter value to insert after " << target << ": ";
                cin >> value;
                insertAfterNode(head, target, value);
                break;
            case 5:
                deleteFromBeginning(head);
                break;
            case 6:
                deleteFromEnd(head);
                break;
            case 7:
                cout << "Enter value of the node to delete: ";
                cin >> target;
                deleteSpecificNode(head, target);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                target = searchNode(head, value);
                if (target != -1)
                    cout << "Node found at position: " << target << endl;
                else
                    cout << "Node not found" << endl;
                break;
            case 9:
                printList(head);
                break;
            case 10:
                // Free the allocated memory
                while (head != nullptr) {
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                }
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
