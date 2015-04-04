#include <iostream>
#include <utility>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

string a[4];

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin >> a[1] >> a[2] >> a[3];
	for (int i = 1; i <= 3; ++i) {
		for (int j = i + 1; j <= 3; ++j) {
			if (a[i].size() == a[j].size()) {
				if (a[i] > a[j])
					swap (a[i], a[j]);
			}
			else {
				if (a[i].size() > a[j].size())
					swap (a[i], a[j]);
			}
		}
	}
	cout << a[3];
	return 0;
}