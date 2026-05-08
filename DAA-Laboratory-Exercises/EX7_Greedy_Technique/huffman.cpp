#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root) return;
    if (root->ch != '$') {
        cout << root->ch << ": " << code << endl;
    }
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void HuffmanCodes(vector<char>& data, vector<int>& freq, int n) {
    priority_queue<Node*, vector<Node*>, compare> pq;
    for (int i = 0; i < n; ++i) {
        pq.push(new Node(data[i], freq[i]));
    }
    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *merged = new Node('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    printCodes(pq.top(), "");
}

int main() {
    int n;
    cout << "Enter the number of characters to be Coded : ";
    cin >> n;

    vector<char> arr(n);
    vector<int> freq(n);

    for(int i = 0; i < n; i++) {
        cout << "Enter the Character and Frequency with spaces : ";
        cin >> arr[i] >> freq[i];
    }

    HuffmanCodes(arr, freq, n);
    return 0;
}