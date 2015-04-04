#include <iostream>
#include <set>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = (1e5) + 5, inf = 1e9;
int n, m, a[N], s[N], l, r, decrease[N];
multiset <int> st;
vector <int> v[N];
int main () {
	freopen ("toy.in", "r", stdin);
	freopen ("toy.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	scanf ("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d", &l, &r);
		v[l].push_back(r);
		++decrease[r];
	}
	int ans = 0, delta;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			st.insert(v[i][j]);
		}
		if (st.size() > a[i]) {
			delta = st.size() - a[i];
			ans += delta;
			while (delta) {
				multiset <int> :: iterator it = st.end();
				--it;
				--decrease[*it];
				st.erase (it);
				--delta;
			}
		}
		while (decrease[i]) {
			st.erase (i);
			--decrease[i];
		}
	}
	printf ("%d", ans);
	return 0;
}