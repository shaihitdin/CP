///LOL BUILD O(N)

#include<iostream>
#include<stdio.h>
using namespace std;
const int N=50001;
int ans1[N],ans2[N],ans3[N];
int a,b,i;
int n;
struct node{
	int x,y,z;
	node *l,*r;
	node(){l=r=NULL;}
};
typedef struct node * tnode;
tnode tmp,root;                                                                
void sp(tnode t,int x,tnode &l,tnode &r){
	if(!t)
	 	l=r=NULL;
	else if(x<t->x){
		sp(t->l,x,l,t->l),r=t;
	}
	else{
	     sp(t->r,x,t->r,r),l=t;
	}
}
void me(tnode &t,tnode l,tnode r){
	if(!l || !r)
	 	t=l? l : r;
	else if(l->y>r->y)
		me(l->r,l->r,r),t=l; 
	else
	     me(r->l,l,r->l),t=r;
}
void insert(tnode &t,tnode it){
	if(!t)
	 	t=it;
	else if(t->y<it->y)
	  	sp(t,it->x,it->l,it->r),t=it;
	else
	     insert((it->x>t->x)? t->r : t->l,it);
}
void output(tnode t,int p){
    if(!t)
    return ;
    if(t->l)
    ans2[t->z]=t->l->z,output(t->l,t->z);
    else
    ans2[t->z]=0;
    if(t->r)
    ans3[t->z]=t->r->z,output(t->r,t->z);
    else
    ans3[t->z]=0;

    ans1[t->z]=p;
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
	 scanf("%d %d",&a,&b);
	  tmp=new node();
	  tmp->x=a;
	  tmp->y=b;
	  tmp->z=i;
	  insert(root,tmp);
	}
	printf("YES\n");
	output(root,0);
	for(i=1;i<=n;++i)
	printf("%d %d %d\n",ans1[i],ans2[i],ans3[i]);
return 0;}