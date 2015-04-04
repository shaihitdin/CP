#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
typedef struct node * tnode;
const long long N=1000000007,M=200001;
struct node{
	long long x,y,num,sum;
	tnode l,r;
	node(){l=r=NULL;}
};
long long sum(tnode it){
	return it?it->sum:0;
}
void upd(tnode it){
	if(it){
	  it->sum=it->num+sum(it->l)+sum(it->r);
	}
}
void sp(tnode t,long long x,tnode &l,tnode &r){
	upd(t);
	upd(l);
	upd(r);
	if(!t){
		r=l=NULL;
		return;
	}
	
	if(t->x >= x) sp(t->l,x,l,t->l),r=t;
	else		   sp(t->r,x,t->r,r),l=t;
	upd(l);
	upd(r);
	upd(t);
}
void me(tnode &t,tnode l,tnode r){
     upd(l);
     upd(r);
     upd(t);
     if(!l || !r){
          t=l?l : r;
          return ;
     }
     if(l->y > r->y) me(l->r,l->r,r),t=l;
     else			 me(r->l,l,r->l),t=r;
     upd(l);
     upd(r);
     upd(t);
}
void in(tnode &t,tnode it){
	upd(t);
     if(!t){
     	t=it;
     	upd(t);
     	return ;
     }
     upd(t);
     if(t->y>it->y) sp(t,it->x,it->l,it->r),t=it;
     else			in((t->x>=it->x)?t->l:t->r,it);
     upd(t);
}
void del(tnode &t,int x){
	if(!t)
	return ;
	if(t->x==x)
		me(t,t->l,t->r);
	else
		del(x < t->x ? t->l : t->r,x);
}
tnode root,tmp,l,r,mid,r1;
char w;
long long p,q,a,b,ans,n,m,i,rndm[M];
int main(){
       freopen("in","r",stdin);
       freopen("out","w",stdout);
       srand(time(0));
       scanf("%I64d %I64d\n",&n,&m);
       p=91,q=47;
       for(i=1;i<=m;++i)
         rndm[i]=i;
	  random_shuffle(rndm+1,rndm+1+m);
       for(i=1;i<=m;++i){
//       fprintf(stderr,"%d:\n",i);
       	scanf("%c %I64d %I64d\n",&w,&a,&b);
       	if(w=='!'){
       		tmp=new node();
       		tmp->x=(a+p)%n;
       		tmp->num=(b+q)%N;
       		tmp->y=rndm[i];
       		del(root,(a+p)%n);
       		in(root,tmp);
       	}
       	else{
//       		fprintf(stderr,"root is %d\n",root);
       	     sp(root,min((a+p)%n,(b+q)%n),l,r);
//			fprintf(stderr,"l is %d & r is %d\n",l,r);
       	     sp(r,max((a+p)%n,(b+q)%n)+1,mid,r1);
       	     ans=sum(mid);
//       	     fprintf(stderr,"mid is %d\n",(mid?1:0));
//       	     fprintf(stderr,"r1 is %d\n",(r1?1:0));
       	     printf("%I64d\n",ans);
       	     p=(p*31+ans)%N;
       	     q=(q*29+ans)%N;
       	     me(r,mid,r1);
       	     me(root,l,r);
       	}
//       	fprintf(stderr,"\n");
       }
return 0;}