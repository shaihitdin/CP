/**
	I'm on someone's monitor!
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int cnt[3];
map <string, int> Map;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n, m;

	cin >> n >> m;

	while(n--) {
		string x;
		cin >> x;
		Map[x] += 1;
	}
	while(m--) {
		string x;
		cin >> x;
		Map[x] += 2;
	}
	
	for(auto it : Map)
		if (it.second == 1)
			cnt[1]++;
		else if (it.second == 2)
			cnt[2]++;
		else
			cnt[0]++;

	if (cnt[1] + (cnt[0] & 1) > cnt[2])
		cout << "YES\n";
	else
		cout << "NO\n";
	
	return 0;
}