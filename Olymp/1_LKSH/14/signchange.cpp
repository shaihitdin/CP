#include<iostream>
#include<stdio.h>	
#include<algorithm>
using namespace std;
const int N = 100001, inf = 1000000009;
int t1[N],t2[N],t3[N],t4[N]; //(in tree) t1 - odd +, t2 - even -, t3 - odd -, t4 - even +
int n;

inline int get1(int r) {
	int res = 0;
	for(int i = r; i >= 1; i = (i & (i + 1)) - 1) res += t1[i];
	return res;
}

inline int get2(int r) {
	int res = 0;
	for(int i = r; i >= 1; i = (i & (i + 1)) - 1) res += t2[i];
	return res;
}

inline int get3(int r) {
	int res = 0;
	for(int i = r; i >= 1; i = (i & (i + 1)) - 1) res += t3[i];
	return res;
}

inline int get4(int r) {
	int res = 0;
	for(int i = r; i >= 1; i = (i & (i + 1)) - 1) res += t4[i];
	return res;
}

/// upd inc
inline void upd(int x, int inc) {
	if(x & 1) {
		for(int i=x;i<=n;i=(i|(i+1))) t1[i]+=inc;
		for(int i=x;i<=n;i=(i|(i+1))) t3[i]-=inc;
	}
	else {
		for(int i=x;i<=n;i=(i|(i+1))) t2[i]-=inc;
		for(int i=x;i<=n;i=(i|(i+1))) t4[i]+=inc;
	}
}

int i,a[N],l,r,m,q;
int main() {
	freopen("signchange.in", "r", stdin);
	freopen("signchange.out", "w", stdout);
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) {
		scanf("%d",&a[i]);
		/*
		if(i&1) {
			t1[i] = tmp;
			t3[i] = -tmp;
		}
		else {
			t2[i] = -tmp;
			t4[i] = tmp;
		}
		*/
	}
	scanf("%d",&m);
	for(i = 1; i <= n; ++i) {
		upd(i,a[i]);
		/*
		if((i | (i+1)) <= n) {
			t1[(i | (i+1))] += t1[i];
			t2[(i | (i+1))] += t2[i];
			t3[(i | (i+1))] += t3[i];
			t4[(i | (i+1))] += t4[i];
		}
		*/
	}
	for(i = 1; i <= m ; ++i) {
		scanf("%d%d%d",&q,&l,&r);
		if(q==0){
			upd(l,r-a[l]);
			a[l]=r;
		}
		else{
			if(l&1){
				printf("%d\n",((get1(r)-get1(l-1))+(get2(r)-get2(l-1))));
			}
			else{
				printf("%d\n",((get3(r)-get3(l-1))+(get4(r)-get4(l-1))));			
			}
		}
	}
return 0;
}