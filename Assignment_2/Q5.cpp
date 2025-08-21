 

// Q. 5 Lost Package Tracker
// Problem Statement:
// A logistics company stores the scanned timestamps (in hours) of packages entering a warehouse in an
// array timestamps[]. Sometimes, a timestamp is repeated due to re-scanning.
// A package is considered "lost" if its ID (timestamp) is missing between two valid timestamps.
// Task:
// Given a sorted but incomplete list of timestamps from start to end, find the first missing timestamp in
// the range.
// Example:
// Input: timestamps = [1001, 1002, 1004, 1005]
// Output: 1003
 
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingTimestamps(vector<int>& timestamps) 
{
    vector<int> missingTimestamps;
    if (timestamps.empty()) {
        return missingTimestamps;
    }

    int start = timestamps[0];
    int end = timestamps.size() -1; // we can also use timestamps.back() for the last timestamp

    for (int i = start; i <= end; ++i) {
        if (find(timestamps.begin(), timestamps.end(), i) == timestamps.end()) {
            missingTimestamps.push_back(i);
        }
    }
    return missingTimestamps;
}
int main () 
{
    int n;
    cout << "Enter the number of timestamps: ";
    cin >> n;
    vector<int> timestamps (n);
    cout << "Enter the timestamps: ";
    for (int i = 0; i < n; i++) {
        cin >> timestamps[i];
    }
    sort(timestamps.begin(), timestamps.end());

    vector<int> missingTimestamps = findMissingTimestamps(timestamps);
    if (missingTimestamps.empty()) {
        cout << "No missing timestamps found." << endl;
    } else {
        cout << "Missing timestamps: ";
        for (int ts : missingTimestamps) {
            cout << ts << " ";
        }
        cout << endl;
    }

    return 0 ;
}