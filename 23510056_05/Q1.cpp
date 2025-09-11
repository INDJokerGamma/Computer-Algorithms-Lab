 
#include <bits/stdc++.h>
using namespace std;

int connections(int n){
    return (n* (n-1) / 2);
}


int maxconn(int A, int B){
    return connections(A-B+1);
}

int minconn(int A, int B){
    if (B ==0 )
        return 0;
    if (B ==1 )
        return connections(A);


    int q = A / B;
    int r = A % B;

    return r * connections(q+1) + (B-1) * connections(q);
}

int main () 
{
    int A,B;
    cout<< "Enter the number of Houses: ";
    cin >> A;
    cout<< "Enter the number of Localities: ";
    cin >>B;

    cout<< "Maximum Connections: " << maxconn(A,B) <<endl;
    cout<< "Minimum Connections: " << minconn(A,B) <<endl;
    return 0 ;
}