#include <bits/stdc++.h>
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w; // sort by weight
    }
};

// Disjoint Set Union (Union-Find)
struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false; // already in same set → cycle

        // union by rank
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

int main() {
    int V = 10; // number of vertices (A-J → 0-9)
    vector<Edge> edges;

    // Add edges (A=0, B=1, ..., J=9)
    edges.push_back({0,1,15}); // A-B
    edges.push_back({0,2,10}); // A-C
    edges.push_back({0,3,19}); // A-D
    edges.push_back({1,3,7});  // B-D
    edges.push_back({1,4,17}); // B-E
    edges.push_back({2,3,16}); // C-D
    edges.push_back({2,5,14}); // C-F
    edges.push_back({3,4,12}); // D-E
    edges.push_back({3,5,6});  // D-F
    edges.push_back({3,6,3});  // D-G
    edges.push_back({4,6,20}); // E-G
    edges.push_back({4,7,13}); // E-H
    edges.push_back({5,6,9});  // F-G
    edges.push_back({5,8,5});  // F-I
    edges.push_back({6,7,4});  // G-H
    edges.push_back({6,8,1});  // G-I
    edges.push_back({6,9,11}); // G-J
    edges.push_back({7,9,2});  // H-J
    edges.push_back({8,9,18}); // I-J

    // Step 1: Sort edges
    sort(edges.begin(), edges.end());

    DSU dsu(V);
    vector<Edge> mst;
    int totalWeight = 0;

    // Step 2: Process edges
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            totalWeight += e.w;
        }
    }

    // Print MSTck
    cout << "Edges in MST:\n";
    for (auto &e : mst) {
        cout << char(e.u + 'A') << " - " << char(e.v + 'A') << " : " << e.w << "\n";
    }
    cout << "Total Weight of MST = " << totalWeight << "\n";

    return 0;
}
