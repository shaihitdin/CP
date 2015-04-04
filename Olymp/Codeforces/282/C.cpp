#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
const int N = 100001;
string s;
int ans[N], d[N];
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio(0);
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (i > 0)
			d[i] = d[i - 1];
		if (s[i] == '(')
			++d[i];
		else if (s[i] == ')')
			--d[i];
	}
	int last = -1;
	for (int i = 0; i < n; ++i)
		if (d[i] < 0) {
			puts("-1");
			return 0;
		}
    for (int i = 0; i < n; ++i)
    	if (s[i] == '#')
    		last = i;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
    	if(s[i] == '#') {
    		++cnt;
    		ans[i] = 1;
    	}
    	if (d[n - 1] - cnt < 0 || d[i] - cnt < 0 ) {
    		puts("-1");
			return 0;
		}
    	if (i == last) {
    		ans[i] += min (d[i] - cnt, d[n - 1] - cnt);
    		cnt += min (d[i] - cnt, d[n - 1] - cnt);
    	}
    }
    if (d[n - 1] - cnt != 0) {
    	puts ("-1");
    	return 0;
    }
	for (int i = 0; i < n; ++i) {
		if (ans[i] != 0)
			cout << ans[i] << "\n";
	}
    return 0;
}