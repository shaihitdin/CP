/// izizi

#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 100;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

inline ld dist2 (ld x, ld y) {
	return sqrt (x * x + y * y);
}

vector <pair <ld, int> > cc;
ld ans = 1e18, sum;
ld x[N], y[N];
ld bx, by, ax, ay, tx, ty;
ld val[N];
ll n;

inline void solve () {

	//iterate which will be done by a
	
	cc.clear ();
	
	for (int i = 1; i <= n; ++i)
		cc.eb (mp (dist2 (x[i] - bx, y[i] - by) - val[i] / 2, i));
	
	sort (cc.begin (), cc.end ());
	
	for (int i = 0; i <= n; ++i) {
		if (i) {
			sum -= val[i];
			sum += dist2 (x[i] - ax, y[i] - ay) + val[i] / 2;
		}
		for (auto it : cc) {
			if (it.se == i)
				continue;
			/*
			if (it.fe > 0)
				break;
			*/
			sum += it.fe;
			break;
		}
		ans = min (ans, sum);
		if (i) {
			sum += val[i];
			sum -= (dist2 (x[i] - ax, y[i] - ay) + val[i] / 2);
		}
		for (auto it : cc) {
			if (it.se == i)
				continue;
			/*
			if (it.fe > 0)
				break;
			*/
			sum -= it.fe;
			break;
		}
	}
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	

	cin >> ax >> ay >> bx >> by >> tx >> ty;
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}

	for (int i = 1; i <= n; ++i) {
		val[i] = dist2 (x[i] - tx, y[i] - ty) * 2;
		sum += val[i];
	}

	
	cout << fixed;
	cout << setprecision (7);

	if (n == 1) {
		cout << min (dist2 (x[1] - ax, y[1] - ay), dist2 (x[1] - bx, y[1] - by)) + dist2 (x[1] - tx, y[1] - ty);
		return 0;
	}
	
	solve ();
	
	swap (ax, bx);
	swap (ay, by);

	solve ();
	
	cout << ans;
	
	return 0;
}