#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long a[6],ans,i; 
int main() {
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	for(i=1;i<=5;++i)
		cin>>a[i];
	for(i=1;i<=5;++i)
		ans+=a[i];
	if(ans==0){
		cout<<-1;
		return 0;
	}
	cout<<((ans%5==0)? (ans/5) : (-1));
	return 0;
}