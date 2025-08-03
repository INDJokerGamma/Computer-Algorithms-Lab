

#include <bits/stdc++.h> 
using namespace std; 
int main() 
{    
    int t;    
    cin>>t;    
    while(t--)    
    {       
        long long int n, k;       
        cin>>n>>k;       
        long long int div = 2*n-2; 

        if(k <= div)       
        {         
            if(k < n)         
            cout<<k<<endl;         
            else         
            cout<<n-(k-n)<<endl;       
        }       
        else
        {       
            long long int res = k%div;         
            if(res < n && res > 0)         
            cout<<res<<endl;         
            else if(res == 0)         
            cout<<2<<endl;         
            else         
            cout<<n-(res-n)<<endl;             
        }  
    } 
}