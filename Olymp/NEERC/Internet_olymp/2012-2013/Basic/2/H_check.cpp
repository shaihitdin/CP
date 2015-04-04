#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,i,a[100];
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>n;
	for(i=1;i<=n;++i)
		a[i]=i;
	do{
		for(i=1;i<=n;++i)
			cout<<a[i]<<" ";
		cout<<"\n";
	}while(next_permutation(a+1,a+n+1));
	return 0;
}