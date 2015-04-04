#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;
#define mkp make_pair
string a[100001];
int n,m;
bool cmp(const string &lhs, const string &rhs){
	for(int i=0;i<min(lhs.size(),rhs.size());++i){
		if(lhs[i]!=rhs[i]){
			return lhs[i]>rhs[i];
		}
	}
	string tmps=lhs+rhs,
	tmpss=rhs+lhs;
	return (tmps>tmpss);
}
int main(){
	freopen("maxnumber.in","r",stdin);
	freopen("maxnumber.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1,&cmp);
	
	for(int i=1;i<=n;++i){
		cout<<a[i]<<" ";
	}
	return 0;
}