#include <iostream>
#include <vector>
#include <algorithm> // For sort

using namespace std;

pair<int, vector<int>> greedyContainerLoading(vector<int>& weights, int capacity) {
    // Sort luggage in ascending order
    sort(weights.begin(), weights.end());

    int current_load = 0;
    vector<int> loaded_families;

    for (int w : weights) {
        if (current_load + w <= capacity) {
            loaded_families.push_back(w);
            current_load += w;
        } else {
            break; // Cannot load more luggage
        }
    }

    return {current_load, loaded_families};
}

int main() {
    int bus_capacity = 5000;
    vector<int> families_luggage = {45, 120, 300, 150, 90, 600, 75, 430, 250, 500,
                                    60, 100, 700, 85, 95, 200, 320, 180, 150, 275};

    auto result = greedyContainerLoading(families_luggage, bus_capacity);

    cout << "Total luggage loaded: " << result.first << endl;
    cout << "Families' luggage loaded: ";
    for (int w : result.second) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}
