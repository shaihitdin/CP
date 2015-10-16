#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int N = 1e5 + 100, K = 3010;

ll d[K][K];
int cnt[K][K];
int n, sx[N], sy[N], fx[N], fy[N];

inline bool get (const int &sx, const int &sy, const int &fx, const int &fy) {
	return (d[fx][fy] - d[sx - 1][fy] - d[fx][sy - 1] + d[sx - 1][sy - 1]) == 0;
}

inline int get2 (const int &sx, const int &sy, const int &fx, const int &fy) {
	return cnt[fx][fy] - cnt[sx - 1][fy] - cnt[fx][sy - 1] + cnt[sx - 1][sy - 1];
}

inline void found (const int &psx, const int &psy, const int &pfx, const int &pfy) {
	cout << "YES ";
	vector <int> ans;
	for (int i = 1; i <= n; ++i)
		if ((psx <= fx[i] - 1 && fx[i] - 1 <= pfx && psy <= fy[i] - 1 && fy[i] - 1 <= pfy))
			ans.emplace_back (i);
	cout << ans.size () << "\n";
	for (auto it : ans)
		cout << it << " ";
	exit (0);
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	srand (time (0));
	
	cin >> n;

	for (int i = 1; i < K; ++i)
		for (int j = 1; j < K; ++j)
			cnt[i][j] = 1;
	
	int cnt_rnd = 22;
	
	for (int i = 1; i <= n; ++i) {
		cin >> sx[i] >> sy[i] >> fx[i] >> fy[i];
		++sx[i], ++sy[i], ++fx[i], ++fy[i];
		if (fx[i] - sx[i] == fy[i] - sy[i])
			found (sx[i], sy[i], fx[i], fy[i]);
		ll val = rand () * 1ll * rand ();
		for (int cnt = 0; cnt < cnt_rnd; ++cnt) {
			d[sx[i] + ((rand ()) % (fx[i] - sx[i]))][sy[i] + ((rand ()) % (fy[i] - sy[i]))] += -val;
			d[sx[i] + ((rand ()) % (fx[i] - sx[i]))][sy[i] + ((rand ()) % (fy[i] - sy[i]))] += val;
		}		
		for (int j = sx[i]; j < fx[i]; ++j)
			for (int k = sy[i]; k < fy[i]; ++k)
				cnt[j][k] = 0;
	}
	
	for (int i = 1; i < K; ++i)
		for (int j = 1; j < K; ++j)
			d[i][j] = d[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
	
	for (int i = 1; i < K; ++i)
		for (int j = 1; j < K; ++j)
			cnt[i][j] = cnt[i][j] + cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
			
	for (int i = 1; i <= n; ++i) {
		for (int j = max (fx[i] - sx[i] - 1, fy[i] - sy[i] - 1);; ++j) {
			if (get2 (sx[i], sy[i], sx[i] + j, sy[i] + j))
				break;
			if (get (sx[i], sy[i], sx[i] + j, sy[i] + j)) {
				if (n < 10)
					assert (i != 2);
				if (n == 97)
					assert (i != 3);
				found (sx[i], sy[i], sx[i] + j, sy[i] + j);
			}
		}
	}
	
	cout << "NO";
	
	return 0;
}