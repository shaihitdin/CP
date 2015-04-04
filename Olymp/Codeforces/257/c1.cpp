#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007
const ll inf= 1e10;
ll n,m ,k;
int run()

{
	ll ans=0;
	scanf("%I64d%I64d%I64d",&n,&m,&k);

	if(n+m-2<k)
	{
		puts("-1");
		return 0;
	}
	if(n>k)ans=max(ans,n/(k+1)*m);
	cerr<<ans<<" ";
	if(m>k)ans=max(ans,m/(k+1)*n);
	cerr<<ans<<" ";
	if(m<=k)ans=max(ans,n/(k-m+2));
	cerr<<ans<<" ";
	if(n<=k)ans=max(ans,m/(k-n+2));
	cerr<<ans<<" ";

	printf("%I64d\n",ans);
	return 0;
}
int main() 
{	
//	freopen("in.txt","r",stdin);
//	ios::sync_with_stdio(0);
	return run();
}