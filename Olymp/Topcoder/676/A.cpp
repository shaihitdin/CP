#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

const int bpr = 1e9 + 7;

class WaterTank {
	
	public:
    double minOutputRate(vector <int> t, vector <int> x, int C) {
		double l = 0, r = 1e9;
		int n = t.size ();
		for (int cnt = 0; cnt <= 100; ++cnt) {
			double mid = (r + l) / 2;
			double now = 0;
			for (int i = 0; i < n; ++i) {
				if (now > C || now + t[i] * 1ll * x[i] - t[i] * mid > C)
					l = mid;
				now = now + t[i] * 1ll * x[i] - t[i] * mid;
				now = max (0.0, now);
			}
			if (l != mid)
				r = mid;
		}
		return r;
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif