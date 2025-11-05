#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
public:
    int weight;
    int value;
    double ratio;

    Item(int w, int v) {
        weight = w;
        value = v;
        ratio = (double)v / w;
    }
};

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items;
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;
        items.push_back(Item(weight, value));
    }

    int capacity;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    // Sort items by ratio (value/weight) in descending order
    sort(items.begin(), items.end(), [](Item &a, Item &b) {
        return a.ratio > b.ratio;
    });

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    cout << "\nItems taken:\n";
    for (auto &item : items) {
        if (remainingCapacity == 0)
            break;

        if (item.weight <= remainingCapacity) {
            // Take whole item
            totalValue += item.value;
            remainingCapacity -= item.weight;
            cout << "Weight: " << item.weight
                 << " | Value: " << item.value
                 << " | Taken: 100%" << endl;
        } else {
            // Take fraction of item
            double fraction = (double)remainingCapacity / item.weight;
            totalValue += item.value * fraction;
            cout << "Weight: " << item.weight
                 << " | Value: " << item.value
                 << " | Taken: " << (fraction * 100) << "%" << endl;
            remainingCapacity = 0;
        }
    }

    cout << "\nMaximum total value in knapsack = " << totalValue << endl;
    return 0;
}
