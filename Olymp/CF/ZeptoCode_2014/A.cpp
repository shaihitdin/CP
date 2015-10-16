#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int N=2001;
int n,x,ans1,ans2,i,j,prev,or_x,tmppos,tmp,ans;
int t[N],h[N],m[N],u[N];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
		cin>>n>>x;
		or_x=x;
		for(i=1;i<=n;++i)
		 cin>>t[i]>>h[i]>>m[i];
		 prev=-1;
		 for(i=1;i<=n;++i){
		 	tmppos=-1;
		 	tmp=-1;
		 	for(j=1;j<=n;++j){
		 		if(prev!=t[j] && x>=h[j] && !u[j] && m[j]>tmp){
		 		  tmp=m[j];
		 		  tmppos=j;
		 		}
		 	}
		 	if(tmppos==-1)
		 	break;
		 	x+=m[tmppos];
		 	prev=t[tmppos];
		 	u[tmppos]=1;
			++ans;
		 }
		 cout<<ans;
return 0;}