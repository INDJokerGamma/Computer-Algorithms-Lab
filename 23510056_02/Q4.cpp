#include <iostream>
using namespace std;

int main()
{
    int X, Y, s, t;
    cin >> X >> Y >> s >> t;

    if ((X + Y + s + s) <= t)
        cout << s * s << endl;
    else
    {
        int count = 0;

        for (int i = X; i <= X + s; i++)
        {
            for (int j = Y; j <= Y + s; j++)
            {
                if (i + j <= t)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
        }

        cout << count << endl;

        return 0;
    }
}