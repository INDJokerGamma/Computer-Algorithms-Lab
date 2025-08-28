// Q3) Implement algorithm for The Skyline Problem: Given n rectangular buildings in a 2-
// dimensional city, computes the skyline of these buildings, eliminating hidden lines. The main
// task is to view buildings from a side and remove all sections that are not visible.
// All buildings share common bottom and every building is represented by triplet (left, ht,
// right) ‘left’: is x coordinated of left side (or wall). ‘right': is x coordinate of right side ‘ht': is
// height of building. For example, the building on right side is represented as (1, 11, 5)
// A skyline is a collection of rectangular strips. A rectangular strip is represented as a pair
// (left, ht) where left is x coordinate of left side of strip and ht is height of strip.
// With Time Complexity O(nLogn)

 
#include <bits/stdc++.h>
using namespace std;

struct Building {
    int left, height, right;
};

struct Strip {
    int left, height;
};

vector<Strip> mergeSkyline(vector<Strip> left, vector<Strip> right) {
    vector<Strip> res;
    int h1 = 0, h2 = 0;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i].left < right[j].left) {
            int x = left[i].left;
            h1 = left[i].height;
            int maxh = max(h1, h2);
            if (res.empty() || res.back().height != maxh)
                res.push_back({x, maxh});
            i++;
        } else {
            int x = right[j].left;
            h2 = right[j].height;
            int maxh = max(h1, h2);
            if (res.empty() || res.back().height != maxh)
                res.push_back({x, maxh});
            j++;
        }
    }

    while (i < left.size()) res.push_back(left[i++]);
    while (j < right.size()) res.push_back(right[j++]);

    return res;
}

vector<Strip> findSkyline(vector<Building>& buildings, int l, int r) {
    if (l == r) {
        vector<Strip> skyline;
        skyline.push_back({buildings[l].left, buildings[l].height});
        skyline.push_back({buildings[l].right, 0});
        return skyline;
    }

    int mid = (l + r) / 2;
    vector<Strip> left = findSkyline(buildings, l, mid);
    vector<Strip> right = findSkyline(buildings, mid + 1, r);

    return mergeSkyline(left, right);
}

int main() {
    int n;
    cin >> n;
    vector<Building> buildings(n);

    for (int i = 0; i < n; i++) {
        cin >> buildings[i].left >> buildings[i].height >> buildings[i].right;
    }

    vector<Strip> skyline = findSkyline(buildings, 0, n - 1);

    for (auto s : skyline) {
        cout << "(" << s.left << "," << s.height << ") ";
    }
    cout << endl;
}
