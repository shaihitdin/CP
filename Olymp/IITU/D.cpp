#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;
const int N=(1e6)+10;
int s[N];
int x[N],y[N],mx[N],ans,n,i;
int main(){
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d",&x[i],&y[i]);
		s[x[i]]=max(s[x[i]],y[i]);
		s[y[i]]=max(s[y[i]],x[i]);
	}
	for(i=N-2;i>=1;--i){
		mx[i]=max(mx[i+1],s[i]);
	}
	for(i=1;i<=n;++i){
///		cerr<<x[i]<<" "<<mx[x[i]]<<" "<<y[i]<<" "<<mx[y[i]]<<"\n";
		if(mx[x[i]]>y[i] || mx[y[i]]>x[i]){
			++ans;
///			cerr<<i<<"\n";
		}
	}
	printf("%d",ans);
	return 0;
}