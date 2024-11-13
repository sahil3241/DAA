#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int weight;
    int value;

    Item(int w, int v)
    {
        weight = w;
        value = v;
    }
};

bool compare(Item a, Item b)
{
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}

double fractionalKnapsack(int capacity, vector<Item> &items)
{
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    for (int i = 0; i < items.size(); i++)
    {
        if (capacity >= items[i].weight)
        {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main()
{
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<Item> items;
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++)
    {
        int weight, value;
        cin >> weight >> value;
        items.push_back(Item(weight, value));
    }

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}