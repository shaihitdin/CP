#include<iostream>
#include<algorithm>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct node{
	long long x,y;
	node *l,*r;
	node(){l=r=NULL;}
};
const int N=300001;
typedef struct node * tnode;
long long ans;
long long y;
int rndm[N];
long long x,i,n;
char q,prevq;
tnode root,tmp;
void me(tnode &t,tnode l,tnode r){
	if(!l || !r)
	 	t=l?l:r;
	else if(l->y>r->y)
	 	me(l->r,l->r,r),t=l;
	else
		me(r->l,l,r->l),t=r;
}
void sp(tnode t,int x,tnode &l,tnode &r){
	if(!t)
		l=r=NULL;
	else if(x<=t->x)
		sp(t->l,x,l,t->l),r=t;
	else
		sp(t->r,x,t->r,r),l=t;
}
void in(tnode &t,tnode it){
	if(!t)
		t=it;
	else if(it->y>t->y)
		sp(t,it->x,it->l,it->r),t=it;
	else
		in((t->x>=it->x)? t->l :t->r ,it);
}

void get_ans(tnode t,int x){
	if(!t)
	 return;
	if(t->x>=x){
	  	ans=min(ans,t->x);
	  	get_ans(t->l,x);
	}
	else
	  	get_ans(t->r,x);
}
void output(tnode t){
	if(!t)
	return ;
	output(t->l);
	cerr<<t->x<<"\n";
	output(t->r);
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	srand(time(0));
	scanf("%I64d\n",&n);
	for(i=1;i<=n;++i)
	  rndm[i]=i;
     random_shuffle(rndm+1,rndm+n+1);
     random_shuffle(rndm+1,rndm+n+1);
	for(i=1;i<=n;++i){
	   scanf("%c ",&q);
	   if(q=='?'){
	   	scanf("%I64d\n",&x);
	   	ans=1000000000*(N*1ll);
	   	get_ans(root,x);
	     y=ans;
	     if(y!=1000000000*(N*1ll))
	     printf("%I64d\n",y);
	     else
	     y=-1,printf("-1\n");
	     
	   }
	   else{
	     scanf("%I64d\n",&x);
	     tmp=new node();
	     tmp->y=rndm[i];
	   	if(prevq=='?'){
	   		tmp->x=(x+y)%1000000000;
	   		in(root,tmp);
	   	}
	   	else{
	   		tmp->x=x;
	   		in(root,tmp);
	   	}
	   }
	   prevq=q;
	}
return 0;}