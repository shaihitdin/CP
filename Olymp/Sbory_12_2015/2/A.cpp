#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int t_num;

	cin >> t_num;

	while (t_num--) {
		int n, m;
		cin >> n >> m;
		map <string, string> car, spy;
		// car[x] = "" -> available, car[x].size () > 0 -> using car[x] spy
		// spy[x] = "" -> not using, spy[x].size () > 0 -> using car named spy[x]
		// pcost[x] = car's pickup cost
		// ccost[x] = car's cost when crushed
		// dcost[x] = car's cost per kilometer
		map <string, int> pcost, ccost, dcost;
		map <string, int> spycheque;
		while (n--) {
			string name;
			cin >> name;
			int p, q, k;
			cin >> p >> q >> k;
			ccost[name] = p;
			pcost[name] = q;
			dcost[name] = k;
		}
		string tmp;
		string name;
		for (int i = 1; i <= m; ++i) {
			int t;
			char q_type;
			cin >> t;
			cin >> name;
			cin >> q_type;
			if (q_type == 'p') {
				if (spy[name].size () > 0)
					spycheque[name] = -oo;
				cin >> tmp;
				spy[name] = tmp;
				car[tmp] = name;
				spycheque[name] += pcost[tmp];
			} else if (q_type == 'r') {
				if (spy[name].size () == 0) {
					spycheque[name] = -oo;
				}
				int sd;
				cin >> sd;
				spycheque[name] += sd * dcost[spy[name]];
				spy[name] = "";
			} else {
				if (spy[name].size () == 0) {
					spycheque[name] = -oo;
				}
				int percentage;
				cin >> percentage;
				double sd = ccost[spy[name]] * percentage / 100.0;
				if (sd != int (sd))
					sd += 1;
				spycheque[name] += sd;
			}
		}
		for (auto &it : spycheque) {
			if (spy[it.first].size () > 0)
				it.second = -oo;
			cout << it.first << " ";
			if (it.second < 0)
				cout << "INCONSISTENT";
			else
				cout << it.second;
			cout << "\n";
		}
	}

	return 0;
}