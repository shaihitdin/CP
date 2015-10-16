#include <bits/stdc++.h>

using namespace std;

int cnt;
int n;

vector <int> a[20000];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n;
	
	cin >> n;
	
	int i = 1, j = 1;
	int sv = 0;
	
	for (i = 1; cnt < n; ++i) {
		for (j = 1; j < i; ++j) {
			++cnt;
			a[i].emplace_back (cnt);
			a[j].emplace_back (cnt);
			if (cnt == n)
				goto end;
		}
		sv += (i - 1);
	}
	
	end:;
		
	if (j == i - 1) {
		sv += (i - 1);
		++i;
	}	
	cout << i - 1 << "\n";
	
	for (int k = 1; k < i; ++k) {
		for (auto it : a[k]) {
			if (it > sv) {
				break;
			}
			cout << it << " ";
		}
		cout << "\n";
	}

	return 0;
}