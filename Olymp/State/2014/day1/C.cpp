#include <iostream>
#include <set>
#include <assert.h>
#include <stdio.h>
using namespace std;
#define mkp make_pair
#define F first
#define S second
multiset <pair <long long, long long>> s;
long long n, a[100001];
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	assert (mkp (1, 2) > mkp (1, 1));
	scanf ("%I64d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%I64d", &a[i]);
		s.insert (mkp (a[i], 0));
	}
	while (1) {				
		auto p1 = *s.begin();
		s.erase (s.begin() );
		if (s.empty() ) {
			printf ("%I64d", p1.S);
			return 0;
		} 
		auto p2 = *s.begin();
		s.erase (s.begin() );
		s.insert (mkp (p1.F + p2.F, max (p1.S + 1, p2.S + 1) ) );
	}
	return 0;
}