#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;
const  int N=100001;
struct node{
	long long x,y,cnt,sum;
	node *l,*r;
	node(){l=r=NULL;x=y=cnt=sum=0;}
};
node *root1,*L,*R,*R1,*tmp,*mid,*mid_2,*tmp2,*root2,*L_2,*R_2,*R1_2;	//root1 odd, root2 even
long long rndm[N],n,m,i,l,r,x,total_counter=1,q;
inline long long cnt(node *it){
	return it?it->cnt:0;
}
inline long long sum(node *it){
	return it?it->sum:0;
}
inline void upd(node *it){
	if(it){
	it->cnt=1+cnt(it->l)+cnt(it->r);
	it->sum=it->x+sum(it->l)+sum(it->r);
	}
}
void me(node *&t,node *l,node *r){
	upd(l);
	upd(r);
	upd(t);
	if(!l || !r)
		t=l?l:r;
	else if(l->y > r->y)
		me(l->r,l->r,r),t=l;
	else
		me(r->l,l,r->l),t=r;
	upd(t);
	upd(l);
	upd(r);
}
void sp(node *t,long long x,node *&l,node *&r,long long add=0){
	upd(l);upd(r);upd(t);
	if(!t){
	 l=r=NULL;
	 return ;
	}
	long long cur_add=add+cnt(t->l);
	if(x<=cur_add)
		sp(t->l,x,l,t->l,add),r=t;
     else
     	sp(t->r,x,t->r,r,add+cnt(t->l)+1),l=t;
     upd(l);
     upd(r);
     upd(t);
}
void output(node *it){
	if(!it)
		return;
    	output(it->l);
    	fprintf(stderr,"%lld ",it->x);
    	output(it->r);
}
int main(){
	freopen("swapper.in","r",stdin);
	freopen("swapper.out","w",stdout);
	/*
				cerr<<l<<"&"<<r<<"\n";
				output(mid);
				fprintf(stderr,"\n");
				output(mid_2);
				fprintf(stderr,"\n\n");
	*/
	O:;
	srand(time(0));
	scanf("%lld%lld",&n,&m);
	if(n==0 && m==0){
		return 0;
	}
	for(i=1;i<=n;++i)
	 	rndm[i]=i;
	random_shuffle(rndm+1,rndm+n+1);
	random_shuffle(rndm+1,rndm+n+1);
	root1 = root2 = new node();
	root1 = root2 = NULL;
	for(i=1;i<=n;++i){
		scanf("%lld",&x);
		tmp = new node();
		tmp->x=x;
		tmp->y=rndm[i];
		if(i&1){
			me(root1,root1,tmp);
		}
		else
			me(root2,root2,tmp);
	}
	printf("Swapper %lld:\n",total_counter);
	for(i=1;i<=m;++i){
		scanf("%lld%lld%lld",&q,&l,&r);
		if(q==1){
			if(l&1){
				sp(root1,l/2,L,R);
				sp(R,(r-l)/2+1,mid,R1);
				sp(root2,l/2,L_2,R_2);
				sp(R_2,(r-l)/2+1,mid_2,R1_2);
				me(R,mid_2,R1);
				me(root1,L,R);
				me(R_2,mid,R1_2);
				me(root2,L_2,R_2);
			}
			else{
				sp(root1,l/2,L,R);
				sp(R,(r-l)/2+1,mid,R1);
				sp(root2,l/2-1,L_2,R_2);
				sp(R_2,(r-l)/2+1,mid_2,R1_2);
				me(R,mid_2,R1);
				me(root1,L,R);
				me(R_2,mid,R1_2);
				me(root2,L_2,R_2);			
			}
		}
		if(q==2){
			if(l&1){
				if(r&1){
				sp(root1,l/2,L,R);
				sp(R,(r-l)/2+1,mid,R1);
				sp(root2,l/2,L_2,R_2);
				sp(R_2,(r-l)/2,mid_2,R1_2);
				printf("%lld\n",(sum(mid)+sum(mid_2)));
				me(R,mid,R1);
				me(root1,L,R);
				me(R_2,mid_2,R1_2);
				me(root2,L_2,R_2);
				}
				else{
				sp(root1,l/2,L,R);
				sp(R,(r-l)/2+1,mid,R1);
				sp(root2,l/2,L_2,R_2);
				sp(R_2,(r-l)/2+1,mid_2,R1_2);
				printf("%lld\n",(sum(mid)+sum(mid_2)));
				me(R,mid,R1);
				me(root1,L,R);
				me(R_2,mid_2,R1_2);
				me(root2,L_2,R_2);				
				}
			}
			else{
				if(r&1){
				sp(root1,l/2,L,R);
				sp(R,(r-l)/2+1,mid,R1);
				sp(root2,l/2-1,L_2,R_2);
				sp(R_2,(r-l)/2+1,mid_2,R1_2);
				printf("%lld\n",(sum(mid)+sum(mid_2)));
				me(R,mid,R1);
				me(root1,L,R);
				me(R_2,mid_2,R1_2);
				me(root2,L_2,R_2);			
				}
				else{
				sp(root1,l/2,L,R);
				sp(R,(r-l)/2,mid,R1);
				sp(root2,l/2-1,L_2,R_2);
				sp(R_2,(r-l)/2+1,mid_2,R1_2);
				printf("%lld\n",(sum(mid)+sum(mid_2)));
				me(R,mid,R1);
				me(root1,L,R);
				me(R_2,mid_2,R1_2);
				me(root2,L_2,R_2);							
				}
			}
		}
	}
	++total_counter;
	printf("\n");
	goto O;
return 0;}