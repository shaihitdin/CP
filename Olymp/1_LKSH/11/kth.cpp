#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct node{
	int cnt, y;
	long long x;
	node *l, *r;
	node(){l = r = 0,x = y = 0;cnt = 0;}
};

node *root, *L, *R, *mid, *tmp;
node *t[(1 << 21)+1];
int n,sz,i,rndm[450001],g;
long long G,x1,lx,mx,y1,ly,my,k1,lk,mk;
long long x,l,m;

inline int cnt(node *it) {
	return it? it->cnt : 0;
}

inline void upd(node *it) {
	if(it) 
		it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

inline void sp(node *t, int x, node *&l, node *&r) {
    upd(l); upd(r); upd(t);
	if(!t){
		l = r = 0; return;
	}
	if(t->x < x) sp(t->r, x, t->r, r), l = t;
	else sp(t->l, x, l, t->l), r = t;
	upd(l); upd(r); upd(t);
}

inline void me(node *&t, node *l, node*r) {
	upd(l); upd(r); upd(t);
	if(!l || !r) {
		t = l ? l : r; return;
	}
	if(l->y > r->y) me(l->r, l->r, r), t = l;
	else me(r->l, l, r->l), t = r;
	upd(t); upd(l); upd(r);
}

inline int get(node *it, int x) {
	if(cnt(it->l)+1 == x) return it->x;
	if(cnt(it->l) >= x) return get(it->l, x);
	else return get(it->r, x - 1 - cnt(it->l));
}

inline node* get2(int v,int Tl,int Tr,int l,int r) {
	if(Tl>r || Tr<l) {
		return 0;
	}
	if(Tl>=l && Tr<=r) {
		return t[v];
	}
	int mid1 = (Tl + Tr) / 2;
	node * L = new node();
	L = get2(v*2,Tl,mid1,l,r);
	node * R = new node();
	R = get2(v*2+1,mid1+1,Tr,l,r);
	node * tmp = new node();
	me(tmp,L,R);
	return tmp;
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	srand(time(0));
	scanf("%d",&n);
	sz = (1 << 19);
	for(i = 1; i < (sz<<1); ++i)
		t[i] = new node();
	for(i = 1; i <= n; ++i)
		rndm[i] = i;
	random_shuffle(rndm + 1, rndm + n + 1);
	random_shuffle(rndm + 1, rndm + n + 1);
	scanf("%lld%lld%lld", &x, &l, &m);
	t[sz]->x = x;
	t[sz]->y = rndm[1];
	for(i = 2; i <= n; ++i) {
		t[sz+i-1] = new node();
		t[sz+i-1]->x = (x*l+m)%1000000009;
		t[sz+i-1]->y = rndm[i];
		x = (x*l+m)%1000000009;
	}
	for(i = sz - 1; i >= 1; --i)
		me(t[i],t[i*2],t[i*2+1]);
	cerr<<cnt(t[1])<<" ";
	int b;
	scanf("%d",&b);
	++b;
	long long ans = 0;
	while(--b) {
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld", &G, &x1, &lx, &mx, &y1, &ly, &my, &k1, &lk, &mk);
		int l = min(x1, y1), r = max(x1, y1);
		tmp = get2(1,0,sz-1,l-1,r-1);
		cerr<<cnt(tmp)<<" ";
		ans += get(tmp,k1);
		cerr<<"OK";
		for(g = 2; g <= G; ++g) {
			x1 = ((l-1)*lx+mx)%n+1;
			y1 = ((r-1)*ly+my)%n+1;
			l = min(x1, y1);
			r = max(x1, y1);
			k1 = (((k1-1)*lk+mk)%(r-l+1))+1;
		    ans += get(get2(1,0,sz-1,l-1,r-1),k1);
		}
		cerr<<"|"<<ans<<"|";
	}
	printf("%lld", ans);
return 0;
}