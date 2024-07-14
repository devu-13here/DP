#include <iostream>
using namespace std;

void transpose_matrix(int matrix[][100], int transpose[][100], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix[100][100], transpose[100][100], n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    transpose_matrix(matrix, transpose, n);

    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
