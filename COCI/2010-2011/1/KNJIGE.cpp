#include<iostream>
#include<stdio.h>
using namespace std;
const int N=300001;
int t[N],n,i,x;
inline int get(int r){
	int ans=0;
	for(int i=r;i>=1;i=(i&(i+1))-1){
		ans+=t[i];
	}
	return ans;
}
inline void upd(int r,int inc){
	for(int i=r;i<=n;i=(i|(i+1))){
		t[i]+=inc;
	}
	return;
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n;
	int ans=0;
	for(i=1;i<=n;++i){
		cin>>x;
		if(get(n)-get(x))
			++ans;
		else
			upd(x,1);
	}
	cout<<ans;
	return 0;
}