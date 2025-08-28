// Q.7 Implement Binary Search algorithm.

#include <bits/stdc++.h>
using namespace std;

int binary(vector<int> arr, int n, int key)
{
    int start=0;
    int end=n-1;

    int mid= start+ (end-start)/2;

    while(start <= end)
    {
        if (arr[mid]== key)
        {
           return mid;
        }
        
        if(arr[mid] < key)
        {
            start= mid+1;
        }
        else
        {
            end= mid-1;
        }
        mid= start+ (end-start)/2;
    }
    return -1;
}
int main () 
{
int n;
cout<<"Enter the size of the array"<<endl;
cin>>n; 
int key ;
cout<<"Enter the key"<<endl;
cin>>key;
vector<int> arr(n);
cout<<"Enter the elements in the array"<<endl;
for(int i=0;i<n;i++)
{
    cin>> arr[i];
}

sort(arr.begin(), arr.end());
cout<<"The sorted array is "<<endl;
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<" ";
}
cout<<endl;
int k = binary(arr, n, key);
cout<<"The index of the key is after sorting"<<endl;
cout<<k<<endl;
return 0;
}