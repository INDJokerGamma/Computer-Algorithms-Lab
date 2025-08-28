// Write a method to sort an array of string so that all the anagrams are next to each other
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;

    for (const string& str : strs) {
        string key = str;
        sort(key.begin(), key.end());
        anagramMap[key].push_back(str);
    }

    strs.clear();
    for (const auto& pair : anagramMap) {
        for (const string& anagram : pair.second) {
            strs.push_back(anagram);
        }
    }
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(strs);

    for (const string& str : strs) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}