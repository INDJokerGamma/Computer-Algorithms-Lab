// Q) Given an M*N matrix in which each row and each column is sorted in ascending order, write a
// method to find an element
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> searchMatrix(const vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    if (rows == 0)
        return {-1, -1};
    int cols = matrix[0].size();

    int row = 0, col = cols - 1;

    while (row < rows && col >= 0)
    {
        if (matrix[row][col] == target)
            return {row, col};
        else if (matrix[row][col] > target)
            col--; // Move left
        else
            row++; // Move down
    }

    return {-1, -1}; // Element not found
}

int main()
{
    vector<vector<int>> mat = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}};
    int target = 29;
    pair<int, int> pos = searchMatrix(mat, target);
    if (pos.first != -1)
        cout << "Found at (" << pos.first << ", " << pos.second << ")\n";
    else
        cout << "Not Found\n";
}
