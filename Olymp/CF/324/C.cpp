#include <bits/stdc++.h>

using namespace std;

int n, t;
string s1, s2;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> t;

	cin >> s1 >> s2;

	string t_s;
	
	t_s.resize (n);
	
	int diff_cnt = 0;
	
	int normal = 0;

	for (int i = 0; i < n; ++i)
		diff_cnt += s1[i] != s2[i];
	
	normal = n - diff_cnt;
	
	int diff1 = 0, diff2 = 0;

	for (int i = 0; i < n; ++i) {
		if (s1[i] == s2[i]) {
			t_s[i] = s1[i];
			continue;
		}
		if (diff1 == diff2)
			if (diff1 + diff_cnt <= t && t <= diff1 + diff_cnt + normal)
				break;
		
		if (diff1 < diff2) {
			t_s[i] = s2[i];
			++diff1;
		} else {
			t_s[i] = s1[i];
			++diff2;
		}
		--diff_cnt;
	}
	
	for (int i = 0; i < n; ++i) {
		if (t_s[i])
			continue;
		if (s1[i] == s2[i]) {
			t_s[i] = s1[i];
			continue;
		}
		if ('a' != s1[i] && 'a' != s2[i]) {
			t_s[i] = 'a';
			++diff1;
			++diff2;
		} else if ('b' != s1[i] && 'b' != s2[i]) {
			t_s[i] = 'b';
			++diff1;
			++diff2;		
		} else if ('c' != s1[i] && 'c' != s2[i]) {
			t_s[i] = 'c';
			++diff1;
			++diff2;		
		}
	}
	
	for (int i = 0; i < n && diff1 < t; ++i) {
		if (s1[i] == s2[i]) {
			if ('a' != s1[i] && 'a' != s2[i]) {
				t_s[i] = 'a';
				++diff1;
				++diff2;
			} else if ('b' != s1[i] && 'b' != s2[i]) {
				t_s[i] = 'b';
				++diff1;
				++diff2;		
			}			
			continue;
		}
	}
	
	if (diff1 != t || diff2 != t) {
		cout << -1;
	} else {
		cout << t_s;
	}
	
	return 0;
}