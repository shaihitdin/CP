#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int N = 300001, inf = 100000001;
int last[N], pos[N], sz, n, i, a[N];
vector<int> ans;
struct tree {
	int mn, upd, p, tmpp;
} t[N * 9];

inline void push (int v) { 
	if(t[v].upd != inf){
		if(v >= sz) {
			if (t[v].mn > t[v].upd) {
				t[v].p = t[v].tmpp;
			}
			t[v].mn = min (t[v].mn, t[v].upd);
		} else {
			if(t[v].upd < t[v * 2].upd) {
				t[v * 2].tmpp = t[v].tmpp;
			}
			t[v * 2].upd = min (t[v * 2].upd, t[v].upd);
			if(t[v * 2 + 1].upd > t[v].upd) {
				t[v * 2 + 1].tmpp = t[v].tmpp;
			}
			t[v * 2 + 1].upd = min (t[v * 2 + 1].upd, t[v].upd);
		}
		t[v].upd = inf;
		t[v].tmpp = 0;
	}
	return;
}
inline void upd (int v, int Tl, int Tr, int l, int r){
	if (Tl > r || Tr < l) {
		return;
	}
	push(v);
	if (Tl >= l && Tr <= r) {
		return;
	}
	int mid = (Tr + Tl) / 2;
	upd (v * 2, Tl, mid, l, r);
	upd (v * 2 + 1, mid + 1, Tr, l, r);
	return;
}
inline void get (int v, int Tl, int Tr, int l, int r, int delta, int fr){
	if (Tl > r || Tr < l) {
		return;
	}
	if (Tl >= l && Tr <= r) {		
	   	push(v);
		t[v].upd = delta;
		t[v].tmpp = fr;
		push(v);
		return;
	}
	int mid = (Tr + Tl) / 2;
	get (v * 2, Tl, mid, l, r, delta, fr);
	get (v * 2 + 1, mid + 1, Tr, l, r, delta, fr);
}
int main(){
	freopen ("expedition.in", "r", stdin);
	freopen ("expedition.out", "w", stdout);
	scanf ("%d", &n);
	sz = (1<<19);
	for (i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
	}
	for (i = n; i >= 1; --i) {
		last[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	for (i = 1; i < sz + sz; ++i)
		t[i].mn = t[i].upd = inf;
	t[sz].mn = 0;	
	for (i = 1; i < n; ++i) {
		upd (1, 0, sz - 1, (i - 1), (i - 1));
//		cerr << i << " " << t[i - 1 + sz].mn << "\n";
		if (t[i - 1 + sz].mn == inf)	continue;
		if (last[i] == 0)	continue;
		get (1, 0, sz - 1, (i), last[i] - 1, t[i - 1 + sz].mn + 1, i - 1 + sz);
				
	}
	if(t[n - 1 + sz].mn == inf){
		printf("0");
		return 0;
	}
	int tmpsss = n - 1 + sz;
	while(tmpsss!=sz) {
		tmpsss = t[tmpsss].p;
		ans.push_back(tmpsss + 1 - sz);
	}
	printf("%d\n", ans.size());
	for(i = ans.size() - 1; i >= 0; --i) {
		printf("%d ", ans[i]);
	}
	return 0;
}