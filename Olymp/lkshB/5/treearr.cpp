//Build O(N)
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int N=50001;
int n;

pair<int,pair<int,int> > a[N];
int x,y,z,i;
int ans1[N],ans2[N],ans3[N];
struct node{
	int x,y,z;
	node l,r,p;
	node(){l=r=p=NULL;}
};
typedef struct node * tnode;
tnode tmp,root,maxx;
void sp(tnode t,int x,tnode &l,tnode &r){
	if(!t)
		l=r=NULL;
	else if(t->x>x)
		sp(t->l,x,l,t->l),r=t;
	else
		sp(t->r,x,t->r,r),l=t;
}
void me(tnode &t,tnode l,tnode r){
	if(!l || !r)
		t=l? l : r;
	else if(l->y>r->y)
		me(l->r,l->r,r),t=l;
	else
		me(r->l,l,r->l),t=r;
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
void build(tnode &t,tnode it){
	if(!t){
	 t=it;
	 return ;
	}
	if(t->y>it->y){
	  it->l=t->r;
	  t->r=it;
	  it->p=t;
	  if(it->l)
	  it->l->p=it;
	  return ;
	}
	if(t->p){
	  build(t->p,it);
	}
	if(!t->p){
	   tnode temp;
	   temp=t;
	   t=it;
	   t->r=NULL;
	   t->l=temp;
	   temp->p=t;
	}
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d %d",&a[i].first,&a[i].second.first);
		a[i].second.second=i;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=2;++i){
		cerr<<i<<"\n";
		x=a[i].first;
		y=a[i].second.first;
		z=a[i].second.second;
	}
	for(i=1;i<=n;++i){
	  printf("%d %d %d\n",ans1[i],ans2[i],ans3[i]);
	}
return 0;}