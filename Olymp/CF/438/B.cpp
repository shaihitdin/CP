#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100;

int a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int h, m, s, t1, t2;

	cin >> h >> m >> s >> t1 >> t2;

	h %= 12;
	t1 %= 12;
	t2 %= 12;

	h *= 5, t1 *= 5, t2 *= 5;

	//cerr << h << " " << m << " " << s << " " << t1 << " " << t2 << "\n";
	int cnt = 0;
	for (int i = t1; i != t2; ++i) {
		if (i == 60)
			i = 0;
		if (i == h)
			++cnt;
		if (i == m)
			++cnt;
		if (i == s)
			++cnt;
		/*
		if (i == t2)
			break;
		*/
	}
	
	if (cnt % 3 == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}