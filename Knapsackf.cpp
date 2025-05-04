#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an item
struct Item {
    int value;
    int weight;
    double ratio;
};

// Function to compare two items based on their value/weight ratio
bool compare(Item a, Item b) {
    return (a.ratio > b.ratio);
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int W, vector<Item>& items) {
    // Sorting items by their value/weight ratio in decreasing order
    for (auto& item : items) {
        item.ratio = (double)item.value / item.weight;
    }
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;  // Total value accumulated in the knapsack
    for (auto& item : items) {
        if (W >= item.weight) {
            // If the knapsack can accommodate the whole item
            W -= item.weight;
            totalValue += item.value;
        } else {
            // If the knapsack cannot accommodate the whole item, take the fraction
            totalValue += item.value * ((double)W / item.weight);
            break;  // Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    vector<Item> items(n);
    cout << "Enter the value and weight of each item: \n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
