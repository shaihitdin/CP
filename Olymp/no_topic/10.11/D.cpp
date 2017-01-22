#include <iostream>

using namespace std;

int cnt[3];

int Election (int a, int b, int c) {
	++cnt[a], ++cnt[b], ++cnt[c];
	return cnt[1] > cnt[0];
}

int main () {
	int a, b, c;
	cin >> a >> b >> c;
	cout << Election (a, b, c);

	return 0;
}