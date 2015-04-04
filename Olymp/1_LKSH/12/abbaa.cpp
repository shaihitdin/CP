#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string s;
int n, i;
int main() {
	freopen("abbaa.in", "r", stdin);
	freopen("abbaa.out", "w", stdout);
	ios_base :: sync_with_stdio(false);
	cin >> n;
	++n;
	while (--n) {
		cin >> s;
		bool flag = 0;
		for (i = 0; i < (int)s.size();) {
			if (s[i] == 'A') {
				if (i + 1 < (int)s.size() && s[i+1] == 'B') {
					i += 2;
					continue;
				} else {
					i += 1;
					continue;
				}
			}
			else if (s[i] == 'B') {
				if (i + 1 < (int)s.size() && s[i+1] == 'A') {
					i += 2;
					continue;
				} else {
					flag = 1;
					break;
				}
			}
		}
		if (flag) 
			cout << "NO\n";
		else 
			cout << "YES\n";
	}
return 0;
}