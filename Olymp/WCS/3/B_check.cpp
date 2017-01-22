#include <bits/stdc++.h>

using namespace std;

int a[6], b[6];
set <int> Set;

inline void rec (int pos) {
	if (pos == 6) {
		Set.clear ();
		int val = 0;
		for (int i = 1; i <= 5; ++i)
			Set.insert (val += a[i]);
		bool flag = 0;
		val = 0;
		for (int i = 1; i <= 5; ++i)
			flag |= (Set.find (val += b[i]) != Set.end ());
		if (!flag) {
			for (int i = 1; i <= 5; ++i)
				cout << a[i] << " ";
			cout << "\n";
			for (int i = 1; i <= 5; ++i)
				cout << b[i] << " ";
			exit (0);
		}
		return;
	}
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 5; ++j) {
			if (a[pos - 1] == i || b[pos - 1] == j)
				continue;
			a[pos] = i, b[pos] = j;
			rec (pos + 1);
		}
	}
}

int main () {

	#ifdef UNBROKEN
	freopen ("in", "r", stdin);
	#endif

	rec (1);

	return 0;
}