
//  Q.3 Implement and Explain Tower of Hanoi algorithm.

#include <bits/stdc++.h>
using namespace std;

void TowerofHanoi(int n, char s_rod, char d_rod, char a_rod )
{
    if (n==1)
    {
        cout << "Moving Disk 1 from rod "<< s_rod << " to rod " << d_rod <<endl;
        return;
    }
    
    TowerofHanoi (n-1, s_rod, a_rod, d_rod);

    cout<<"Move disk "<< n << " from rod " << s_rod << " to "  << d_rod <<endl;
    cout<<endl;

    TowerofHanoi (n-1, a_rod, d_rod, s_rod);
}
int main () 
{
   int n;
   cout<< "Enter the number of disks"<<endl;
   cin>>n; 
   cout<< "The order of the rods are like: "<<endl;
   cout<<endl;
   TowerofHanoi (n, 'A', 'B', 'C');
   
return 0 ;
}