#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int oo = 1e9;
const int N = 1e5 + 100;

bool u[N];
int t_val[N];
vector <int> cc;
char q_type[N];
int x[N], k[N], d[N];

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	freopen ("out.t", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int q;

	cin >> q;

	for (int i = 1; i <= q; ++i) {
		cin >> q_type[i];
		if (q_type[i] == '+') {
			cin >> x[i];
			cc.emplace_back (x[i]);
		} else if (q_type[i] == '-') {
			cin >> x[i];
			cc.emplace_back (x[i]);
		} else {
			cin >> k[i] >> d[i];
		}
	}
	
	sort (cc.begin (), cc.end ());
	cc.resize (unique (cc.begin (), cc.end ()) - cc.begin ());
	
	for (int i = 1; i <= q; ++i) {
		if (q_type[i] == '+' || q_type[i] == '-') {
			x[i] = lower_bound (cc.begin (), cc.end (), x[i]) - cc.begin () + 1;
		}
	}
	
	for (int i = 1; i <= cc.size (); ++i) {
		t_val[i] = cc[i - 1];
	}
	
	int cnt = 0;

	for (int q_num = 1; q_num <= q; ++q_num) {
		if (q_type[q_num] == '+') {
			u[x[q_num]] = 1;
			++cnt;
		} else if (q_type[q_num] == '-') {
			u[x[q_num]] = 0;
			--cnt;
			//cerr << "DEL " << t_val[x[q_num]] << "\n";
		} else {
			if (cnt < k[q_num]) {
				cout << 0 << "\n";
				continue;
			}
			if (k[q_num] == 1) {
				cout << cnt << "\n";
				continue;
			}
			int i = 0, j = 0;
			while (!u[i]) ++i;
			for (int ds = 0; ds < k[q_num] - 1; ++ds, ++j)
				while (!u[j]) ++j;
			while (!u[j]) ++j;
			int ans = 0;
			if (t_val[j] - t_val[i] <= d[q_num])
				++ans;
			//cerr << "KEK " << ans << " " << t_val[i] << " " << t_val[j] << "\n";
			for (++i, ++j; j <= cc.size (); ++i, ++j) {
				while (j <= cc.size () && !u[j]) ++j;
				if (j > cc.size ())
					break;
				while (!u[i]) ++i;
				ans += (t_val[j] - t_val[i] <= d[q_num]);
			}
			cout << ans << "\n";
		}
		if (q_num % 1000 == 0) {
			cerr << q_num << "\n";
		}
	}
	
	return 0;
}