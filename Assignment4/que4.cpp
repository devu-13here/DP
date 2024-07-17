#include <iostream>
using namespace std;

#define MAX_CHAR 26
#define MAX_SIZE 1000 // assuming the string won't exceed 1000 characters

class SimpleQueue {
private:
    char queue[MAX_SIZE];
    int front;
    int rear;

public:
    SimpleQueue() : front(0), rear(0) {}

    void push(char x) {
        if (rear < MAX_SIZE) {
            queue[rear++] = x;
        }
    }

    void pop() {
        if (front < rear) {
            front++;
        }
    }

    char frontElement() {
        if (front < rear) {
            return queue[front];
        }
        return '\0';
    }

    bool empty() {
        return front == rear;
    }
};

void findFirstNonRepeating(string str) {
    SimpleQueue q;
    int freq[MAX_CHAR] = {0};

    for (char c : str) {
        freq[c - 'a']++;
        q.push(c);

        while (!q.empty() && freq[q.frontElement() - 'a'] > 1) {
            q.pop();
        }

        if (!q.empty()) {
            cout << q.frontElement() << " ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    findFirstNonRepeating(str);

    return 0;
}
