#include <bits/stdc++.h>

using namespace std;

inline int play (int x) {
	cout << x << "\n";
	fflush (stdout);
	cin >> x;
	if (x == -1)
		exit (0);
	return x;
}

inline int calc (int x) {
	return ((x * 1ll * 487237) + 1011807) % (1 << 20);
}

int nxt[1 << 20];

int main () {
    /*
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	*/
	srand (time (0));
	
	int val;

	cin >> val;

	for (int i = 0; i < (1 << 20); ++i) {
		nxt[i] = i;
	}
	
	while (1) {
		int n_val = play (1);
		if (n_val < val) {
			for (int i = 0; i < (1 << 20); ++i)
				if (__builtin_popcount (nxt[i]) % 2 == 1)
					nxt[i] = -1;
		} else {
			for (int i = 0; i < (1 << 20); ++i)
				if (__builtin_popcount (nxt[i]) % 2 == 0)
					nxt[i] = -1;
		}
		for (int i = 0; i < (1 << 20); ++i)
			if (nxt[i] != -1)
				nxt[i] = calc (nxt[i]);
		int cnt = 0;
		for (int i = 0; i < (1 << 20); ++i) {
			cnt += (nxt[i] != -1);
		}
		val = n_val;
		if (cnt == 1)
			break;
	}
	
	int ss = -1;
	for (int i = 0; i < (1 << 20); ++i)
		if (nxt[i] != -1)
			ss = nxt[i];
	while (1) {
		if (__builtin_popcount (ss) % 2 == 1) {
			val = play (val);
		} else {
			val = play (1);
		}
		ss = calc (ss);
	}

	return 0;
}