/**
Call it magic, call it true
Call it magic when I'm with you
And I just got broken, broken into two
Still I call it magic when I'm next to you

And I don't, and I don't, and I don't, and I don't
No I don't, it's true
I don't, no I don't, no I don't, no I don't
Want anybody else but you

I don't, no I don't, no I don't, no I don't
No I don't, it's true
I don't, no I don't, no I don't, no I don't
Want anybody else but you

Call it magic, cut me into two
And with all your magic, I disappear from view
And I can't get over, can't get over you
Still I call it magic, such a precious truth

And I don't, and I don't, and I don't, and I don't
No I don't, it's true
I don't, no I don't, no I don't, no I don't
Want anybody else but you

I don't, no I don't, no I don't, no I don't
No I don't, it's true
I don't, no I don't, no I don't, no I don't
Want anybody else but you

Wanna fall, I fall so far
I wanna fall, fall so hard
And I call it magic, I call it true
I call it maaa ma-ma-maaagic

And if you were to ask me
After all that we've been through
Still believe in magic
Well yes I do
Oh yes I do
Yes I do
Oh yes I do
Of course I do



Otzhig, I love you
**/

/// izizi

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int bpr = 1e9 + 7, N = 210, oo = 1e9;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

struct state {
	pair <string, string> a[N];
	int res;
} cur, nxt, best;


set <string> c1, c2;
int n;

inline void calc (state &cur) {
	c1.clear ();
	c2.clear ();
	cur.res = 0;
	for (int i = 1; i <= n; ++i) {
		if (c1.find (cur.a[i].fe) != c1.end () && c2.find (cur.a[i].se) != c2.end ())
			++cur.res;
		c1.insert (cur.a[i].fe);
		c2.insert (cur.a[i].se);
	}
}

const int MAGIC = 5e4 + 100;

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	srand (time (0));
	
	int test;

	cin >> test;

	for (int test_num = 1; test_num <= test; ++test_num) {
		cerr << test_num << "\n";
		cout << "Case #" << test_num << ": ";
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> cur.a[i].fe >> cur.a[i].se;
		calc (cur);
		int ans = cur.res;

		double t = n, alpha = 0.99;
		for (int till = 1; till <= MAGIC; ++till) {
			nxt = cur;
			for (int i = 0; i <= int (t); ++i)
				swap (nxt.a[rand() % n + 1], nxt.a[rand() % n + 1]);
			calc (nxt);
			double d = (int)(nxt.res - cur.res);
			d = -d;
			if (d < 0 || exp((-d) / t) > (rand() % 1024) / 1024)
				cur = nxt;
			if (cur.res > ans) ans = cur.res;
			t *= alpha;
		}
		cout << ans << "\n";
	}
	
	return 0;
}