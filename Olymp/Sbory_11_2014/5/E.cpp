#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

multiset <double> s;
double x,y;
int n;
int main () {
	freopen ("midnum.in", "r", stdin);
	freopen ("midnum.out" ,"w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%lf", &x);
		s.insert(x);
	}
	while(s.size() != 1) {
		x = *s.begin();
		y = *s.rbegin();
		s.erase (s.begin());
		auto it = s.end ();
		--it;
		s.erase (it);
		s.insert((x + y) / 2.0);
	}
	printf ("%.6lf", *s.begin());
	return 0;
}