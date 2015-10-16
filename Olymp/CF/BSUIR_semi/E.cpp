#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<time.h>
#include<stdlib.h>
using namespace std;
int n,k,i,x,y;
struct tree{
   int x;
   tree *l,*r;
}*root,*tmp;
tree * M(tree *l,tree *r){
	if(!l || !r)
	 return l ? l : r;
     if(l->x > r->x){
        swap(l,r);
     }
     if((rand()^rand()^rand())&1) swap(l->l,l->r);
	l->l=M(l->l,r);
	return l;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif
    scanf("%d%d",&n,&k);
    for(i=1;i<=k;++i){
    	tmp=new tree();
    	tmp->x=0;
    	root=M(root,tmp);
    }
    for(i=1;i<=n;++i){
        scanf("%d",&y);
        x=root->x;
        root=M(root->l,root->r);
        if(x+y<=2e6){
        	tmp=new tree();
        	tmp->x=x+y;
        	root=M(root,tmp);
        }
    }

    printf("%d",root->x);
    return 0;
}