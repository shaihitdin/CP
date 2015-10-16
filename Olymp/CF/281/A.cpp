#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int s[1001];
bool banned[1001];
string h, a;
char command, card;
int m, t, n;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> h >> a;
	cin >> n;
	++n;
	while (--n) {
		cin >> t >> command >> m >> card;
		if (command == 'h') {
			if (s[100 + m] + ( (card == 'y') ? 1 : 2) > 1 && !banned[100 + m]) {
				cout << h << " " << m << " " << t << "\n";
				banned[100 + m] = 1;
			}
			s[100 + m] += ( (card == 'y') ? 1 : 2);
		}
		else {
			if (s[200 + m] + ( (card == 'y') ? 1 : 2) > 1 && !banned[200 + m]) {
				cout << a << " " << m << " " << t << "\n";
				banned[200 + m] = 1;
			}
			s[200 + m] += ( (card == 'y') ? 1 : 2);		
		}
	}
	return 0;
}