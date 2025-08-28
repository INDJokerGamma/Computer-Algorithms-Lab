/* Q2) Implement algorithm for Tiling problem: Given an n×n board where n is of form 2k
 where k >= 1 (Basically n is a power of 2 with minimum value as 2). The board has one
 missing cell (of size 1 x 1). Fill the board using L shaped tiles. An L shaped tile is a 2 x 2
 square with one cell of size 1×1 missing*/

#include <bits/stdc++.h>
using namespace std;

int tileID = 1; // unique ID for each L-shaped tile


void tileBoard(vector<vector<int>>& board, int n, int topRow, int topCol, int missingRow, int missingCol) 
{
    if (n == 2) 
    {
        // Base case: 2x2 board
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 2; j++) 
            {
                if (topRow + i != missingRow || topCol + j != missingCol) 
                    board[topRow + i][topCol + j] = tileID;
            }
        }
        tileID++;
        return;
    }

    int t = tileID++; // current tile number
    int mid = n / 2;

    // Missing cell quadrant
    int quad = (missingRow < topRow + mid ? 0 : 2) + (missingCol < topCol + mid ? 0 : 1);

    // Place L-tile in the center covering 3 quadrants
    if (quad != 0) board[topRow + mid - 1][topCol + mid - 1] = t;
    if (quad != 1) board[topRow + mid - 1][topCol + mid] = t;
    if (quad != 2) board[topRow + mid][topCol + mid - 1] = t;
    if (quad != 3) board[topRow + mid][topCol + mid] = t;

    
    // Recurse for each quadrant
    // Top-left
    tileBoard(board, mid, topRow, topCol,
              (quad == 0 ? missingRow : topRow + mid - 1),
              (quad == 0 ? missingCol : topCol + mid - 1));

    // Top-right
    tileBoard(board, mid, topRow, topCol + mid,
              (quad == 1 ? missingRow : topRow + mid - 1),
              (quad == 1 ? missingCol : topCol + mid));

    // Bottom-left
    tileBoard(board, mid, topRow + mid, topCol,
              (quad == 2 ? missingRow : topRow + mid),
              (quad == 2 ? missingCol : topCol + mid - 1));

    // Bottom-right
    tileBoard(board, mid, topRow + mid, topCol + mid,
              (quad == 3 ? missingRow : topRow + mid),
              (quad == 3 ? missingCol : topCol + mid));

}

int main() {
    int n = 8; // board size (must be power of 2)
    int missingRow = 2, missingCol = 3; // coordinates of missing cell

    vector<vector<int>> board(n, vector<int>(n, 0));
    board[missingRow][missingCol] = -1; // mark missing cell

    tileBoard(board, n, 0, 0, missingRow, missingCol);

    // Print the board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(3) << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
