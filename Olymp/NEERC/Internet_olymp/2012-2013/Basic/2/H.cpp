#include<iostream>
#include<stdio.h>
using namespace std;
long long n;
inline long long rec(long long n){
	if(n==0)
		return 1;
	if(n&1) 
		return ((rec(n-1)*2)%1000000007);
	else {
		long long b=rec(n>>1);
		return (b*b)%1000000007;
	}
}
int main(){
	freopen("stadium.in","r",stdin);
	freopen("stadium.out","w",stdout);
	cin>>n;
	cout<<rec(n-1);
	return 0;
}