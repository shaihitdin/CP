#include <bits/stdc++.h>

using namespace std;

char a[301];
int n;

int main () {
	
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i) {
		for (int jump = 1; jump <= n; ++jump) {
		    int now = i;
			for (; now <= n && a[now] == '*'; now += jump);
			if ((now - i) / jump > 4) {
				puts ("yes");
				return 0;
			}
		}
	}

	puts ("no");
	return 0;
}