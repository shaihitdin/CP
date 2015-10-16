#include <iostream>
#include <set>
#include <stdlib.h>
#include <map>
#include <stdio.h>
using namespace std;
#define mkp make_pair
#define F first
#define S second
typedef long long ll;
const int N = (2e6 + 1);
set <pair <pair <int, int>, pair <int, int> > > mp;
pair <pair <int, int>, pair <int, int> > st[N];
int d[N];
bool rev[N];
int a[3], b[3];
int stq, enq;
pair <pair <int, int>, pair <int, int> > v;
pair <int, int> fp, sp;
int dist;
bool re;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> a[1] >> b[1] >> a[2] >> b[2];
	st[enq++] = mkp (mkp (a[1], b[1]), mkp (a[2], b[2]));
	while (stq < enq) {
		re = rev[stq];
		dist = d[stq];
		if (stq > (900000))
			break;
		v = st[stq++];
		fp = mkp (v.F.F, v.F.S);
		sp = mkp (v.S.F, v.S.S);
		if ((long long)fp.F * fp.S < (long long)sp.F * sp.S) {
			swap (fp, sp);
			re = !re;
		}
		if ((long long)fp.F * fp.S == (long long)sp.F * sp.S) {
			if (re == 1)
				swap (fp, sp);
			cout << dist << "\n" << fp.F << " " << fp.S << "\n" << sp.F << " " << sp.S;
			exit (0);
		}
		if (!(fp.F & 1)) {
			if (mp.insert (mkp (mkp (fp.F >> 1, fp.S), sp)).S == 1) {
				rev[enq] = re;
				d[enq] = dist + 1;
				st[enq++] = mkp (mkp (fp.F >> 1, fp.S), sp);
			}
		}
		if (!(fp.S & 1)) {
			if (mp.insert (mkp (mkp (fp.F, fp.S >> 1), sp)).S == 1) {
				rev[enq] = re;
				d[enq] = dist + 1;			
				st[enq++] = mkp (mkp (fp.F, fp.S >> 1), sp);
			}
		}
		if (!(fp.F % 3)) {
			if (mp.insert (mkp (mkp (fp.F - (fp.F / 3), fp.S), sp)).S == 1) {
				rev[enq] = re;
				d[enq] = dist + 1;
				st[enq++] = mkp ( mkp (fp.F - (fp.F / 3), fp.S), sp);
			}
		}
		if (!(fp.S % 3)) {
			if (mp.insert (mkp (mkp (fp.F, fp.S - (fp.S / 3)), sp)).S == 1) {
				rev[enq] = re;
				d[enq] = dist + 1;
				st[enq++] = mkp (mkp (fp.F, fp.S - (fp.S / 3)), sp);
			}
		}
	}
	puts ("-1");
	exit (0);
}