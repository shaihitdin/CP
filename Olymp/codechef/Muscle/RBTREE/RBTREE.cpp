#include <iostream>
#include <stdio.h>
 
using namespace std;
 
#define mkp make_pair
#define F first
#define S second
 
const unsigned int N = 1073741823, Nn = 100000001;
unsigned int l_cash[Nn], r_cash[Nn], col_cash[Nn];
 
inline unsigned int get_l(const unsigned int &x) {
	if (x < Nn && l_cash[x] != 0)	return l_cash[x];
	if (x > N)
		return x;
	if (x < Nn) {
		l_cash[x] = get_l(x << 1);	
		return l_cash[x];
	}
	return get_l (x << 1);
}
 
inline unsigned int get_r(const unsigned int &x) {
	if (x < Nn && r_cash[x] != 0)	return r_cash[x];
	if (x > N)
		return x;
	if (x < Nn) {
		r_cash[x] = get_r((x << 1) + 1);
		return r_cash[x];
	}
	return get_r ((x << 1) + 1);
}
 
inline unsigned int rev(const unsigned int &x) {
	if(x == 1)	return 2;
	else	return 1;
}
 
inline unsigned int get_col(const unsigned int &x) {
	if (x < Nn && col_cash[x] != 0) return col_cash[x];
	if (x < Nn) {
		col_cash[x] = rev (get_col(x >> 1));
		return col_cash[x];
	}
	return rev (get_col(x >> 1));
}
 
inline bool parent(const unsigned int &par, const unsigned int &x) {
	unsigned int l1 = get_l (par);
	unsigned int r1 = get_r (par);
	unsigned int l2 = get_l (x);
	unsigned int r2 = get_r (x);
	if(l1 <= l2 && r2 <= r1)	return 1;
	return 0;
}
 
inline void add (pair <unsigned int, unsigned int> &res, const unsigned int &pos) {
	if (get_col (pos) == 1)	++res.F;
	else	++res.S;
}
 
inline pair <unsigned int, unsigned int> get_ans (const unsigned int &x, const unsigned int &y) {
	unsigned int pr = x;
	pair <unsigned int, unsigned int> res;
	res = mkp (0, 0);
	while (!parent (pr, y)) {
		add (res, pr);
		pr >>= 1;
	}
	while (pr != y) {
		add (res, pr);
		if (parent (pr << 1, y))
			pr <<= 1;
		else
			pr = (pr << 1) + 1;
	}
	add (res, y);
	return res;
}
 
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	unsigned int t, flag = 0;
	scanf ("%d\n", &t);
	++t;
	col_cash[1] = 1;
 
	while (--t) {
		char q;
		getchar();
		q = getchar();
		getchar();
		if (q == 'i') 
			flag = !flag;
		else {
			unsigned int x, y;
			scanf ("%d%d\n", &x, &y);
			if (x > y)	swap (x, y);
			pair <unsigned int, unsigned int> res; // First = black, second = red
			res = get_ans (x, y);
			unsigned int e;
			if (q == 'b') 
				e = 0;
			else 
				e = 1;
			if (flag) 
				e ^= 1;
			else
				e ^= 0;
			if (e)
				printf ("%d\n", res.S);
			else
				printf ("%d\n", res.F);
		}
	}	
	
	return 0;
}