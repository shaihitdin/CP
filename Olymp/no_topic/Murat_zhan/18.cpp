#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int main () {

	string a, b;
	
	a = "a";

	while (a.size () < 200) {
		b = a;
		for (int i = 0; i < b.size (); ++i)
			b[i] = ((a[i] == 'a') ? ('b') : ('a'));
		a += b;
	}
	
	
	for (int i = 188; i <= 192; ++i)
		cout << a[i];
	
	return 0;
}