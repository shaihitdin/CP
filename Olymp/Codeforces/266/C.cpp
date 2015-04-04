#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define mkp make_pair
#define F first
#define S second
long long n,a[500010],d[500010],last_eq[500010],last_eq1[500010],suffpointer,prefpointer,ans,l,r,i,j;
pair<long long,long long> pref[500010],suff[500010];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%I64d",&n);
	for(i=1;i<=n;++i){
		scanf("%I64d",&a[i]);
		d[i]=d[i-1]+a[i];
		pref[i].F=d[i];
		pref[i].S=i;
	}
	for(i=n;i>=1;--i){
		suff[i].F=suff[i+1].F+a[i];
		suff[i].S=i;
	}
	stable_sort(pref+1,pref+n+1);
	stable_sort(suff+1,suff+n+1);
	suff[n+1].F=100000000000000000;
	pref[0].F=100000000000000000;

	cerr<<"\n";
	for(i=n;i>=1;--i){
		if(suff[i].F!=suff[i+1].F) last_eq[i]=i;
		else	last_eq[i]=last_eq[i+1];	
	}
	for(i=n;i>=1;--i){
		if(pref[i].F!=pref[i+1].F) last_eq1[i]=i;
		else	last_eq1[i]=last_eq1[i+1];	
	}
	suffpointer=1;
	prefpointer=1;
	while(suffpointer<=n && prefpointer<=n){
		while(pref[prefpointer].F<suff[suffpointer].F && prefpointer<=n)	prefpointer=last_eq1[prefpointer]+1;
		while(suff[suffpointer].F<pref[prefpointer].F && suffpointer<=n)	suffpointer=last_eq[suffpointer]+1;
		//cerr<<pref[prefpointer].F<<" "<<suff[suffpointer].F<<"\n";
		if(pref[prefpointer].F!=suff[suffpointer].F){
			continue;
		}
		cerr<<"OK";
		if(suff[suffpointer].S==pref[prefpointer].S)	++suffpointer;
		cerr<<suff[suffpointer].S<<"-"<<pref[prefpointer].S<<"&";
		if(d[suff[suffpointer].S]-d[pref[prefpointer].S]==pref[prefpointer].F){
			cerr<<"&&"<<pref[prefpointer].S<<"&&\n";
			cerr<<suff[suffpointer].S<<" "<<pref[prefpointer].S<<"\n";
			while( pref[prefpointer].S >= suff[suffpointer].S && suffpointer!=last_eq[suffpointer]) ++suffpointer;
			ans+=max((last_eq[suffpointer]-suffpointer+1)*(last_eq1[prefpointer]-prefpointer+1),0*1ll);
		}
		prefpointer=last_eq1[prefpointer]+1;
	}
	printf("%I64d",ans);
return 0;}