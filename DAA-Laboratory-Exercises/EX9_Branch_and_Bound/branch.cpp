#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

// Item structure
struct Item {
    int weight;
    int value;
    int id;
    double ratio;

    Item(int w, int v, int i) {
        weight = w;
        value = v;
        id = i;
        ratio = (double)v / w;
    }
};

// Node in the Branch and Bound tree
struct Node {
    int level;
    int profit;
    int weight;
    double bound;

    // Max-heap based on bound
    bool operator<(const Node& other) const {
        return bound < other.bound;
    }
};

// Calculate upper bound using fractional knapsack
double getBound(Node u, int n, int W, vector<Item>& items) {
    if (u.weight >= W) return 0;

    double bound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;

    while (j < n && totalWeight + items[j].weight <= W) {
        totalWeight += items[j].weight;
        bound += items[j].value;
        j++;
    }

    if (j < n) {
        bound += (double)(W - totalWeight) * items[j].ratio;
    }

    return bound;
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<Item> items;

    for (int i = 0; i < n; i++) {
        int v, w;
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> v >> w;
        items.push_back(Item(w, v, i + 1));
    }

    // Sort items by value/weight ratio (descending)
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return b.ratio < a.ratio;
    });

    // Priority queue (max-heap by bound)
    priority_queue<Node> pq;

    // Root node
    Node u;
    u.level  = -1;
    u.profit =  0;
    u.weight =  0;
    u.bound  = getBound(u, n, W, items);
    pq.push(u);

    int maxProfit = 0;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.bound <= maxProfit) continue;

        int nextLevel = cur.level + 1;
        if (nextLevel == n) continue;

        // ---- Include item at nextLevel ----
        Node withItem;
        withItem.level  = nextLevel;
        withItem.profit = cur.profit + items[nextLevel].value;
        withItem.weight = cur.weight + items[nextLevel].weight;

        if (withItem.weight <= W && withItem.profit > maxProfit) {
            maxProfit = withItem.profit;
        }

        withItem.bound = getBound(withItem, n, W, items);
        if (withItem.bound > maxProfit) {
            pq.push(withItem);
        }

        // ---- Exclude item at nextLevel ----
        Node withoutItem;
        withoutItem.level  = nextLevel;
        withoutItem.profit = cur.profit;
        withoutItem.weight = cur.weight;
        withoutItem.bound  = getBound(withoutItem, n, W, items);

        if (withoutItem.bound > maxProfit) {
            pq.push(withoutItem);
        }
    }

    cout << "\nInitial Max Profit = " << maxProfit << endl;

    return 0;
}