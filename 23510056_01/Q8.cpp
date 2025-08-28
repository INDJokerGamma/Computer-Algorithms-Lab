// Q) Imagine you are reading in stream of integers. Periodically, you wish to be able to look up the rank
// of number x (the number of values less than or equal to x). Implement the data structures and
// algorithms to support these operations. That is, Implement the method track (int x), which is called
// when each number is generated, and the method getRankOfNumber (int x), which return the number
// of values less than or equal to x (not including x itself).
// EXAMPLE
// Stream (in order of appearance) : 5, 1, 4, 4, 5, 9, 7, 13, 3
// getRankOfNumber(1) = 0
// getRankOfNumber(3) = 1
// getRankOfNumber(4) =3

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "Enter Number to Know Rank" << endl;
    cin >> x;
    bool check = false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == x)
        {
            cout << "Rank of " << x << " is " << i + 1 << endl;
            check = true;
            break;
        }
    }
    if (!check)
    {
        cout << "Number Not Found" << endl;
    }
    return 0;
}