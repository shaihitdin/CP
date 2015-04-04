#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;
const  int N=100001;
struct node{
	long long x,y,cnt,sum,upd;
	bool upd1;
	node *l,*r;
	node(){l=r=NULL;x=y=cnt=sum=upd=0;upd1=0;}
};
node *root,*L,*R,*R1,*tmp,*mid;
long long rndm[N],n,m,i,l,r,x;
char q;
long long cnt(node *it){
	return it?it->cnt:0;
}
long long sum(node *it){
	return it?it->sum:0;
}
void upd(node *it){
	if(it){
	it->cnt=1+cnt(it->l)+cnt(it->r);
	it->sum=it->x+sum(it->l)+sum(it->r);
	}
}
void push(node *it){
	if(it && it->upd1){
		it->x=it->upd;
		if(it->l)
			it->l->upd=it->x,it->l->sum=(it->l->cnt)*(it->x),it->l->upd1=1;
		if(it->r)
			it->r->upd=it->x,it->r->sum=(it->r->cnt)*(it->x),it->r->upd1=1;
		it->upd=0;
		it->upd1=0;
		upd(it);
	}
}
void me(node *&t,node *l,node *r){
	push(l);
	push(r);
	if(!l || !r)
		t=l?l:r;
	else if(l->y > r->y)
		me(l->r,l->r,r),t=l;
	else
		me(r->l,l,r->l),t=r;
	push(t);
	upd(t);
}
void sp(node *t,long long x,node *&l,node *&r,long long add=0){
	if(!t){
	 l=r=NULL;
	 return ;
	}
	push(t);
	long long cur_add=add+cnt(t->l);
	if(x<=cur_add)
		sp(t->l,x,l,t->l,add),r=t;
     else
     	sp(t->r,x,t->r,r,add+cnt(t->l)+1),l=t;
     push(l);
     push(r);
     upd(l);
     upd(r);
     upd(t);
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	srand(time(0));
	scanf("%I64d %I64d\n",&n,&m);
	for(i=1;i<=n;++i)
	 	rndm[i]=i;
	random_shuffle(rndm+1,rndm+n+1);
	random_shuffle(rndm+1,rndm+n+1);
	for(i=1;i<=n;++i){
		tmp=new node();
		tmp->y=rndm[i];
		me(root,root,tmp);
	}
	for(i=1;i<=m;++i){
		scanf("%c %I64d %I64d",&q,&l,&r);
//		cerr<<q<<" "<<l<<" "<<r<<"\n";
		sp(root,l-1,L,R);
		sp(R,r-l+1,mid,R1);
		if(q=='A'){
		 	scanf("%I64d",&x);
		 	mid->upd=x;
		 	mid->upd1=1;
		}
		else{
			printf("%I64d\n",sum(mid));
		}
		me(R,mid,R1);
		me(root,L,R);
		scanf("\n");
	}
return 0;}