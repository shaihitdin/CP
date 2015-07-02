#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int N = 1e5 + 100, B_SZ = 350;

/*
struct node {
	vector <int> g[B_SZ];
	vector <int> positions;

	node () {

	}

} *b[B_SZ];
*/

int ans[N];
int n, m;
vector <int> v[N];

//int b_num[N];

inline void Merge (const int &x, const int &y) {
	if (v[x].size () > v[y].size ())
		v[x].swap (v[y]);
	if (!v[x].size ())
		return;
	int save = v[y].size ();
	v[y].resize (v[y].size () + v[x].size ());
	memcpy (&v[y][save], &v[x][0], sizeof (int) * v[x].size ());
	v[x].clear ();
}

int main () {
	freopen ("balls.in", "r", stdin);
	freopen ("balls.out", "w", stdout);

	scanf ("%d%d", &n, &m);
	/*
	int block = sqrt (n);
	
	
	for (int i = 1; i <= n; ++i) {
		b_num[i] = i / block + 1;
		b_cnt[i] = (b_num[i] == b_num[i - 1]) ? b_cnt[i - 1] + 1 : 1;
	}

	for (int i = 1; i < B_SZ; ++i)
		b[i] = new node ();
	
	for (int i = 1; i <= n; ++i)
		b[b_num[i]].g[b_cnt[i]].push_back (i);
	*/
	
	for (int i = 1; i <= n; ++i)
		v[i].push_back (i);
	while (m--) {
		int c, f, t;
		scanf ("%d%d%d", &c, &f, &t);
	    if (f == t)
	    	continue;
		if (f + c - 1 >= t && f <= t)
			for (int i = f + c - 1, j = t + c - 1; i >= f; --i, --j)
				Merge (i, j);
		else
			for (int i = f, j = t; i <= f + c - 1; ++j, ++i)
				Merge (i, j);
	}

	
	
	for (int i = 1; i <= n; ++i)
		for (auto it : v[i])
			ans[it] = i;
	
	for (int i = 1; i <= n; ++i)
		printf ("%d ", ans[i]);
	
	return 0;
}
