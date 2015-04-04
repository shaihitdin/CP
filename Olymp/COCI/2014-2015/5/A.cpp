#include <iostream>
#include <stdio.h>
using namespace std;
int s[10], ans, temp;
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	for (int i = 0; i < 8; ++i)
		cin >> s[i];
	ans = 0;
	for (int i = 0; i < 8; ++i) {
		temp = 0;
		for (int j = i, cnt = 1; cnt <= 4; j = (j + 1) % 8, ++cnt)
			temp += s[j];
		ans = max (ans, temp);	
	}
	cout << ans;
	return 0;
}