#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long double ld;
typedef long long ll;

const int N = 1e4 + 100;
const ld eps = 1 / 1e7;

ld a[N];
vector <int> ans;
vector <pair <ld, int> > ans2;
ll b[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n;
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i] * 100;
	}
	for (int i = 1; i <= n; ++i) {
		if (b[i] >= 0) {
			if (b[i] <= 100)
				continue;
			ans.emplace_back (i);
		} else {
			ans2.emplace_back (make_pair (b[i], i));
		}
	}
	
	sort (ans2.begin (), ans2.end ());
	for (int i = 0; i + 1 < ans2.size (); i += 2) {
		if (ans2[i].first * ans2[i + 1].first > 10000) {
			ans.emplace_back (ans2[i].second);
			ans.emplace_back (ans2[i + 1].second);
		}
	}
		
	if (ans.size () == 0) {
		int mxid = 1;
		for (int i = 2; i <= n; ++i)
			if (a[mxid] < a[i])
				mxid = i;
		//ans.push_back (mxid);
		if (ans2.size () > 1) {
			if (ans2[0].first * ans2[1].first / 10000.0 > b[mxid] / 100.0) {
				ans.emplace_back (ans2[0].second);
				ans.emplace_back (ans2[1].second);
			}
		}
		if (ans.size () == 0)
			ans.push_back (mxid);
	}
	
	sort (ans.begin (), ans.end ());

	cout << ans.size () << "\n";

	for (int i = 0; i < ans.size (); ++i)
		cout << ans[i] << " ";
	
	return 0;
}