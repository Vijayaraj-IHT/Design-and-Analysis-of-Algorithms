#include <iostream>
using namespace std;

int main() {
    int i, j, n, v;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size! Please enter a value greater than 0." << endl;
        return 1;
    }

    int arr[n];
    cout << "Enter the array elements:" << endl;
    for(i=0; i<n; i++) cin >> arr[i];

    // Sorting Logic
    for(int i=1; i<=n-1; i++) {
        v = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > v) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = v;
    }

    cout << "Array after Insertion Sorting:" << endl;
    for(i=0; i<n; i++) cout << arr[i] << "\t";

    return 0;
}
