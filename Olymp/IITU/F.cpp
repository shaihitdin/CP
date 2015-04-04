#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define mkp make_pair
#define F first
#define S second
pair<long long,long long> a[2000001];
long long ch[31],n,i,j,ans,l;
string s[2000001];
int main(){
	freopen("sentence.in","r",stdin);
	freopen("sentence.out","w",stdout);
	ios_base::sync_with_stdio(0);
	for(i=1;cin>>s[i];++i);
	n=i-1;
	for(i=1;i<=n;++i){
		a[i]=mkp(s[i].size(),i);
	}
	sort(a+1,a+n+1);
	for(i=n;i>=1;--i){
		ans+=((a[i].F)*(i-1));
	}
//	cerr<<ans;
	for(l=1,i=0;i<a[n].F;++i){
		while(a[l].F<i+1)	
			++l;
//		cerr<<l<<" ";
		memset(ch,0,sizeof(ch));
		for(j=l;j<=n;++j){
			++ch[int(s[a[j].S][i]-'a')];
//			cerr<<s[a[j].S][i]<<" ";
		}
		for(j=0;j<=25;++j){
			if(ch[j]==0)	continue;
			if(ch[j]==1)	continue;
//	        cerr<<ch[j]<<" ";
			ans-=(((ch[j])*(ch[j]-1))/2);
		}
//		cerr<<"\n";
	}
	cout<<ans;
	return 0;
}