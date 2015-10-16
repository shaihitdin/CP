#include <bits/stdc++.h>

using namespace std;

const int N = 3e5;

int st[N], enq;
int a[N], n;
int l[N], r[N];

vector <int> g[N];

multiset <int> Set;

int main () {
    #ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);

	enq = 0;
	
	for (int i = 1; i <= n; ++i) {
		while (enq && a[st[enq]] >= a[i])
			--enq;
		if (!enq)
			l[i] = 1;
		else
			l[i] = st[enq] + 1;
		st[++enq] = i;
	}
	
	enq = 0;

	for (int i = n; i; --i) {
		while (enq && a[st[enq]] >= a[i])
			--enq;
		if (!enq)
			r[i] = n;
		else
			r[i] = st[enq] - 1;
		st[++enq] = i;
	}
	
	for (int i = 1; i <= n; ++i) {
		Set.insert (a[i]);
		g[r[i] - l[i] + 1].push_back (a[i]);
	}
	
	for (int i = 1; i <= n; ++i) {
		printf ("%d ", *Set.rbegin ());
		for (auto it : g[i])
			Set.erase (Set.find (it));
	}

	return 0;
}