#include <bits/stdc++.h>

using namespace std;

const int N = 3000;

int main() {
    freopen ("game.in", "r", stdin);
    freopen ("game.out", "w", stdout);
    freopen ("game.err", "w", stderr);
    /*
    int l, r;
    std::cin >> l >> r;
    */
    int ans = 0;
    for (int i = 1; i < N; i++) {
        std::vector <bool> dp(i + 1, false);
        for (int j = i - 1; j >= 1; j--) {
            dp[j] = !dp[j + 1];
            if (j * 2 <= i)
                dp[j] = dp[j] | !dp[j * 2];
        }
        ans += dp[1];
        if (dp[1]) {
        	cerr << i << " ";
        	//i += 2;
        }
    }
    cout << ans << endl;
    return 0;
}
