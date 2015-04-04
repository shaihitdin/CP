/*
ID: shaihit1
PROG: hamming
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 30;

vector <int> ans;
int n, b, d;

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

inline int hamming_dist (const int &x, const int &y) {
	/**
	int res = 0;
	for (int i = 0; i < b; ++i)
		res += (bit (x, i) ^ bit (y, i));
	return res;
	**/
	return __builtin_popcount (x ^ y);
}

int main() {
	
	freopen ("hamming.in", "r", stdin);
	freopen ("hamming.out", "w", stdout);

	scanf ("%d%d%d", &n, &b, &d);
	ans.push_back (0);
	for (int i = 1; i < (1 << b); ++i) {
		for (auto it : ans)
			if (hamming_dist (it, i) < d)
				goto no;
		ans.push_back (i);
		if (ans.size() == n)
			break;
		no:;	
	}
	int i = 0;
	for (; i < ans.size(); ++i) {
		bool flag = 0;
		if (i && i % 10 == 0) { 
			putchar ('\n');
			bool flag = 1;
		}
	    		
		printf ("%d", ans[i]);
		if (((i + 1) % 10 != 0 || (i + 1 == ans.size())) && !flag)
	    	putchar (i + 1 == ans.size() ? '\n' : ' ');

	}
	
	return 0;
}
