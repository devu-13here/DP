#include <iostream>
#define MAX 5

using namespace std;
class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
        } else {
            if (front == -1) front = 0;
            arr[++rear] = value;
            cout << value << " enqueued." << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << arr[front++] << " dequeued." << endl;
            if (front > rear) front = rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            for (int i = front; i <= rear; ++i) {
                cout << arr[i] << " ";
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
    Queue q;
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
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << (q.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 4:
                cout << (q.isFull() ? "Queue is full." : "Queue is not full.") << endl;
                break;
            case 5:
                q.display();
                break;
            case 6:
                q.peek();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
