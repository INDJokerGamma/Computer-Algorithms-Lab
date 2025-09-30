#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> top(N), bottom(N);
    for (int i = 0; i < N; i++) cin >> top[i];
    for (int i = 0; i < N; i++) cin >> bottom[i];

    vector<int> dp(N+1, 0);

    // Base cases
    dp[1] = abs(top[0] - bottom[0]);
    if (N > 1) {
        dp[2] = max(
            dp[1] + abs(top[1] - bottom[1]), 
            abs(top[0] - top[1]) + abs(bottom[0] - bottom[1])
        );
    }

    // Fill DP
    for (int i = 3; i <= N; i++) {
        int vertical = dp[i-1] + abs(top[i-1] - bottom[i-1]);
        int horizontal = dp[i-2] + abs(top[i-2] - top[i-1]) + abs(bottom[i-2] - bottom[i-1]);
        dp[i] = max(vertical, horizontal);
    }

    cout << dp[N] << "\n";
    return 0;
}
