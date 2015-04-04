#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
const int N=101;
vector<int> a,b;
int x,n,m,i,y,z;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>m;
	for(i=1;i<=n;++i){
	 cin>>x;
	 a.push_back(x);
	 b.push_back(i);
	}
	while(a.size()!=1){
		if(a[0]>m){
		y=a[0]-m;
		z=b[0];
		a.erase(a.begin());
		b.erase(b.begin());
		a.push_back(y);
		b.push_back(z);
		}
		else{
		a.erase(a.begin());
		b.erase(b.begin());
		}
	}
	cout<<b[0];
return 0;}