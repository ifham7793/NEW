#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    int comparisons = 0, swaps = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            comparisons++;
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swaps++;
            }
        }
    }
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    return 0;
}
