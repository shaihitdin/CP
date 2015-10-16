#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;
int n,i,j,d[256],k;
long long ans;
char x;
vector<int> v;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin>>n>>k;	
	for(i=1;i<=n;++i){
		cin>>x;
		++d[int(x)];
	}
	for(i=0;i<256;++i){
		if(d[i]!=0)
			v.push_back(d[i]);
	}
	sort(v.begin(),v.end());
	for(i=v.size()-1;k!=0;--i){
		if(v[i]>k){ans+=(k*k); k=0;}
		else	{ans+=v[i]*v[i]; k-=v[i];}
	}
	cout<<ans;
return 0;
}