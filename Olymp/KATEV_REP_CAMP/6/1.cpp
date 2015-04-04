#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

map <int, int> Mn, Mx; // in y axis, out vertex;

long long ans[2];
int n;
int x[N], y[N];
int nx[N], ny[N];
int mn, start;
int main () {
	
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];

	if (n < 4) {
		puts ("0 0");
	}
	for (int i = 0; i < n; ++i)
		if (y[i] > mn) {
			mn = y[i];
			start = i;
		}
	for (int j = 0; j < n; ++j, start = (start + 1) % n) {
		nx[j] = x[start];
		ny[j] = x[start];
	}
	for (int i = 0; i < n; ++i)
		Mn[ny[i]] = i, Mx[ny[i]] = i;
	bool flag = 1;

	for (int i = 0; i != 0 || flag; i = (i + 1) % n) {
		/*
		if (y[i] == y[(i + 1) % n])
			continue;
		*/
		int j;
		if (flag) {
			if (min (ny[i], ny[(i + 1) % n]) == ny[i])
				j = i;
			else
				j = (i + 1) % n;
		
			if (nx[Mn[ny[j]]] > nx[j])
				Mn[ny[j]] = j;
			if (nx[Mx[ny[j]]] < nx[j])
				Mx[ny[j]] = j;
		}
		else {
			if (max (ny[i], ny[(i + 1) % n]) == ny[i])
				j = i;
			else
				j = (i + 1) % n;
			if (nx[Mn[ny[j]]] > nx[j])
				Mn[ny[j]] = j;
			if (nx[Mx[ny[j]]] < nx[j])
				Mx[ny[j]] = j;		
		}
		if (ny[(i + 1) % n] < ny[i])
			flag = 0;
	}

	auto it = Mn.begin();
	auto it1 = Mx.begin();

	for (;it != Mn.end(); ++it, ++it1) {
		int d1 = nx[it -> second], d2 = nx[it1 -> second], add = (it -> first) & 1;
		long long diff = d2 - d1;
		if (diff & 1) {
			ans[(d1 + add) & 1] += (diff / 2 + 1);
			ans[((d1 + add) & 1) ^ 1] += (diff / 2);
		}
		else {
			ans[(d1 + add) & 1] += (diff / 2);
			ans[((d1 + add) & 1) ^ 1] += (diff / 2 + 1);
		}
	}
	cout << ans[0] << " " << ans[1];
	return 0;
}