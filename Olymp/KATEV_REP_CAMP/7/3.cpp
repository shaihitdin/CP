#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 4e7;


ll n, m;


int main () {

	freopen ("3.in", "r", stdin);
	freopen ("3.out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	cin >> n >> m;
	
	cout << n;
	/*
	for (int i = 1; i <= m; ++i) {
		ll x;
		cin >> x;
		l.push_back (x);
	}

	sort (l.begin(), l.end());
	
	for (int i = 0; i < l.size(); ++i)
		if (l[i] >= 2 && l[i] <= 9)
			can[l[i]] = 1;

	ll nw[6], was[6];
	nw[1] = 10;
	nw[2] = 13;
	nw[3] = 17;
	nw[4] = 21;
	nw[5] = 25;
	was[1] = 2;
	was[2] = 3;
	was[3] = 5;
	was[4] = 7;
	was[5] = 9;
	j = 0;
	ll elements = 5;
	for (int i = 3; i < N; ++i) {
		while (1) {
			while (j < s.size() && l[j] < nw[1])
				++j;
			if (j == s.size())
				break;
			if (l[j] < nw[2]) {
				can[l[j]] = was[1] + (l[j] - nw[1] - 1);
				r_can[was[1] + (l[j] - nw[1] - 1)] = l[j];
				d.push_back (was[1] + (l[j] - nw[1] - 1));
			}
			else if (l[j] < nw[3]) {
				can[l[j]] = was[2] + (l[j] - nw[2] - 1);
				r_can[was[2] + (l[j] - nw[2] - 1)] = l[j];
				d.push_back (was[2] + (l[j] - nw[2] - 1));
			}
			else if (l[j] < nw[4]) {
				can[l[j]] = was[3] + (l[j] - nw[3] - 1);
				r_can[was[3] + (l[j] - nw[3] - 1)] = l[j];
				d.push_back (was[3] + (l[j] - nw[3] - 1));
			}
			else if (l[j] < nw[5]) {
				can[l[j]] = was[4] + (l[j] - nw[4] - 1);
				r_can[was[4] + (l[j] - nw[4] - 1)] = l[j];
				d.push_back (was[4] + (l[j] - nw[4] - 1));
			}
			else
				break;
			++j;
		}
		for (int k = 1; k <= 5; ++k)
			was[k] = nw[k];
		nw[1] = was[5] + 1;
		elements = elements + 2;
		nw[2] = nw[1] + elements - 2;
		nw[3] = nw[2] + elements - 1;
		nw[4] = nw[3] + elements - 1;
		nw[5] = nw[4] + elements - 1;
	}
	sort (d.begin(), d.end());

	for (int i = 0; i < d.size(); ++d)
		pos[d[i]] = i;
	for (int i = 0; i < d.size(); ++i)
		dyn[d[i]] = 1e18;

	Set.insert (mkp (0, 0));

	while (Set.size()) {
		auto v = Set.begin() -> second;		
		v = pos[d[i]];
		dyn[v + 1] = d[v] + 1;
		if (r_can[v] != 0 && dyn[r_can[v]] > dyn[v] + 1) {
			Set.erase (mkp (dyn[r_can[v]], r_can[v]));
			dyn[r_can[v]] 
		}
	}
	*/
	return 0;
}