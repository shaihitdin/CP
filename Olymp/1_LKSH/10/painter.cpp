#include<iostream>
#include<stdio.h>	
#include<algorithm>
using namespace std;
const int N = (1<<20), inf = 1000000009;
struct tree {
	int left, right, sum, num;
	bool flag;
	int change;
};
tree t[N * 8];
int sz, m, i, l, r;
char q;
inline void push (int v, int Tl, int Tr) {
	if(t[v].flag) {
		if(t[v].change == 1) {
			t[v].left = 1;
			t[v].right = 1;
			t[v].sum = Tr - Tl + 1;
			t[v].num = 1;
			if(v < sz) {
				t[v * 2].flag = 1, t[v * 2 + 1].flag = 1;
				t[v * 2].change = t[v].change, t[v * 2 + 1].change = t[v].change;
			}
			t[v].change = 0;
			t[v].flag = 0;
	     } else {
			t[v].left = 0;
			t[v].right = 0;
			t[v].sum = 0;
			t[v].num = 0;
			if(v < sz) {
				t[v * 2].flag = 1, t[v * 2 + 1].flag = 1;
				t[v * 2].change = t[v].change, t[v * 2 + 1].change = t[v].change;
			}
			t[v].change = 0;
			t[v].flag = 0;	    
	    }
	}
}

void upd(int v, int Tl, int Tr, int l, int r, int x) {
	push(v, Tl, Tr);
	if(Tl > r || Tr < l) {
		return;
	}
	if(l <= Tl && Tr <= r) {
		t[v].change = x;
		t[v].flag = 1;
		push(v, Tl, Tr);
		return;
	}
	int mid = (Tl+Tr) >> 1;
	upd(v * 2, Tl, mid, l, r, x);
	upd(v * 2 + 1, mid + 1, Tr, l, r, x);
	t[v].left = t[v * 2].left;
	t[v].right = t[v * 2 + 1].right;
	if(t[v * 2].right == 1 && t[v * 2 + 1].left == 1) {
		t[v].num = t[v * 2].num + t[v * 2 + 1].num - 1;
	} else {
		t[v].num = t[v * 2].num + t[v * 2 + 1].num;
	}
	t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum; 
}
int main() {
	freopen("painter.in", "r", stdin);
	freopen("painter.out", "w", stdout);
	scanf("%d\n", &m);
	sz = (1 << 20);
	++m;
	while(--m) {
		scanf("%c%d%d\n", &q, &l, &r);
		l += 500000;
		r += l;
		--r;
		int x;
		if(q == 'B') x = 1;
		else	x = 0;
		upd(1, 0, sz-1, l, r, x);
		printf("%d %d\n", t[1].num, t[1].sum);
	}
return 0;
}