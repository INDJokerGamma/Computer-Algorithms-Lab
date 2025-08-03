// Q.1 You are an IT company's manager. Based on their performance over the last N working days, you
// must rate your employee. You are given an array of N integers called workload, where workload[i]
// represents the number of hours an employee worked on an i
// th day. The employee must be evaluated
// using the following criteria:
// ∙ Rating = the maximum number of consecutive working days when the employee has worked
// more than 6 hours.
// You are given an integer N where N represents the number of working days. You are given an integer
// array workload where workload[i] represents the number of hours an employee worked on an i
// th day.
// Task
// Determine the employee rating

#include<bits/stdc++.h>
using namespace std;
int solve (int N, vector<int> workload) {
   // Write your code here
  int total =0;
  int maxtot=0;
  for(int i =0; i<N; i++)
  {
    if (workload[i] > 6)
      total ++;
    
    else
      total =0;

    if (maxtot < total)
      maxtot = total;
  }
  return maxtot;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> workload(N);
    for(int i_workload = 0; i_workload < N; i_workload++)
    {
    	cin >> workload[i_workload];
    }

    int out_;
    out_ = solve(N, workload);
    cout << out_;
}