#include <iostream>
using namespace std;

void common_elements(int arr1[], int size1, int arr2[], int size2) {
    cout << "Common elements: ";
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
                break;
            }
        }
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {4, 5, 6, 7, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    common_elements(arr1, size1, arr2, size2);
    return 0;
}
