#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void interleaveQueue(queue<int>& q) {
    if (q.size() % 2 != 0) {
        cout << "Queue length is not even." << endl;
        return;
    }

    int halfSize = q.size() / 2;
    stack<int> s;

    // Push the first half elements of the queue into the stack
    for (int i = 0; i < halfSize; ++i) {
        s.push(q.front());
        q.pop();
    }

    // Enqueue the elements of the stack back into the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Dequeue the first half elements and enqueue them back
    for (int i = 0; i < halfSize; ++i) {
        q.push(q.front());
        q.pop();
    }

    // Again push the first half elements into the stack
    for (int i = 0; i < halfSize; ++i) {
        s.push(q.front());
        q.pop();
    }

    // Now interleave the elements of the stack and queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n, value;

    cout << "Enter the number of elements (even number): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "The number of elements must be even." << endl;
        return 1;
    }

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        q.push(value);
    }

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
