#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
const long long mod = 1000000007; 
long long a,b,ans,ans1,i,a1,n,d,sum;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	srand(time(0));
	cin>>a>>b;
		ans=ans1=0;
		for(i = 1; i < b; ++i){
			a1=((b*i)+i)%(mod*2);
			d=(b*i)%(mod*2);
			n=a;
			sum=(((2*1ll * a1)%(mod*2) + (d * (n-1))%(mod*2)) * n % (mod*2)) / 2;
			ans=(sum+ans)% mod;
		}
	cout<<ans;
	return 0;
}