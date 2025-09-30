#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

// Huffman tree node
struct Node {
    string sensor;
    int freq;
    Node *left, *right;
    
    Node(string s, int f) : sensor(s), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for min-heap
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Recursive function to generate codes
void generateCodes(Node* root, string code, map<string, string> &codes) {
    if (!root) return;
    
    if (!root->left && !root->right) {
        codes[root->sensor] = code;
    }
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

int main() {
    // Sensors with frequency × importance
    map<string, int> sensors = {
        {"Temp",400}, {"Humidity",300}, {"Pressure",600}, {"Light",150}, {"Gas",120},
        {"Motion",200}, {"Smoke",100}, {"Vibration",250}, {"Sound",350}, {"CO2",450},
        {"pH",80}, {"Toxic",60}, {"Voltage",220}, {"Current",180}, {"Wind",140},
        {"Rain",200}, {"GPS",90}, {"UV",70}, {"Dust",160}, {"Salinity",110}
    };

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Create leaf nodes
    for (auto s : sensors) {
        minHeap.push(new Node(s.first, s.second));
    }

    // Build Huffman Tree
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();
        Node* merged = new Node("", left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        minHeap.push(merged);
    }

    Node* root = minHeap.top();

    // Generate codes
    map<string, string> codes;
    generateCodes(root, "", codes);

    // Print codes
    cout << "Sensor Huffman Codes:\n";
    for (auto c : codes) {
        cout << c.first << " : " << c.second << endl;
    }

    // Calculate average code length
    double total_weight = 0;
    double total_bits = 0;
    for (auto s : sensors) {
        total_weight += s.second;
        total_bits += s.second * codes[s.first].length();
    }
    double avg_length = total_bits / total_weight;
    cout << "\nAverage code length: " << avg_length << " bits\n";

    return 0;
}
