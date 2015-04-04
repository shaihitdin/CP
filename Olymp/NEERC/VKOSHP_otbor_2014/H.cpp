#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
const int N=1001;
map<string,int> mp;
int d[N],n,i;
string a[N],b[N],c[N];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	freopen("names.in","r",stdin);
	freopen("names.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(i=1;i<=n;++i){
		++mp[a[i]];
		++mp[b[i]];
	}
	for(i=1;i<=n;++i){
		if(mp[a[i]]>1){
			swap(a[i],c[i]);
			swap(c[i],b[i]);
		}
	}
	for(i=1;i<=n;++i){
		d[i]=i;
	}
	sort(d+1,d+n+1,cmp);
	for(i=1;i<=n;++i){
		cout<<a[d[i]]<<" "<<b[d[i]]<<" "<<c[d[i]]<<"\n";
	}
	return 0;
}