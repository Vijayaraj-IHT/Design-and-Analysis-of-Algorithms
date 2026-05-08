#include <iostream>
using namespace std;

// Merge two sorted subarrays
// A[l..m] and A[m+1..r]
void merge(int A[], int l, int m, int r) {
    int p = m - l + 1;
    int q = r - m;

    // Create temp arrays
    int* B = new int[p];
    int* C = new int[q];

    // Copy data
    for (int i = 0; i < p; i++)
        B[i] = A[l + i];

    for (int j = 0; j < q; j++)
        C[j] = A[m + 1 + j];

    int i = 0, j = 0, k = l;

    // Merge temp arrays back into A
    while (i < p && j < q) {
        if (B[i] <= C[j]) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = C[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < p) {
        A[k] = B[i];
        i++;
        k++;
    }

    while (j < q) {
        A[k] = C[j];
        j++;
        k++;
    }

    delete[] B;
    delete[] C;
}

// MergeSort function
void mergeSort(int A[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);

        merge(A, l, m, r);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* A = new int[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout<<"\nBefore sorting :\t";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    mergeSort(A, 0, n - 1);
    cout<<"Merge sort for "<<n << "elements\n";
    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    delete[] A;
    return 0;
}