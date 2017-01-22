#include <bits/stdc++.h>

using namespace std;
                       
typedef long long ll;

double k, a, b;
map <double, bool> s;
vector <double> ans;
double o[110];

inline void check (double x) {
	int bb = a / x;
	if (bb * x != a)
		++bb;
   	int cnt = 0;
   	for (; bb * x <= b; ++bb) {
   		if (!s.count (bb * x))
   			return;
   		if (s[bb * x] == 0)
   			++cnt;
   	}
   	if (cnt == 0)
   		return;
   	bb = a / x;
   	if (bb * x != a)
   		++bb;
   	for (; bb * x <= b; ++bb) {
   		s[bb * x] = 1;
   	}
   	ans.emplace_back (x);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);

	cin.tie (0);

	cin >> k;

	cin >> a >> b;

	for (int i = 1; i <= k; ++i) {
		double x;
		cin >> x;
		s[x] = 0;
		o[i] = x;
	}	

	for (int i = 1; i <= k; ++i) {
		for (int j = i + 1; j <= k; ++j) {
			if (o[j] < o[i])
				swap (o[j], o[i]);
		}
	}
	
	for (int len = 1; len <= k; ++len) {
		for (int i = 1; i + len <= k; ++i) {
			check (o[i + len] - o[i]);
		}
	}
	
	for (int i = 1; i <= k; ++i) {
		check (o[i]);
	}
	
	sort (ans.begin (), ans.end ());

	cout << fixed;
	cout.precision (5);

	for (auto it : ans) {
		cout << it << "\n";
	}
	
	return 0;
}