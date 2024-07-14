#include <iostream>
using namespace std;

void multiply_matrices(int matrix1[][100], int matrix2[][100], int result[][100], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[100][100], matrix2[100][100], result[100][100], n;
    cout << "Enter the size of the matrices: ";
    cin >> n;
    cout << "Enter the elements of the first matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix1[i][j];
    cout << "Enter the elements of the second matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix2[i][j];

    multiply_matrices(matrix1, matrix2, result, n);

    cout << "Resultant matrix after multiplication:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
