#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int a[N];
int n;
int c[N];
int ans[2][N];

inline bool cmp (const int &x, const int &y) {
	return a[x] < a[y];
}

map <int, bool> Ex1, Ex2;

typedef long long ll;

inline ll myrand () {
	return ((1ll * (rand () << 15LL)) | (1ll * rand ())) % (ll)1e9;
}

inline bool Try_it (const int &pos, const int &f_s, const int &s_s) {
	if (!Ex1[f_s] && !Ex2[s_s]) {
		Ex1[f_s] = 1;
		Ex2[s_s] = 1;
		ans[0][pos] = f_s;
		ans[1][pos] = s_s;
		return 1;
	}
	return 0;
}


int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	srand (time (0));
	
	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	
	int till = (n + 2) / 3;
	for (int i = 1; i <= n; ++i)
		c[i] = i;

	sort (c + 1, c + n + 1, cmp);
	
	int cnt1 = 0, cnt2 = 0;

	for (int it = 1; it <= n; ++it) {
		int i = c[it];
		if (a[i] >= 1e6) {
			while (1) {
				int check = myrand () % a[i];
				if (Try_it (i, check, a[i] - check))
					continue;
				if (Try_it (i, a[i] - check, check))
					continue;
			}
		} else {
			int check = a[i] / 2;
			if (a[i] != 0)
				check %= a[i];
			else
				check = 0;
			if (Try_it (i, check, a[i] - check))
				continue;
			if (Try_it (i, a[i] - check, check))
				continue;
			/*
			check = a[c[it - 1]];
			if (Try_it (i, check, a[i] - check))
				continue;
			if (Try_it (i, a[i] - check, check))
				continue;
			*/
			for (int cnt = 1; cnt <= 100; ++cnt) {
				if (a[i] == 0)
					check = 0;
				else
					check = myrand () % a[i];
				if (Try_it (i, check, a[i] - check))
					goto here;
				if (Try_it (i, a[i] - check, check))
					goto here;
			}
			
			if (Ex1[check] == 1)
				++cnt1;
			if (Ex2[a[i] - check] == 1)
				++cnt2;
			ans[1][i] = check;
			ans[0][i] = a[i] - check;
			here:;
		}
	}
		
	if (cnt1 > till || cnt2 > till) {
		printf ("NO\n");
		return 0;
	}
	
	printf ("YES\n");

	for (int i = 1; i <= n; ++i) {
		printf ("%d ", ans[0][i]);
	}
	printf ("\n");
	for (int i = 1; i <= n; ++i) {
		printf ("%d ", ans[1][i]);
	}

	return 0;
}