#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Supply {
    string name;
    double weight;
    double value;
    bool divisible; // true if item can be fractionally taken
};

// Comparator for value/weight ratio
bool cmp(Supply a, Supply b) {
    double r1 = a.value / a.weight;
    double r2 = b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(double capacity, vector<Supply>& supplies, vector<pair<string, double>>& taken) {
    sort(supplies.begin(), supplies.end(), cmp);

    double total_value = 0;
    double current_weight = 0;

    for (auto s : supplies) {
        if (current_weight >= capacity) break;

        if (s.divisible) {
            double can_take = min(s.weight, capacity - current_weight);
            total_value += can_take * (s.value / s.weight);
            current_weight += can_take;
            taken.push_back({s.name, can_take});
        } else {
            if (current_weight + s.weight <= capacity) {
                total_value += s.value;
                current_weight += s.weight;
                taken.push_back({s.name, s.weight});
            }
        }
    }
    return total_value;
}

int main() {
    double helicopter_capacity = 1000;

    vector<Supply> supplies = {
        {"Rice", 100, 500, true},
        {"Medicine", 50, 400, false},
        {"Water", 200, 600, true},
        {"Blankets", 150, 450, false},
        {"Tents", 300, 800, false},
        {"Wheat", 120, 300, true},
        {"Sugar", 80, 250, true},
        {"Oxygen", 60, 700, false},
        {"Milk", 90, 350, true},
        {"FirstAid", 40, 500, false}
        // Add up to 100 items as needed
    };

    vector<pair<string, double>> taken;
    double max_value = fractionalKnapsack(helicopter_capacity, supplies, taken);

    cout << "Maximum value loaded: " << max_value << endl;
    cout << "Items taken (weight considered):" << endl;
    for (auto t : taken) {
        cout << t.first << ": " << t.second << " kg" << endl;
    }

    return 0;
}
