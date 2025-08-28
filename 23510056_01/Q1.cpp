// Q) You are given two sorted array, A and B, where A has a large enough buffer at the end to hold B.
// Write a method to merge B into A in sorted order

#include <bits/stdc++.h>
using namespace std;

// Merges array B into A assuming A has enough space
int mergeSortedArrays(vector<int>& A, int m, vector<int>& B, int n) {
    
    int i = m - 1;  // Pointer at last element of real data in A
    int j = n - 1; // Pointer at last element of B
    int k = m + n - 1; // Pointer at last index of A (including buf

    // If B still has elements left
   while (j >= 0) {
        if (i >= 0 && A[i] > B[j]) 
        {
            A[k] = A[i];
            i--;
        } 
        else 
        {
            A[k] = B[j];
            j--;
        }
        k--;
    }

    for (int i = 0; i < m + n; i++) {
        cout << A[i] << " ";
    }
    return 0;
}

int main () 
{
vector<int > A = {1,2,3,4,5,0,0,0,0,0};
vector<int > B = {6,7,8,9,10};
int m=5;
int n= B.size();
mergeSortedArrays(A, m, B, n);
return 0 ;
}