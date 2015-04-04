#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;
string s;
int n, correct, ans, found, mult;
int main () {
	freopen ("stupid.in", "r", stdin);
	freopen ("stupid.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		ans = 0;
		reverse (s.begin(), s.end() );
		for (int j = 0; j < s.size(); ++j) {
			if (s[j] == '?') {
				correct = j % 3;
			}
			else if (j % 3 == 0) {
				ans += ( (s[j] - '0') * 9);
			}
			else if (j % 3 == 1) {
				ans += ( (s[j] - '0') * 3);			
			}
			else if (j % 3 == 2) {
				ans += ( (s[j] - '0') * 7);			
			}	
		}
		if (correct == 0) {
			mult = 9;
		}
		if (correct == 1) {
			mult = 3;
		}
		if (correct == 2) {
			mult = 7;
		}
		for (int j = 0; j <= 9; ++j) {
			if ( (ans + (mult * j) ) % 10 == 0)
				found = j;
		}
		for (int j = 0; j < s.size(); ++j) {
				if (s[j] == '?') {
					s[j] = (found + '0');
				}
		}
		reverse (s.begin(), s.end() );
		cout << "Scenario #" << i << ":\n" << s << "\n\n";
		
	}	
	return 0;
}