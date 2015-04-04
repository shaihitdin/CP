#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> ans;
int a[1001],n,i;
int main(){
	freopen("chaotic.in","r",stdin);
	freopen("chaotic.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>a[i];
	}
	for(i=3;i<=n;++i){
		if(a[i]<a[i-1] && a[i-1]<a[i-2]){
			swap(a[i],a[i-1]);
			ans.push_back(i-1);
		}
		if(a[i]>a[i-1] && a[i-1]>a[i-2]){
			swap(a[i],a[i-1]);
			ans.push_back(i-1);
		}
	}
	cout<<ans.size()<<"\n";
	for(i=0;i<ans.size();++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}