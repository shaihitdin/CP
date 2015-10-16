#include<iostream>
#include<stdio.h>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
#define F first
#define S second
#define mkp make_pair
int n,i,j;
pair<int,int> a[2001];
vector<pair<int,int> > v;
int ans[4][2001];
int main(){
	#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif
    cin>>n;
    for(i=1;i<=n;++i){
    	cin>>a[i].F;
    	a[i].S=i;
    }
    sort(a+1,a+n+1);
	for(i=1;i<=n;++i){
		if(a[i-1].F==a[i].F){
			v.push_back(mkp(a[i].S,a[i-1].S));
		}
	}
	if(v.size()<2){
		cout<<"NO";
		return 0;
	}
	for(i=1;i<=n;++i){
			ans[1][i]=a[i].S;
	}
	for(i=1;i<=n;++i){
		for(j=i+1;j<=n;++j){
			if(a[i].F==a[j].F){
				swap(a[i],a[j]);
				goto here;
			}
		}
	}
	here:;
	for(i=1;i<=n;++i){
			ans[2][i]=a[i].S;
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			if(a[i].F==a[j].F && ans[1][i]!=a[j].S && ans[2][i]!=a[j].S){
				swap(a[i],a[j]);
				goto there;
			}
		}
	}
	there:;
	for(i=1;i<=n;++i){
		ans[3][i]=a[i].S;
	}
	cout<<"YES\n";
	for(i=1;i<=3;++i){
		for(j=1;j<=n;++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}