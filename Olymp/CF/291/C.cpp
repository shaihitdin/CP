#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair

typedef long long ll;

const int N = 1e6 + 11;
const ll p1 = 5, p2 = 7, modulo = 1e9 + 21;

ll p_pow1[N], p_pow2[N];
ll h1[N], h2[N];

string s, t;

set <pair <ll, ll> > Set;


inline ll get_hash (const ll &ha, const ll &haa) {
	return (((ha - haa) % modulo) + modulo) % modulo;
}

inline ll to_pow1 (const ll &h, const ll &pos) {
	return (h * p_pow1[N - pos - 1]) % modulo;
}

inline ll to_pow2 (const ll &h, const ll &pos) {
	return (h * p_pow2[N - pos - 1]) % modulo;
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	p_pow1[0] = p_pow2[0] = 1;
	for (int i = 1; i < N; ++i)
		p_pow1[i] = (p_pow1[i - 1] * p1) % modulo;
	for (int i = 1; i < N; ++i)
		p_pow2[i] = (p_pow2[i - 1] * p2) % modulo;
	
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> s;
		
		ll h_t1 = 0, h_t2 = 0;

		for (int j = 0; j < s.size(); ++j) {
			h_t1 = ((s[j] - 'a' + 1) * p_pow1[j] + h_t1) % modulo; 
			h_t2 = ((s[j] - 'a' + 1) * p_pow2[j] + h_t2) % modulo;
		}
		Set.insert (mkp (h_t1, h_t2));
	}
	for (int i = 1; i <= m; ++i) {
		cin >> t;
		for (int j = 0; j < t.size(); ++j) {
			
			h1[j] = ((t[j] - 'a' + 1) * p_pow1[j]);
			if (j) h1[j] += h1[j - 1];
			h1[j] %= modulo;
			
			h2[j] = ((t[j] - 'a' + 1) * p_pow2[j]);
			if (j) h2[j] += h2[j - 1];
			h2[j] %= modulo;

		}
		
		bool flag = 0;
		for (int j = 0; j < t.size(); ++j) {
			for (char k = 'a'; k <= 'c'; ++k) {
				if (t[j] == k)
					continue;
				ll temph1, temph2;
				temph1 = temph2 = 0;
				if (j) {
					temph1 = (temph1 + h1[j - 1]) % modulo;
					temph2 = (temph2 + h2[j - 1]) % modulo;
				}
				temph1 = ((k - 'a' + 1) * p_pow1[j] + temph1) % modulo;
				temph2 = ((k - 'a' + 1) * p_pow2[j] + temph2) % modulo;
				temph1 = (temph1 + (get_hash (h1[t.size() - 1], h1[j]))) % modulo;
				temph2 = (temph2 + (get_hash (h2[t.size() - 1], h2[j]))) % modulo;
				if (Set.find (mkp (temph1, temph2)) != Set.end())
					flag = 1;
			}
		}
		if (flag)
			puts ("YES");
		else
			puts ("NO");
	}
	return 0;
}