#include<stdio.h>
#include<iostream>
#include<time.h>
#include<algorithm>
using namespace std;
typedef struct node* tnode;
struct node{
	int x,y,z,cnt;
	int mx,mxz;
	tnode l,r;
	node(){l=r=NULL;mx=0;}
};
void mx(tnode it){
	return (it?it->mx:0);
}
void upd(tnode it){
	if(it){
		if(max(it->x,max(mx(it->l),mx(it->r)))==it->x){
			
		}
		if(max(it->x,max(mx(it->l),mx(it->r)))==mx(it->l)){
		
		}
		if(max(it->x,max(mx(it->l),mx(it->r)))==mx(it->r)){
		
		}
	}
}
int cnt (pitem t) {
	return t ? t->cnt : 0;
}

void upd_cnt (pitem t) {
	if (t)
		t->cnt = 1 + cnt(t->l) + cnt (t->r);
}
void sp(tnode t,tnode &l,tnode &r,int key,int add=0){
    	upd (t);
	if(!t){
	 l=r=NULL;
	 return ;
	}
//	cerr<<"split:"<<key<<" & "<<(t->lastpos+t->energy)<<" ";
	int cur_key=add+cnt(t->l);
	if(key <= cur_key)
	  sp(t->l,l,t->l,key), r=t;
	else
	  sp(t->r,t->r,r,add+1+cnt(t->l)), l=t;
	upd(t);
	upd(l);
	upd(r);
	upd_cnt(t);
}
void me(tnode &t,tnode l,tnode r){
	upd(l);
	upd(r);
	if(!l || !r)
	t=l? l : r;
	else if(l->y > r->y)
	  me(l->r,l->r,r),t=l;
     else
	  me(r->l,l,r->l),t=r;
	upd(l);
	upd(r);
	upd(t);
	upd_cnt(t);
}

tnode root,tmp,L,R;
int i,j,ans,rndm[1000001];
int n,m,k,p,a[N][N],ans,sum,pen1,pen2,x,y;

int main(){
      freopen("in","r",stdin);
      freopen("out","w",stdout);
      srand(time(0));
	scanf("%d %d %d %d",&n,&m,&k,&p);
     for(i=1;i<=n*m;++i){
     	rndm[i]=i;
     }
     random_shuffle(rndm+1,rndm+1+n);
	
	for(i=1;i<=n;++i)
	   for(j=1;j<=m;++j)
	   	 scanf("%d",&a[i][j]);

	for(i=1;i<=n;++i){
		sum=0;
	   for(j=1;j<=m;++j){
	     sum+=a[i][j];
	   }
	   tmp=new node();
	   tmp->x=sum;
	   tmp->y=rndm[i];
	   tmp->z=i;
	   me(root,root,tmp);
	}
	for(i=1;i<=m;++i){
		sum=0;
	   for(j=1;j<=n;++j){
	     sum+=a[j][i];
	   }
	   tmp=new node();
	   tmp->x=sum;
	   tmp->y=rndm[i+n];
	   tmp->z=i+n;
	   me(root,root,tmp);
	}
	for(i=1;i<=k;++i){
		root->mx=x;
		root->mxz=y;
	     if(t1[1]<=n){
	        //pen1 his
             if(t[1]-pen1>=0){
               ans+=t[1]-pen1;
               t[sz+t1[1]-1]-=(p*m);
               pen2+=p;
             }
             else
               break;
	     }
	     else{
	        //pen2 his
             if(t[1]-pen2>=0){
               ans+=t[1]-pen2;
               t[sz+t1[1]-1]-=(p*n);
               pen1+=p;
             }
             else
               break;
	     }
	     x=;
	     cerr<<x<<"\n";
	     
	}

		printf("%d ",ans);

return 0;}