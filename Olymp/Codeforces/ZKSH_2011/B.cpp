#include <bits/stdc++.h>

using namespace std;

string AntiMap[10];
map <string, int> Map;
int cnt[10];


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	Map["S"] = 1;
	Map["M"] = 2;
	Map["L"] = 3;
	Map["XL"] = 4;
	Map["XXL"] = 5;
	AntiMap[5] = "XXL";
	AntiMap[4] = "XL";
	AntiMap[3] = "L";
	AntiMap[2] = "M";
	AntiMap[1] = "S";

	for (int i = 1; i <= 5; ++i)
		cin >> cnt[i];

	int k;

	cin >> k;

	for (int i = 1; i <= k; ++i) {
		string q;
		int t_num;
		cin >> q;
		t_num = Map[q];
		for (int l = t_num, r = t_num; l >= 1 || r <= 5; --l, ++r) {
			if (cnt[r]) {
				cout << AntiMap[r] << "\n";
				--cnt[r];
				break;
			}
			if (l > 0 && cnt[l]) {
				cout << AntiMap[l] << "\n";
				--cnt[l];
				break;
			}
		}
	}

	return 0;
}