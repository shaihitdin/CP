#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
struct node{
	int x,cnt;
	node *l,*r;
	node() {l = r = NULL; x = cnt = 0; }
}	*root,*tmp,*L,*R,*mid,*R1;

inline int cnt(node *it){
	return it? it->cnt : 0;
}

inline void upd(node *it){
	if(it){
		it->cnt=cnt(it->l)+cnt(it->r)+1;
	}
}

inline void Split(node *t, node *&l, node *&r, int spkey){
	if(!t){
		l=r=NULL;
		return;
	}
	upd(t);
	if(spkey <= cnt(t->l))	Split(t->l, l, t->l, spkey),r=t;
	else	Split(t->r,t->r,r,spkey-cnt(t->l)-1),l=t;
	upd(t);upd(l);upd(r);
}

inline void OUT(node *it){
	if(!it)	return;
	OUT(it->l);
	cout<<it->x<<" ";
	OUT(it->r);
	return;
}

inline void Merge(node *&t, node *l, node *r){
	upd(l);upd(r);
	if(!l || !r){
		t=l?l:r;
		upd(t);
		return;
	}
	if(cnt(l) < cnt(r))	Merge(l->r,l->r,r),t=l;
	else	Merge(r->l,l,r->l),t=r;
	upd(t);upd(l);upd(r);
}
int n,i,x;
string q;
int main(){
	freopen("kenobi.in","r",stdin);
	freopen("kenobi.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>q;
		if(q=="add"){
			cin>>x;
			tmp=new node();
			tmp->x=x;
			tmp->cnt=1;
			Merge(root,root,tmp);
		}
		if(q=="take"){
			Split(root,root,R,cnt(root)-1);			
		}
		if(q=="mum!"){
			Split(root,L,R,cnt(root)/2);
			Merge(root,R,L);
		}          
	}
	cout<<cnt(root)<<"\n";
	OUT(root);
	return 0;
}