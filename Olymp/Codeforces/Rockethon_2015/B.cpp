#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> pos[20], elements[20];

ll lvl, n, m, step, cnt[51], prevmx;
ll u[61];
ll fact[20];
ll l[61], r[61];
int main () {

	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif


	cin >> n >> m;	
	for (lvl = 1; step != n; ++lvl) {
		memset (cnt, 0, sizeof (cnt));
		for (int i = 1; i <= n; ++i)
			for (int j = i; j <= n && !u[j]; ++j)
				for (int k = i; k <= j; ++k)
					++cnt[k];
		int mx = 0, mxpos;
		for (int i = 1; i <= n; ++i) {
			if (cnt[i] > mx) {
				mx = cnt[i];
				mxpos = i;
			}			
		}
		if (mx == prevmx)
			--lvl;
		pos[lvl].push_back (mxpos);
		prevmx = mx;
		u[mxpos] = lvl;
		++step;
	}
	fact[0] = 1;
	for (int i = 1; i <= 19; ++i)
		fact[i] = fact[i - 1] * i;
	
	
	r[lvl] = n;
	l[lvl] = n - int (pos[lvl].size()) + 1;
	
	for (int i = lvl - 1; i; --i) {
		r[i] = l[i + 1] - 1;
		l[i] = r[i] - int (pos[i].size()) + 1;			
	}
	for (int i = lvl; i; --i)
		for (int j = l[i]; j <= r[i]; ++j)
			elements[i].push_back (j);
	
	for (int i = 1; i <= n; ++i) {
		sort (elements[u[i]].begin(), elements[u[i]].end());
		bool flag = 0;
		for (int j = 0, sss = elements[u[i]].size(); sss; ++j, --sss) {
			if (m > fact[sss])
				m -= fact[sss];
			else {
				cout << elements[u[i]][j] << " ";
				elements[u[i]].erase (elements[u[i]].begin() + j);
				flag = 1;
				break;
			}
		}
		if (!flag) {
			cout << elements[u[i]][ int (elements[u[i]].size()) - 1] << " ";
			elements[u[i]].erase (elements[u[i]].begin() + int (elements[u[i]].size()) - 1);
		}
	}
	return 0;
}