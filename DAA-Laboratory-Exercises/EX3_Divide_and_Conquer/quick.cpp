#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// HoarePartition scheme
int hoarePartition(int A[], int l, int r) {
    int p = A[l];        // pivot
    int i = l - 1;
    int j = r + 1;

    while (true) {
        do {
            i++;
        } while (A[i] < p);

        do {
            j--;
        } while (A[j] > p);

        if (i >= j)
            return j;

        swap(A[i], A[j]);
    }
}

// Quicksort using Hoare partition
void quicksort(int A[], int l, int r) {
    if (l < r) {
        int s = hoarePartition(A, l, r);
        quicksort(A, l, s);
        quicksort(A, s + 1, r);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> A(n);

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout<<"\nBefore sorting :\t";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    quicksort(A.data(), 0, n - 1);
    cout<<"\nQuick sort for "<<n << "elements\n";
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}