/// Oh, my dear
#include <bits/stdc++.h>

using namespace std;

int n, s;

inline int get_ans (int pos) {
	cout << pos << "\n";
	fflush (stdout);
	int x;
	cin >> x;
	if (x == s)
		exit (0);
	return x;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n >> s;

	int q1 = get_ans (1), q2 = get_ans (n);

	if (q1 < q2) {
		int l = 1, r = n;
		while (r - l > 1) {
			int mid = (r + l) >> 1;
			int x = get_ans (mid);
			if (s < x)
				r = mid;
			else
				l = mid;
		}
	} else {
		if (s < q2) {
			int l = 1, r = n;
			while (r - l > 1) {
				int mid = (r + l) >> 1;
				int x = get_ans (mid);
				if (x > q2) {
					l = mid;
				} else {
					if (x < s)
						l = mid;
					else
						r = mid;
				}
			}
		} else {
			int l = 1, r = n;
			while (r - l > 1) {
				int mid = (r + l) >> 1;
				int x = get_ans (mid);
				if (x < q1) {
					r = mid;
				} else {
					if (x < s)
						l = mid;
					else
						r = mid;
				}
			}
		}
	}
	
	assert (0);
	
	return 0;
}