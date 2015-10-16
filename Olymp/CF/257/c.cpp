#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
long long x,n,m,i,y,z,k,ans1,ans2;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>m>>k;
	if(k>(n-1)+(m-1)){
		cout<<-1;
		return 0;
	}
	//ans1 first divide n, ans2 first divide m
		if(k<n){
			ans1=n/(k+1);
			ans1*=m;
		}
		else{
			k-=(n-1);
			ans1=m/(k+1);
			k+=(n-1);
		}

	///
		if(k<m){
			ans2=m/(k+1);
			ans2*=n;
		}
		else{
			k-=(m-1);
			ans2=n/(k+1);
		}
	cout<<max(ans1,ans2);
return 0;}