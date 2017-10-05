#include <bits/stdc++.h>

using namespace std;

const int N = 5000;


string s[55];
int p[N];
string ans[N];

inline int get_p (int x) {
	if (x == p[x])
		return x;
	return p[x] = get_p (p[x]);
}

inline void Merge (int x, int y) {
	x = get_p (x), y = get_p (y);
	p[x] = y;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n - k + 1; ++i) {
		cin >> s[i];
	}

	int lst = 0;

	for (int i = 1; i <= n; ++i)
		p[i] = i;
	
	for (int i = 1; i <= n - k + 1; ++i) {
		if (s[i] == "YES") {
			lst = i;
		}
	}
	
	if (lst == 0) {
		for (int i = 1; i <= n; ++i) {
			cout << "A ";
		}
		return 0;
	}
	
	
	
	for (int i = lst - 1; i >= 1; --i) {
		if (s[i] == "NO") {
			Merge (i, i + k - 1);
		}
	}
	
	for (int i = lst + k; i <= n; ++i) {
		if (s[i - k + 1] == "NO") {
			Merge (i, i - k + 1);
		}
	}
	
	string t;
	for (int i = 1; i <= 8; ++i)
		t += char ('a' + i);

	for (int i = 1; i <= n; ++i) {
		next_permutation (t.begin (), t.end ());
		ans[i] = t;
	}
	
	for (int i = 1; i <= n; ++i) {
		ans[i][0] = ans[i][0] - 'a' + 'A';
	}
	
	for (int i = 1; i <= n; ++i) {
		cout << ans[get_p (i)] << " ";
	}
	
	return 0;
}