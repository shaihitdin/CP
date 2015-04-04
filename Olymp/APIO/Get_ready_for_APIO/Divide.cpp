#include<stdio.h>
#include<iostream>
#include<time.h>
#include<algorithm>
using namespace std;
typedef struct node* tnode;
struct node{
	int lastpos,energy,gold,y,gold1,lastpos1,energy1;
	bool upd;
	tnode l,r;
	node(){l=r=NULL;upd=0;lastpos=0;energy=0;gold=0;gold1=0;lastpos1=0;energy1=0;}
};
void push(tnode it){
	if(it && it->upd){
	 it->energy-=(it->lastpos1-it->lastpos);
	 it->lastpos=it->lastpos1;
	 it->gold+=it->gold1;
	 it->energy+=it->energy1;
	 
	 if(it->l){
	 /*
	  if(it->l->upd)
	   it->l->energy-=(it->l->lastpos1-it->l->lastpos);
	   */
	  it->l->upd=1,it->l->gold1+=it->gold1,it->l->lastpos1=it->lastpos1,it->l->energy1+=it->energy1;}
	 if(it->r){ 
	 /*
	  if(it->r->upd)
	   it->r->energy-=(it->r->lastpos1-it->r->lastpos);
	   */
	  it->r->upd=1,it->r->gold1+=it->gold1,it->r->lastpos1=it->lastpos1,it->r->energy1+=it->energy1;}
	 
	 it->upd=0;
	 it->lastpos1=0;
	 it->gold1=0;
	 it->energy1=0;
	}
}
void sp(tnode t,tnode &l,tnode &r,int key){
    	push (t);
	if(!t){
	 l=r=NULL;
	 return ;
	}
//	cerr<<"split:"<<key<<" & "<<(t->lastpos+t->energy)<<" ";
	if(key <= (t->lastpos+t->energy))
	  sp(t->l,l,t->l,key), r=t;
	else
	  sp(t->r,t->r,r,key), l=t;
}
void me(tnode &t,tnode l,tnode r){
	push (l);
	push (r);
	if(!l || !r)
	t=l? l : r;
	else if(l->y > r->y)
	  me(l->r,l->r,r),t=l;
     else
	  me(r->l,l,r->l),t=r;
}
void insert(tnode &t,tnode it){
 	push(t);
	if(!t)
	 t=it;
	 else if(it->y > t->y)
	 	sp(t,it->l,it->r,(it->lastpos+it->energy)), t=it;
	 else
	 	insert((it->lastpos+it->energy) < (t->lastpos+t->energy) ? t->l : t->r ,it);
}
tnode root,tmp,L,R;
int i,n,ans,x,g,e,rnd[100001];
void check(tnode t){
	if(!t)
	return ;
	push(t);
	ans=max(ans,t->gold);
	check(t->l);
//	cerr<<"...gold:"<<t->gold<<"...energy"<<t->energy<<"...lastpos"<<t->lastpos<<"\n";
	check(t->r);
}
int main(){
      freopen("divide.in","r",stdin);
      freopen("divide.out","w",stdout);
      srand(time(0));
      scanf("%d",&n);
      for(i=1;i<=n;++i)
       rnd[i]=i;
       random_shuffle(rnd+1,rnd+n+1);
      for(i=1;i<=n;++i){
         scanf("%d %d %d",&x,&g,&e);
//         cerr<<i<<":";
          tmp=new node();
		tmp->lastpos=x;
		tmp->energy=e;
		tmp->gold=g;
		tmp->y=rnd[i];
		sp(root,L,R,x-e);
//		cerr<<"\n";
		push(R);
		if(R){
		R->upd=1;
		R->gold1+=g;
		R->lastpos1=x;
		R->energy1+=e;
//		cerr<<"DOES\n";
		}
		me(root,L,R);
//		cerr<<"INSERT";
		insert(root,tmp);
		check(root);
		
      }
          //check(root);
		printf("%d ",ans);

return 0;}