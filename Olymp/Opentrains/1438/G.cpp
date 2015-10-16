#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> PII;

const int N = 31;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define pb push_back
                         
ll h, a[4];
char col[] = {' ', 'W', 'G', 'B'};
vector <char> ans;

bool running_out_of_time_motherfucker() {
	return ((clock() / (1.0 * CLOCKS_PER_SEC)) > 0.99);
}

void rec(int i) {        /*
	if (running_out_of_time_motherfucker()) {
		cout << "Impossible\n";
		exit(0);
	}                  */
	if (i == 0) {
		forn(k, 1, 3)
			if (a[k]) return;
		reverse(ans.begin(), ans.end());
		for (auto c : ans)
			cout << c;
		exit(0);	
	}        
	forn(k, 1, 3) {
		if (a[k] < i) continue;
		a[k] -= i;
		ans.pb(col[k]);
		rec(i - 1);
		ans.pop_back();
		a[k] += i;
	}
}

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> a[1] >> a[2] >> a[3];
	h = 1;             
	while (h * (h + 1) / 2 < a[1] + a[2] + a[3]) ++h;
	if (h * (h + 1) / 2 != a[1] + a[2] + a[3]) {
		cout << "Impossible\n";
		return 0;
	}
	rec(h);
	cout << "Impossible\n";
	
	return 0;
}
