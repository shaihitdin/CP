#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
///N=10^6 with (rand()^rand()^rand())
///N=10^5 with (rand())
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
     if( rand() & 1) swap(l->l,l->r);
    l->l=M(l->l,r);
    return l;
}
int n,i,el;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
     srand(time(0));
     scanf("%d",&n);
       for(i=1;i<=n;++i){
          scanf("%d",&el);
          tmp=new tree();
          tmp->x=el;
          root=M(root,tmp);
       }
       for(i=1;i<=n;++i){
           printf("%d ",root->x);
           root=M(root->l,root->r);
       }
return 0;}