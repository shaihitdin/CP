#include <bits/stdc++.h>

using namespace std;

const int N = 4e5;

#define last lolo

struct node {
	map <char, int> nx;
	int link;
};

node sa[N];
int sz;


inline void sa_extend (const char &ch) {
	for (sz++, p = last; p != -1; p = sa[p].link)
		sa[p].nx
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	sa[sz++].link = -1;	
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
		sa_extend (s[i]);
	return 0;
}