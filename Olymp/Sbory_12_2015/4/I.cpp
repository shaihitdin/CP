#include <iostream>
#include <unordered_map>
#include <stdio.h>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int N = 1e5 + 100;

int n, a[N];

typedef long long ll;

const int sz = 15e4 + 131;

map <int, bool> mod[sz];

map <int, bool> stupid_cnt;
//map <int, int> mod[32];

inline bool get (int x) {
	return mod[x % sz][x];
}

inline void pl (int x) {
	mod[x % sz][x] ^= 1;
}

inline void add (int x, ll i) {
	bool sign = x < 0;
	x = abs (x);
	if (sign) {
		pl (((1 << i) - (x & ((1 << i) - 1))) & ((1 << i) - 1));
	} else {
		pl (x & ((1 << i) - 1));
	}
}

int tmp[N];

int main () {

	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	
	scanf ("%d", &n);

	int ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
		ans ^= a[i];
		stupid_cnt[a[i]] ^= 1;
	}	

	for (int i = 1; i <= n; ++i) {
		stupid_cnt[a[i]] ^= 1;
		tmp[i] = stupid_cnt[a[i]];
		if (tmp[i] & 1)
			ans ^= -1;
	}
	
	stupid_cnt.clear ();
	
	//vector <int> cc;
	
	for (ll j = 31; j > 0; --j) {
		//cc.clear ();
		for (int i = 1; i <= n; ++i)
			add (a[i], j);
		for (int i = 1; i < n; ++i) {
			int sd;
			add (a[i], j);
			if (a[i] < 0) {
				sd = ((1 << j) - ((-a[i]) & ((1 << j) - 1))) & ((1 << j) - 1);
			} else {
				sd = a[i] & ((1 << j) - 1);
			}
			int s = get (sd) ^ tmp[i];
			if (s & 1)
				ans ^= ((1 << j) - 1);
			tmp[i] ^= s;
		}		
		for (int i = 0; i < sz; ++i)
			mod[i].clear ();
	}
	/*
	for (int i = 1; i < n; ++i) {
		del (a[i]);
		int sd;
		for (ll j = 31; j > 0; --j) {
			if (a[i] < 0) {
				sd = ((1 << j) - ((-a[i]) & ((1 << j) - 1))) & ((1 << j) - 1);
			} else {
				sd = a[i] & ((1 << j) - 1);
			}
			int s = get (j, sd) - tmp;
			if (s & 1)
				ans ^= ((1 << j) - 1);
			tmp += s;
		}
	}
	*/
	printf ("%d", ans);
	
	fprintf (stderr, "%d", clock () * 1000 / CLOCKS_PER_SEC);
	
	return 0;
}