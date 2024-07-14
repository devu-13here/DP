#include <iostream>
using namespace std;

int matrix_sum(int matrix[][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            sum += matrix[i][j];
    return sum;
}

void column_wise_sum(int matrix[][100], int n) {
    cout << "Column wise sum: ";
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += matrix[j][i];
        }
        cout << sum << " ";
    }
    cout << endl;
}

void row_wise_sum(int matrix[][100], int n) {
    cout << "Row wise sum: ";
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += matrix[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
}

int diagonal_sum(int matrix[][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += matrix[i][i];
    return sum;
}

int reverse_diagonal_sum(int matrix[][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += matrix[i][n - 1 - i];
    return sum;
}

void menu() {
    int matrix[100][100];
    int n;
    cout << "Enter the number of rows/columns for the square matrix: ";
    cin >> n;
    cout << "Enter the matrix elements row by row:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Sum of the matrix\n";
        cout << "2. Column wise sum of matrix\n";
        cout << "3. Row wise sum of matrix\n";
        cout << "4. Sum of diagonal elements\n";
        cout << "5. Sum of reverse diagonal elements\n";
        cout << "6. Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Sum of the matrix: " << matrix_sum(matrix, n) << endl;
                break;
            case 2:
                column_wise_sum(matrix, n);
                break;
            case 3:
                row_wise_sum(matrix, n);
                break;
            case 4:
                cout << "Sum of diagonal elements: " << diagonal_sum(matrix, n) << endl;
                break;
            case 5:
                cout << "Sum of reverse diagonal elements: " << reverse_diagonal_sum(matrix, n) << endl;
                break;
            case 6:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}
