#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1010, M = 1e5 + 100;

ll c[N][N], a[N][N], b[N][N];
int q_type[M], sx[M], sy[M], fx[M], fy[M];
ll x[M];

inline int fmax (const int &x, const int &y) {
	if (x > y)
		return x;
	return y;
}

inline int fmin (const int &x, const int &y) {
	if (x < y)
		return x;
	return y;
}

inline bool intersect (const int &sx1, const int &sy1, const int &fx1, const int &fy1, 
						const int &sx2, const int &sy2, const int &fx2, const int &fy2) {
	int sx3 = fmax (sx1, sx2), sy3 = fmax (sy1, sy2), fx3 = fmin (fx1, fx2), fy3 = fmin (fy1, fy2);
	if (sx3 <= fx3 && sy3 <= fy3)
		return (((fy3 - sy3 + 1) & 1) & ((fx3 - sx3 + 1) & 1));
	return 0;
}

inline ll get (const int &sx, const int &sy, const int &fx, const int &fy) {
	return b[fx][fy] ^ b[sx - 1][fy] ^ b[fx][sy - 1] ^ b[sx - 1][sy - 1];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, m;

	scanf ("%d%d", &n, &m);

	const int MAGIC = 1000;

	vector <int> quer;
	
	for (int i = 1; i <= m; ++i) {
		scanf ("%d", &q_type[i]);
		if (q_type[i] == 1) {
			scanf ("%d%d%d%d", &sx[i], &sy[i], &fx[i], &fy[i]);
			ll res = get (sx[i], sy[i], fx[i], fy[i]);
			for (int j : quer)
				if (intersect (sx[i], sy[i], fx[i], fy[i], sx[j], sy[j], fx[j], fy[j]))
					res ^= x[j];
			printf ("%I64d\n", res);
		} else {
			quer.emplace_back (i);
			scanf ("%d%d%d%d%I64d", &sx[i], &sy[i], &fx[i], &fy[i], &x[i]);
			for (int j = sx[i]; j <= fx[i]; ++j) {
				c[j][sy[i]] ^= x[i];
				c[j][fy[i] + 1] ^= x[i];
			}
		}
		if (quer.size () == MAGIC) {
			int tmp = 0;
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= n + 1; ++k)
					tmp ^= c[j][k], a[j][k] ^= tmp, c[j][k] = 0, b[j][k] = b[j - 1][k] ^ b[j][k - 1] ^ b[j - 1][k - 1] ^ a[j][k];

			quer.resize (0);
		}
	}

	return 0;
}