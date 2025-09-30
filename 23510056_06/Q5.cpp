#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int optimalMergeCost(vector<int>& logs) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Push all log sizes into min-heap
    for (int size : logs) {
        minHeap.push(size);
    }

    int total_cost = 0;

    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();

        int merge_cost = first + second;
        total_cost += merge_cost;

        minHeap.push(merge_cost);
    }

    return total_cost;
}

int main() {
    // Logs arrive in rounds
    vector<vector<int>> rounds = {
        {40, 120, 200, 10},
        {30, 15, 250, 90, 60},
        {100, 75, 35, 55, 85, 45},
        {500, 300, 150, 25, 70}
    };

    vector<int> all_logs;
    for (auto& round : rounds) {
        all_logs.insert(all_logs.end(), round.begin(), round.end());
    }

    int total_merge_cost = optimalMergeCost(all_logs);

    cout << "Total minimum merge cost: " << total_merge_cost << " MB" << endl;

    return 0;
}
