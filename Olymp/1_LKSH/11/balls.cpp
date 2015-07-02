#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int N = 1e5 + 100;

vector <int> v[N];
int ans[N];
int n, m;

int main () {
	freopen ("balls.in", "r", stdin);
	freopen ("balls.out", "w", stdout);

	scanf ("%d%d", &n, &m);

	for (int i = 1; i <= n; ++i)
		v[i].push_back (i);
	
	while (m--) {
		int c, f, t;
		scanf ("%d%d%d", &c, &f, &t);
	    if (f == t)
	    	continue;
		if (f + c - 1 >= t && f <= t) {
			for (int i = f + c - 1, j = t + c - 1; i >= f; --i, --j) {
				if (!v[i].size ())
					continue;
				if (v[i].size () > v[j].size ())
					v[i].swap (v[j]);
				auto temp = v[i];
				v[i].resize (0);
				for (auto it : temp)
					v[j].push_back (it);
			}
		} else {
			for (int i = f, j = t; i <= f + c - 1; ++j, ++i) {
				if (!v[i].size ())
					continue;
				if (v[i].size () > v[j].size ())
					v[i].swap (v[j]);
				auto temp = v[i];
				v[i].resize (0);
				for (auto it : temp)
					v[j].push_back (it);
			}
		}
	}

	
	
	for (int i = 1; i <= n; ++i)
		for (auto it : v[i])
			ans[it] = i;
	
	for (int i = 1; i <= n; ++i)
		printf ("%d ", ans[i]);
	
	return 0;
}
