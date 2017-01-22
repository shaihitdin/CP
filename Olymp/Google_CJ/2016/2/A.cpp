/// Stupido del problemo

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

const int oo = 1e9, bpr = 1e9 + 7, N = 4096;

int a[N + N + 100];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int t;

	cin >> t;

	//P R S

	for (int test = 1; test <= t; ++test) {
		cout << "Case #" << test << ": ";
		cin >> n >> r >> p >> s;
		cnt[1] = p, cnt[2] = r, cnt[3] = s;
		nn = (1 << n);
		sz = 0;
		memset (a, 0, sizeof (a));
		vector <int> ans;
		
	}
	
	return 0;
}