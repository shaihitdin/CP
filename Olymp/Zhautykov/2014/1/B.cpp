#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
vector <int> v[21];
int a[21], b[21];
int n, m;
inline void rec (const int &lvl, const int &sum, const int &mask) {
	if (lvl == m) {
		for (int i = 0; i < n; ++i)
			if (sum == a[i])
				v[i].push_back(mask);
		 return;
	}
	rec (lvl + 1, sum, mask);
	rec (lvl + 1, sum + b[lvl], mask ^ (1 << lvl));
}
bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}
set <int> d[(1 << 20)];
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];
	rec (0, 0, 0); 
	d[0].insert ((1 << m) - 1);
	int Nn = (1 << n);
	for (int i = 0; i < Nn; ++i)
		for (int j = 0; j < n; ++j)
			if (!bit (i, j) )
				for (int x : v[j])
					for (int y : d[i])
						if ( (y & x) == x)
							d[i | (1 << j)].insert (y ^ x);						
	if (d[Nn - 1].size() == 0)
		puts ("NO");
	else
		puts ("YES");
	return 0;
}