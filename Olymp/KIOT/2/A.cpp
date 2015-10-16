#include <iostream>
#include <stdio.h>
#include <math.h>
#include <map>


using namespace std;

map <int, int> Map;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	const long double eps = 1 / 1e9;
	
	int n;
	
	while (cin >> n) {
		Map.clear ();
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			if (x == 0)
				continue;
			++Map[x];
		}
		bool flag = 1;
		for (map <int, int> :: iterator tit = Map.begin (); tit != Map.end (); ++tit) {
			pair <int, int> it = *tit;
			int x = sqrt (it.first) + eps;
			x -= 2;
			for (; x * x < it.first; ++x);
			if (x * x == it.first) {
				continue;
			}
			if (it.second % it.first != 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}