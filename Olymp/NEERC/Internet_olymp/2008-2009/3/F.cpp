#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "quadr."
#define pb push_back
#define x first
#define y second
 
typedef long long ll;
typedef pair <int, int> PII;

const int N = 2e5;

int dist(const PII &a, const PII &b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ll sqr(ll x) {
    return x * x;
}

int n = 4;       
PII p[4];
int id[4] = {0, 1, 2, 3};

int main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
//	#endif

	forn(i, 0, 3)
		cin >> p[i].x >> p[i].y;

	for (;;) {
		bool ok = (dist(p[id[0]], p[id[2]]) == dist(p[id[1]], p[id[3]]));
		forn(i, 0, 2) 
			if (dist(p[id[i]], p[id[i + 1]]) != dist(p[id[3]], p[id[0]]))
				ok = 0;
		if (ok && 2 * dist(p[id[0]], p[id[1]]) == dist(p[id[0]], p[id[2]])) {                    
			cout << "YES\n";
			return 0;
		}
		if (!next_permutation(id, id + 4)) break;
	}

	cout << "NO\n";

	return 0;
}
