/**
	I'm on someone's monitor!
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 100;

int p[N], sz[N], cnt[N], cnt0;
bitset <N> now;

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

inline int get_p (const int &x) {
	return x == p[x] ? x : p[x] = get_p (p[x]);
}

inline void Merge (int a, int b) {
	a = get_p (a);
	b = get_p (b);
	if (sz[a] < sz[b])
		swap (a, b);
	sz[a] += sz[b];
	p[b] = a;
}
inline void add_obj (int x) {
	now |= (now << x);
	now[x] = 1;
}

inline void add (int x, int ent) {
	int f = 20;
	for (;!bit (ent, f);--f);
	for (int i = 0; i < f; ++i)
		add_obj (x * (1 << i));
	add_obj (x * (ent - (1 << f) + 1));
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	srand (time (0));

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, k;
	cin >> n >> k;
	if (!k) {
		cout << "0 0\n";
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		p[i] = i, sz[i] = 1;	
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		Merge (x, i);
	}
	
	int c1 = 0, c2 = 0;	
	for (int i = 1; i <= n; ++i) {
		if (p[i] == i) {
			cnt[sz[i]]++;
			c1 += sz[i] % 2;
			c2 += sz[i] / 2;
			if (sz[i] % 2 == 0)
				cnt0 += sz[i];
			else
				cnt0 += (sz[i] - 1);
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		if (!cnt[i])
			continue;
		add (i, cnt[i]);
	}
	
	if (now[k])
		cout << k << " ";
	else
		cout << min (n, k + 1) << " ";

  int ans_max = 0;
  ans_max += 2 * min(k, c2);
  k -= min(k, c2);
  ans_max += min(k, c1);
  cout << ans_max;
	return 0;
}