#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
const int N = 100001;
string s;
int i, j, p[N];
int main() {
	freopen("basis.in", "r", stdin);
	freopen("basis.out", "w", stdout);
	ios_base :: sync_with_stdio(0);
	cin >> s;
	for(i = 1; i < (int)s.size(); ++i) {
		j = p[i-1];
		while(j > 0 && s[i] != s[j]) j = p[j - 1];
		if(s[i] == s[j]) ++j;
		p[i] = j;
	}
	cout << (int)s.size() - p[(int)s.size() - 1];
return 0;
}