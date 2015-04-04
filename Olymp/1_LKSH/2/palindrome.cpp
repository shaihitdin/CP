#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>

using namespace std;

const int N = 100001;

long long pal1[N], pal2[N], i, l, r, ans;

string s;

int main() {
	freopen("palindrome.in", "r", stdin);
	freopen("palindrome.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> s;
	for (i = 0, l = 0, r = -1; i < (int)s.size(); ++i) {
		int pal = (i > r ? 0 : min(pal1[l + r - i], r - i)) + 1;
		while(i - pal >= 0 && i + pal < (int)s.size() && 
		s[i + pal] == s[i - pal]) ++pal;
		pal1[i] = --pal;
		if(i + pal > r)
			l = i - pal, r = i + pal;
		ans += pal;
	}
	for (i = 0, l = 0, r = -1; i < (int)s.size(); ++i) {
		int pal = (i > r ? 0 : min(pal2[l + r - i + 1], r - i + 1)) + 1;
		while(i - pal >= 0 && i + pal - 1 < (int)s.size() && 
		s[i + pal - 1] == s[i - pal]) ++pal;
		pal2[i] = --pal;
		if(i + pal - 1 > r)
			l = i - pal, r = i + pal - 1;
		ans += pal;
	}
	cout << ans;	
return 0;
}