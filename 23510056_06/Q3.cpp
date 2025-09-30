#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Startup {
    string name;
    int deadline;
    int profit;
};

// Comparator to sort by profit descending
bool cmp(Startup a, Startup b) {
    return a.profit > b.profit;
}

pair<int, vector<string>> jobSequencing(vector<Startup>& startups, int total_slots) {
    sort(startups.begin(), startups.end(), cmp);

    vector<string> slots(total_slots, "Empty");
    int total_profit = 0;

    for (auto s : startups) {
        // Find a free slot for this startup (from min(deadline, total_slots) - 1 down to 0)
        for (int j = min(total_slots, s.deadline) - 1; j >= 0; j--) {
            if (slots[j] == "Empty") {
                slots[j] = s.name;
                total_profit += s.profit;
                break;
            }
        }
    }

    return {total_profit, slots};
}

int main() {
    int total_slots = 10;
    vector<Startup> startups = {
        {"S1", 2, 300}, {"S2", 1, 200}, {"S3", 3, 180}, {"S4", 2, 400},
        {"S5", 1, 250}, {"S6", 3, 100}, {"S7", 4, 500}, {"S8", 2, 150},
        {"S9", 3, 220}, {"S10", 4, 330}
        // Add up to 50 startups as needed
    };

    auto result = jobSequencing(startups, total_slots);

    cout << "Maximum Total Profit: " << result.first << endl;
    cout << "Scheduled Startups (Slot-wise):" << endl;
    for (int i = 0; i < total_slots; i++) {
        cout << "Slot " << i+1 << ": " << result.second[i] << endl;
    }

    return 0;
}
