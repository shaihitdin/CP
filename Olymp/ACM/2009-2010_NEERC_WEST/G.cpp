#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int N = 1e5 + 100;

vector <int> gg[N];
int u[N];

int main () {

	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	int n;
	cin >> n;

	for (int a = 1; a <= n; ++a) {
		for (int x = 1; a * x <= n; ++x) {
			gg[n - a * x].emplace_back (a);
		}
	}
	
	int ans = 0;
	for (int a = 1; a <= n; ++a) {
		for (int x = 1; a * x <= n; ++x) {
			for (auto it : gg[a * x]) {
				if (it != a && !u[it]) {
					u[it] = 1;
					++ans;
				}
			}
		}
		for (int x = 1; a * x <= n; ++x)
			for (auto it : gg[a * x])
				u[it] = 0;

	}

	
	//cerr << clock () * 1000 / CLOCKS_PER_SEC;
		
	cout << ans / 2;
	
	return 0;
}