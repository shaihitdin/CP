#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "tetris."

typedef long long ll;

const int N = 1e5 + 100;

int n, m;
char s[N];

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	scanf("%d %d\n", &n, &m);
	int ans = 0, cnt = 0;
	forn(i, 1, n) {
		scanf("%s\n", s);
		bool flag = 1;
		forn(j, 0, m - 1) 
			flag &= (s[j] == '*');
		if (!flag) {
			ans += (cnt * (cnt + 1)) / 2;
			cnt = 0;
		}
		else
			++cnt;
	}
	ans += (cnt * (cnt + 1)) / 2;
	cnt = 0;

	printf("%d\n", ans);

	return 0;
}