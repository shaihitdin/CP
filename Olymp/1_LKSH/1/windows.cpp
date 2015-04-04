#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
  int y, sx, fx, flag;
};

node l[100010];
int sz, n, sz1;
int i, sx, sy, fx, fy;
int t[(1<<23)+1], t1[(1<<23)+1]; //t - int, t1 - pos
int flag[(1<<23)+1];

bool cmp (const node &lhs, const node &rhs) {
	if(lhs.y == rhs.y) {
		return (lhs.flag > rhs.flag);
	}
	return (lhs.y < rhs.y);
}

inline void push (int v) {
	if(flag[v] != 0) {
		t[v] += flag[v];
		if(v < sz1) {
			flag[v*2] += flag[v];
			flag[v*2+1] += flag[v];
			if(t[v * 2] > t[v * 2 + 1])
				t1[v] = t1[v * 2];
			else
				t1[v] = t1[v * 2 + 1];
		}
		else
			t1[v] = v-sz1;
		flag[v] = 0;
	}
}

inline void upd (int v, int Tl, int Tr, int l, int r, int upd_to) {
	if(Tl > r || Tr < l)	return;
	if(l <= Tl && Tr <= r) {
		flag[v] += upd_to; push (v);
		return;
	}
	int mid = (Tl + Tr) / 2;
	push (v);
	upd (v * 2, Tl, mid, l, r, upd_to);
	upd (v * 2 + 1, mid + 1, Tr, l, r, upd_to);
	if(t[v * 2] > t[v * 2 + 1]) {
		t[v] = t[v * 2];
		t1[v] = t1[v * 2];
	} else {
		t[v] = t[v * 2 + 1];
		t1[v] = t1[v * 2 + 1];	
	}
	push(v);
}

int main() {
	freopen ("windows.in", "r", stdin);
	freopen ("windows.out", "w", stdout);
	scanf ("%d", &n);
	sz1 = (1<<21);
	for (i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
		++sz;
		l[sz].y = sy; l[sz].sx = sx+1000000; l[sz].fx = fx+1000000; l[sz].flag = 1;
		++sz;
		l[sz].y = fy; l[sz].sx = sx+1000000; l[sz].fx = fx+1000000; l[sz].flag = -1;
	}
	sort (l + 1, l + sz + 1, cmp);
	int ans1 = 0, ans2 = 0, ans3 = 0;
	for(i = sz1; i < sz1 + sz1; ++i)
		t1[i] = i - sz1;
	for(i = sz1 - 1; i >= 1; --i)
		t1[i] = t1[i * 2];
	for (i = 1; i <= sz; ++i) {
    	upd(1, 0, sz1 - 1, l[i].sx, l[i].fx, l[i].flag);
    	if(t[1] > ans1) {
    		ans1 = t[1];
    		ans2 = l[i].y;
    		ans3 = t1[1];
    	}
	}
	printf("%d\n%d %d", ans1, ans3-1000000, ans2);
	return 0;
}
