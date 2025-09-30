#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int V = 10; // A-J (0 to 9)
    vector<vector<pair<int,int>>> adj(V);

    // Function to add edges (undirected)
    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    };

    // Add edges (A=0, B=1, ..., J=9)
    addEdge(0,1,15); // A-B
    addEdge(0,2,10); // A-C
    addEdge(0,3,19); // A-D
    addEdge(1,3,7);  // B-D
    addEdge(1,4,17); // B-E
    addEdge(2,3,16); // C-D
    addEdge(2,5,14); // C-F
    addEdge(3,4,12); // D-E
    addEdge(3,5,6);  // D-F
    addEdge(3,6,3);  // D-G
    addEdge(4,6,20); // E-G
    addEdge(4,7,13); // E-H
    addEdge(5,6,9);  // F-G
    addEdge(5,8,5);  // F-I
    addEdge(6,7,4);  // G-H
    addEdge(6,8,1);  // G-I
    addEdge(6,9,11); // G-J
    addEdge(7,9,2);  // H-J
    addEdge(8,9,18); // I-J

    vector<int> key(V, INF), parent(V, -1);
    vector<bool> inMST(V, false);

    key[0] = 0; // start from A (0)
    int totalWeight = 0;

    for (int i = 0; i < V; i++) {
        int u = -1;

        // Pick vertex not in MST with min key
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;
        }

        inMST[u] = true;
        totalWeight += key[u];

        // Update neighbors
        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    cout << "Edges in MST:\n";
    for (int v = 1; v < V; v++) {
        cout << char(parent[v] + 'A') << " - " << char(v + 'A') 
             << " : " << key[v] << "\n";
    }
    cout << "Total Weight of MST = " << totalWeight << "\n";

    return 0;
}
