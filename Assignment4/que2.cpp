#include <iostream>
#define MAX 5
using namespace std;

class CircularQueue {
private:
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() : front(-1), rear(-1) {}

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1));
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
        } else {
            if (front == -1) {
                front = rear = 0;
            } else if (rear == MAX - 1 && front != 0) {
                rear = 0;
            } else {
                rear++;
            }
            arr[rear] = value;
            cout << value << " enqueued." << endl;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << arr[front] << " dequeued." << endl;
            if (front == rear) {
                front = rear = -1;
            } else if (front == MAX - 1) {
                front = 0;
            } else {
                front++;
            }
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            if (rear >= front) {
                for (int i = front; i <= rear; i++) {
                    cout << arr[i] << " ";
                }
            } else {
                for (int i = front; i < MAX; i++) {
                    cout << arr[i] << " ";
                }
                for (int i = 0; i <= rear; i++) {
                    cout << arr[i] << " ";
                }
            }
            cout << endl;
        }
    }
   void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
};

int main() {
    CircularQueue cq;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check if Empty\n";
        cout << "4. Check if Full\n";
        cout << "5. Display Queue\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cout << (cq.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 4:
                cout << (cq.isFull() ? "Queue is full." : "Queue is not full.") << endl;
                break;
            case 5:
                cq.display();
                break;
            case 6:
                cq.peek();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
