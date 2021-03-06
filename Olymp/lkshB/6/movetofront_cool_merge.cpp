#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;
const  int N=100001;
struct node{
	int x,cnt,sum,upd;
	node *l,*r;
	node(){l=r=NULL;x=cnt=sum=upd=0;}
};
inline int cnt(node *it){
	return it?it->cnt:0;
}
inline int sum(node *it){
	return it?it->sum:0;
}
inline void upd(node *it){
	if(it){
	it->cnt=1+cnt(it->l)+cnt(it->r);
	it->sum=it->x+sum(it->l)+sum(it->r);
	}
}
inline void push(node *it){
	if(it && it->upd){
		it->x=it->upd;
		if(it->l)
			it->l->upd=it->x,it->l->sum=(it->l->cnt)*(it->x);
		if(it->r)
			it->r->upd=it->x,it->r->sum=(it->r->cnt)*(it->x);
		it->upd=0;
		upd(it);
	}
}
inline void me(node *&t,node *l,node *r){
	push(l);
	push(r);
	if(!l || !r)
		t=l?l:r;
	else if(l->cnt > r->cnt)
		me(l->r,l->r,r),t=l;
	else
		me(r->l,l,r->l),t=r;
	upd(t);
}
inline void sp(node *t,int x,node *&l,node *&r,int add=0){
	if(!t){
	 l=r=NULL;
	 return ;
	}
	push(t);
	int cur_add=add+cnt(t->l);
	if(x<=cur_add)
		sp(t->l,x,l,t->l,add),r=t;
     else
     	sp(t->r,x,t->r,r,add+cnt(t->l)+1),l=t;
     upd(t);
}
inline void output(node *it){
	if(!it)
	return ;
	output(it->l);
	printf("%d ",it->x);
	output(it->r);
}
node *root,*L,*R,*R1,*tmp,*mid;
int rndm[N],n,m,i,l,r,x;
char q;
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d %d\n",&n,&m);
	for(i=1;i<=n;++i){
		tmp=new node();
		tmp->x=i;
		me(root,root,tmp);
	}
	for(i=1;i<=m;++i){
		scanf("%d %d",&l,&r);
		sp(root,l-1,L,R);
		sp(R,r-l+1,mid,R1);
        me(L,mid,L);
        me(root,L,R1);
	}
	output(root);
return 0;}