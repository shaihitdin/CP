#include<iostream>
#include<stdio.h>
using namespace std;
const int N=300001;
int banned[N];
inline int get(int r){
	int res=0;
	for(;r>=1;r=(r&(r+1))-1)	res+=banned[r];
	return res;
}
inline void upd(int x,int inc){
	for(;x<N;x=(x|(x+1)))	t[x]+=inc;
}
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	scanf("%d%d",&n,&h);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			upd(i+(h-a[i]),1);
			upd(i+h+1,-1);
		}
	}
	for(l=1;l<=;++l){
		if(get(r)){
		
		}
		
	}
	return 0;
}