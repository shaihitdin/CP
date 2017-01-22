#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;


int perm[4];
vector <int> dp[5][5];
int ans = -1;

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> perm[0] >> perm[1] >> perm[2] >> perm[3];
	
	sort (perm, perm + 4);

	for (;;) {
			
		for (int i = 1; i <= 4; ++i)
			for (int j = i; j <= 4; ++j)
				dp[i][j].clear ();
		dp[1][1].emplace_back (perm[0]);
		dp[2][2].emplace_back (perm[1]);
		dp[3][3].emplace_back (perm[2]);
		dp[4][4].emplace_back (perm[3]);
	
		for (int i = 1; i <= 4; ++i) {
			for (int j = i; j <= 4; ++j) {
				for (int k = i; k < j; ++k) {
					for (auto it1 : dp[i][k]) {
						for (auto it2 : dp[k + 1][j]) {
							dp[i][j].emplace_back (it1 + it2);
							dp[i][j].emplace_back (it1 - it2);
							dp[i][j].emplace_back (it1 * it2);
							if (it1 % it2 == 0)
								dp[i][j].emplace_back (it1 / it2);
						}
					}
				}
				for (int k = i; k < j; ++k) {
					for (int k2 = k + 1; k2 < j; ++k2) {
						for (auto it1 : dp[i][k]) {
							for (auto it2 : dp[k + 1][k2]) {
								for (auto it3 : dp[k2 + 1][j]) {
									dp[i][j].emplace_back (it1 * it2 + it3);
									dp[i][j].emplace_back (it1 + it2 * it3);
									dp[i][j].emplace_back (it1 * it2 - it3);
									dp[i][j].emplace_back (it1 - it2 * it3);
									if (it1 % it2 == 0)
										dp[i][j].emplace_back (it1 / it2 + it3);
									if (it2 % it3 == 0)
										dp[i][j].emplace_back (it1 + it2 / it3);
									if (it1 % it2 == 0)
										dp[i][j].emplace_back (it1 / it2 - it3);
									if (it2 % it3 == 0)
										dp[i][j].emplace_back (it1 - it2 / it3);									
								}
							}
						}
					}
				}
			}
		}	
		
		for (auto it : dp[1][4]) {
			if (abs (it - 21) == abs (ans - 21))
				ans = min (ans, it);
			else if (abs (it - 21) < abs (ans - 21))
				ans = it;
			//cerr << it << " ";
		}
		if (!next_permutation (perm, perm + 4))
			break;
	}
	
	cout << ans;

	return 0;
}