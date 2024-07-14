#include <iostream>
using namespace std;

void spiral_print(int matrix[][100], int n) {
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i)
            cout << matrix[top][i] << " ";
        ++top;

        for (int i = top; i <= bottom; ++i)
            cout << matrix[i][right] << " ";
        --right;

        if (top <= bottom) {
            for (int i = right; i >= left; --i)
                cout << matrix[bottom][i] << " ";
            --bottom;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                cout << matrix[i][left] << " ";
            ++left;
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

    cout << "Spiral form: ";
    spiral_print(matrix, n);
    return 0;
}
