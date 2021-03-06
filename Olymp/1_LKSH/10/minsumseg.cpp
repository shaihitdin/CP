#include<iostream>
#include<stdio.h>	
#include<algorithm>
using namespace std;
const int N = 300001, inf = 1000000009;
struct tree{
	int Min,Max;
	bool flag;
	int change;
};
tree t[N*8];
int sz, m, i, x, y;
inline void push (int v) {
	if(t[v].flag) {
		t[v].Min = t[v].change;
		t[v].Max = t[v].change;
		if(v < sz) {
			t[v * 2].flag = 1, t[v * 2 + 1].flag = 1;
			t[v * 2].change = t[v].change, t[v * 2 + 1].change = t[v].change;
		}
		t[v].change = 0;
		t[v].flag = 0;
	}
}
inline int getMin(int v,int Tl,int Tr,int l,int r) {
	if(Tl > r || Tr < l) {
		return inf;
	}
	push(v);
	if(Tl >= l && Tr <= r) {
		return t[v].Min;
	}
	int res = inf;
	int mid = (Tl+Tr) >> 1;
	res = min(res, getMin(v*2, Tl, mid, l, r));
	res = min(res, getMin(v*2+1, mid+1, Tr, l, r));
	return res;
}

inline int getMax(int v,int Tl,int Tr,int l,int r) {
	if(Tl > r || Tr < l) {
		return -inf;
	}
	push(v);
	if(Tl >= l && Tr <= r) {
		return t[v].Max;
	}
	int res = -inf;
	int mid = (Tl+Tr) >> 1;
	res = max(res, getMax(v*2, Tl, mid, l, r));
	res = max(res, getMax(v*2+1, mid+1, Tr, l, r));
	return res;
}
inline void upd(int v,int Tl,int Tr, int l, int r, int x) {
	if(Tl > r || Tr < l) {
		return ;
	}
	push(v);
	if(Tl >= l && Tr <= r) {
		t[v].change = x;
		t[v].flag = 1;
		push(v);
		return ;
	}
	int mid = (Tl+Tr) >> 1;
	upd(v*2, Tl, mid, l, r, x);
	upd(v*2+1, mid+1, Tr, l, r, x);
	t[v].Min = min(t[v*2].Min, t[v*2+1].Min);
	t[v].Max = max(t[v*2].Max, t[v*2+1].Max);
}
int main() {
	freopen("minsumseg.in", "r", stdin);
	freopen("minsumseg.out", "w", stdout);
	ios_base :: sync_with_stdio(0);
	cin >> n >> m;
	sz = (1 << 19);
	for (i = 1; i < N; ++i) {
		t[i+sz-1].Min = 
		((i * 1ll * i * 1ll) * 1ll % 12345 + (i * 1ll * i * 1ll * i * 1ll) * 1ll % 23456);
		t[i+sz-1].Max = t[i+sz-1].Min;
	}
	for (i = sz+N; i < (1 << 18); ++i) 
		t[i].Min = inf, t[i].Max = -inf;
	for (i = sz-1; i > 0; --i) 
		t[i].Min = min(t[i*2].Min,t[i*2+1].Min), t[i].Max = max(t[i*2].Max,t[i*2+1].Max);
	
	for(i = 1; i <= m; ++i){
		scanf("%d%d",&x,&y);
		if(x>0) {
			printf("%d\n",getMax(1, 0, sz-1, x-1, y-1) - getMin(1, 0, sz-1, x-1, y-1));
		} else {
			upd(1, 0, sz-1, abs(x)-1, abs(x)-1, y);
		}
	}
return 0;
}