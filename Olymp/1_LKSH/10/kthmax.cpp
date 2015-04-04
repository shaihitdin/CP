#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<time.h>

using namespace std;
const  int N = 100001;

struct node {
	long long x, cnt, y;
	node *l, *r;
	node() {l = r = NULL; x = cnt = 0; }
};

node *root, *L, *R, *R1, *tmp, *mid;
long long n, m, i, l, r, x;
long long q;

inline long long cnt (node *it) {
	return it ? it->cnt : 0;
}

inline void upd (node *it) {
	if(it) {
	it->cnt = 1 + cnt(it->l) + cnt(it->r);
	}
}

inline void sp (node *t, long long x, node *&l, node *&r) {
	upd(t); upd(l); upd(r);
	if(!t) {
		r = l = 0; return;
	}	
	if(t->x >= x) sp(t->l, x, l, t->l), r = t;
	else		   sp(t->r, x, t->r, r), l = t;
	upd(l); upd(r); upd(t);
}

inline void me (node *&t, node *l, node *r) {
     upd(l); upd(r); upd(t);
     if(!l || !r) {
          t = l ? l : r; return;
     }
     if(l->y > r->y) me(l->r, l->r, r), t = l;
     else	me(r->l, l, r->l), t = r;
     upd(l); upd(r); upd(t);
}

inline long long get (node *t, int x) {
		if(x == cnt(t->r) + 1) return t->x;
		if(cnt(t->r) >= x) return get(t->r, x);
		else return get(t->l, x - cnt(t->r) - 1);
}

inline long long read()
{
  int c = getchar();
  long long x = 0, sign = 1;
  while (c <= 32)
    c = getchar();
  if (c == '+') {
  	sign = 1;
  }
  if (c == '-') {
  	sign = -1;
  }
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getchar();
  return x*sign;
}
int rndm[N];
int main() {
	freopen ("kthmax.in", "r", stdin);
	freopen ("kthmax.out", "w", stdout);
	scanf("%d",&m);
	srand (time (0) );
	for (int i = 1; i <= m; ++i)
		rndm[i] = i;
	random_shuffle (rndm + 1, rndm + m + 1);
	for (i = 1; i <= m; ++i) {
	    scanf ("%d%d", &q, &x);
	    if (q == 1) {
			tmp = new node();
			tmp->x = x;
			tmp->cnt = 1;
			tmp->y = rndm[i];
			sp (root, x, L, R);
			me (R, tmp, R);
			me (root, L, R);
		}
		if (q == 0) {
			printf("%lld\n", get (root, x));
		}
		if (q == -1) {
			sp (root, x, L, R);
			sp (R, x+1, mid, R1);
			me (root, L, R1);
		}
	}
return 0;
}