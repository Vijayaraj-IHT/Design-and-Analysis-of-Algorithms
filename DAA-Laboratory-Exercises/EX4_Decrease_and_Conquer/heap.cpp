#include <iostream>
using namespace std;

void siftDown(int H[], int n, int k) {
    int v = H[k];
    while (2 * k <= n) {
        int j = 2 * k;
        if (j < n && H[j] < H[j + 1]) j++;
        if (v >= H[j]) break;
        H[k] = H[j];
        k = j;
    }
    H[k] = v;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: Array size must be positive." << endl;
        return 1;
    }

    int H[n + 1];
    cout << "Enter elements:\n";
    for (int i = 1; i <= n; i++) cin >> H[i];

    // Build Max Heap
    for (int i = n / 2; i >= 1; i--) siftDown(H, n, i);

    // Heap Sort
    for (int i = n; i > 1; i--) {
        swap(H[1], H[i]);
        siftDown(H, i - 1, 1);
    }

    cout << "Sorted Array: ";
    for (int i = 1; i <= n; i++) cout << H[i] << " ";

    return 0;
}