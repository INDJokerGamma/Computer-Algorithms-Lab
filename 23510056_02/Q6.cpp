// Q.6 Implement linear search algorithm
#include <bits/stdc++.h>
using namespace std;
int main () 
{
int n;;
cout<<"Enter the size of the array"<<endl;
cin>>n; 
int key ;
cout<<"Enter the key"<<endl;
cin>>key;

int arr[n];
cout<<"Enter the elements in the array"<<endl;
for(int i=0;i<n;i++)
{
    cin>> arr[i];
}
for(int i=0;i<n;i++)
{
    if(arr[i] == key)
    {
        cout<<"The index of the key is "<< i <<endl;
        return 0;
    }
}
return 0 ;
}