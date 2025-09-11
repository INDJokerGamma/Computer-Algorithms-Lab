#include <iostream>
#include <vector>
using namespace std;

void findSignalDrops(vector<int>& signal) {
    int n = signal.size();
    int count = 0;
    vector<int> temp; // store current decreasing subsequence

    temp.push_back(signal[0]);

    for (int i = 1; i < n; i++) {
        if (signal[i] < signal[i - 1]) {
            temp.push_back(signal[i]);
        } else {
            if (temp.size() >= 3) {
                count++;
                cout << "Drop " << count << ": ";
                for (int val : temp) cout << "-> "<<val << " ";
                cout << endl;
            }
            temp.clear();
            temp.push_back(signal[i]);
        }
    }

    // check last run
    if (temp.size() >= 3) {
        count++;
        cout << "Drop " << count << ": ";
        for (int val : temp) cout << val << " ";
        cout << endl;
    }

    cout << "Total Drops = " << count << endl;
}

int main() {
    vector<int> signal = {5, 4, 3, 6, 7, 4, 3, 2};
    findSignalDrops(signal);
    return 0;
}
