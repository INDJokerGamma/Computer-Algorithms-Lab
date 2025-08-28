#include <bits/stdc++.h>
using namespace std;

int findMaxInBitonicArray(vector<int>& arr) {

    int n = arr.size();
    int start = 0, end = n - 1;

    while (start <= end) 
    {
        int mid = start + (end - start) / 2;

        // Check if mid is peak
        if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == n - 1 || arr[mid] > arr[mid + 1])) 
            return arr[mid];

        // If mid is part of increasing sequence, move right
        else if (mid < n - 1 && arr[mid] < arr[mid + 1]) 
            start = mid + 1;
        
        // Else, move left
        else 
            end = mid - 1;
        
    }
    return -1; // should never reach here if input is valid bitonic
}

int main() {
    vector<int> arr = {1, 3, 8, 12, 9, 5, 2};
    cout << "Maximum element is: " << findMaxInBitonicArray(arr) << endl;
    return 0;
}
