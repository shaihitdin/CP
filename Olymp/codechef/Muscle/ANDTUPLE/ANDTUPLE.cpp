#include<iostream>
#include<stdio.h>
using namespace std;
long long t,n,k;
int main(){
/*
	freopen("in","r",stdin);
	freopen("out","w",stdout);
*/
    cin>>t;
    ++t;
    while(--t){
		cin>>k>>n;
		cout<<(n/2+1)%1000000009<<"\n";
	}
	return 0;
}