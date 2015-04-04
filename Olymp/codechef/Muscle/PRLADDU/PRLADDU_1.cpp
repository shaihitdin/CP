#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long t,i,n,a[1000001*2],l,tmp,ans;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>t;
	++t;
	while(--t){
		cin>>n;
		l=1;
		ans=0;
		for(i=1;i<=n;++i){
			cin>>a[i];
			if(a[i]==0)	continue;
			while(l!=i && ((((a[i]>0) && (a[l]<0)) || ((a[i]<0) && (a[l]>0))) || (a[l]==0))){
				tmp=min(abs(a[l]),abs(a[i]));
				ans+=((i-l)*tmp);
				a[l]+=(a[l]>0 ? -1 : +1) * tmp;
				a[i]+=(a[i]>0 ? -1 : +1) * tmp;
				if(a[i]==0)	break;
				++l;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}