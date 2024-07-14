#include <iostream>
using namespace std;

void zigzag_print(int matrix[][100], int n) {
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
        } else {
            for (int j = n - 1; j >= 0; --j)
                cout << matrix[i][j] << " ";
        }
    }
    cout << endl;
}

int main() {
    int matrix[100][100], n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    cout << "Zig Zag form: ";
    zigzag_print(matrix, n);
    return 0;
}
