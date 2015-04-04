#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<time.h>
using namespace std;
#define F first
#define S second
#define mkp make_pair
const int N=100001;
struct node{
	int x,x1,y,sum,upd;
	node *l,*r;
	node(){
	l=r=NULL,x=x1=y=sum=upd=0;
	}
};
vector<pair<int,int> > query[N];
vector<int> g[N];
int cnt,ans[N],rnd[N],root,n,m,i,x,v,k;
inline void upd(node *it){
	if(it){
		if(it->upd){
			it->sum+=it->upd;
			if(it->l){
				it->l->upd+=it->upd;
			}
			if(it->r){
				it->r->upd+=it->upd;			
			}
			it->upd=0;
		}
	}
}
inline void Merge(node *&t,node *l,node *r){
	upd(l),upd(r);
	if(!l || !r){
		t=l?l:r;
		return;
	}
	if(l->y > r->y)	Merge(l->r,l->r,r), t=l;
	else	Merge(r->l,l,r->l),	t=r;
	upd(t);
}
inline void Split(node *t,node *&l,node *&r,int Split_key){
	upd(t);
	if(!t){
		l=r=NULL;
		return;
	}
	if(t->x >= Split_key)	Split(t->l,l,t->l,Split_key), r=t;
	else Split(t->r,t->r,r,Split_key), l=t;
	upd(l),upd(r);
}
node *t,*L,*R,*R1,*mid, *tmp;
inline void dfs(int v,int depth){
		Split(t,L,R,depth+1);
		if(L)	L->upd+=1;
		Merge(t,L,R);
		for(int i=0;i<query[v].size();++i){
			Split(t,L,R,depth+query[v][i].F);
			Split(R,mid,R1,depth+query[v][i].F+1);
			tmp=new node();
			tmp->x=depth+query[v][i].F;
			tmp->y=rnd[++cnt];
			Merge(mid,mid,tmp);
			Merge(R,mid,R1);
			Merge(t,L,R);
		}
		for(int i=0;i<g[v].size();++i){
			dfs(g[v][i],depth+1);
		}
		for(int i=0;i<query[v].size();++i){
			Split(t,L,R,depth+query[v][i].F);
			Split(R,mid,R1,depth+query[v][i].F+1);
			ans[query[v][i].S]=mid->sum;
			Merge(mid,mid->l,mid->r);
			Merge(R,mid,R1);
			Merge(t,L,R);
		}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	srand(1999999);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		if(x==-1)	root=i;
		else	g[x].push_back(i);
	}
	scanf("%d",&m);
	for(i=1;i<=m;++i){
		rnd[i]=i;
	}
	random_shuffle(rnd+1,rnd+m+1);
	for(i=1;i<=m;++i){
		scanf("%d%d",&v,&k);
		query[v].push_back(mkp(k,i));
	}
	dfs(root,1);
	for(i=1;i<=m;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}