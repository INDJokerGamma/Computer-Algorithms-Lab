// Q) Given a sorted array of string which is interspersed with empty string, write a method to find the
// location of a given string.
// EXAMPLE
// Input: find “ball” in {“at”, “”, “”, “ball”, “”, “”, “car”, “”, “”, “dad”, “”,””}
// Output: 4

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int sparseSearch(const vector<string>& arr, int left, int right, const string& target) {
    if (left > right) return -1;                // Base case: range empty
    int mid = (left + right) / 2;
    // If mid is empty, find the nearest non-empty string
    if (arr[mid].empty()) {
        int l = mid - 1, r = mid + 1;
        while (l >= left || r <= right) {
            if (l >= left && !arr[l].empty()) {
                mid = l; 
                break;
            }
            if (r <= right && !arr[r].empty()) {
                mid = r;
                break;
            }
            l--; r++;
        }
        // If no non-empty string found
        if (arr[mid].empty()) return -1;
    }
    // Compare and continue binary search
    if (arr[mid] == target) {
        return mid;
    } 
    else if (arr[mid] > target) {
        return sparseSearch(arr, left, mid - 1, target);
    } else {
        return sparseSearch(arr, mid + 1, right, target);
    }
}

int main()
{
    vector<string> words = {"at", "", "", "ball", "", "", "car", "", "", "dad", "", "", ""};
    string required = "ball";

    int index = sparseSearch(words,0,12,required);
    if(index!=-1)
    cout<<words[index]<<" Found at index "<<index<<endl;
    else
    cout << "Not Found" << endl;
    return 0;
}
