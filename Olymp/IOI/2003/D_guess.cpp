#include <bits/stdc++.h>

using namespace std;

set <int> Set[10][3];
char a[51][51];
int n, p;
double Left;
int pos1;

inline void erase_them (const int &a, const int &b) {
    Left -= double (Set[a][b].size());
	while (Set[a][b].size()) {
		int del = *Set[a][b].begin();
		for (int i = 1; i <= p; ++i)
			for (int j = 0; j < 3; ++j)
				Set[i][j].erase (del);
	}	
}


vector <int> v1, v2, acc, del;
double mid;
double val;

inline void check (const int &pos, const int &lvl, const double &a1, const double &a2) {
	if (lvl == 3) {
		if (max (fabs (a1 - mid), fabs (a2 - mid)) < val) {
			val = max (fabs (a1 - mid), fabs (a2 - mid));
			acc = v1;
			pos1 = pos;
			del = v2;
		}
		return;
	}
	double temp = Set[pos][lvl].size();
	v1.push_back (lvl);
	check (pos, lvl + 1, a1 + temp, a2);
	v1.pop_back ();
	v2.push_back (lvl);
	check (pos, lvl + 1, a1, a2 + temp);
	v2.pop_back ();
}

int main () {
	/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	srand (time (0));
	cin >> n >> p;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= p; ++j)
			cin >> a[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= p; ++j)
			Set[j][a[i][j] - 'X'].insert (i);
	Left = n;
	while (Left != 1) {
		mid = (Left / 3.0);
		val = 1e18;
		pos1 = 0;
		v1.resize (0);
		v2.resize (0);
		acc.resize (0);
		del.resize (0);
		for (int i = 1; i <= p; ++i) {
			check (i, 0, 0, 0);
			check (i, 0, 0, 0);
			check (i, 0, 0, 0);
		}
		cout << "Q " << pos1 << " ";
		
		for (int it : acc)
			cout << char (it + 'X') << " ";
		cout << "\n";
		int q;
		cin >> q;
		if (q == 0)
			for (int it : acc)
				erase_them (pos1, it);
		else
			for (int it : del)
				erase_them (pos1, it);
	}
	for (int i = 1; i <= p; ++i)
		for (int j = 0; j < 3; ++j)
			if (Set[i][j].size()) {
				cout << "C " << *Set[i][j].begin();
				return 0;
			}
	return 0;
}