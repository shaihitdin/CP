#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
stack<int> st[4];
vector<int> ans1,ans2;
int n;
bool rec(){
	if(st[3].size()==n){
		return 1;
	}
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			if(i==j)	continue;
			if(st[j].size()==0)	continue;
			if(st[i].size()==0 || st[j].top()<st[i].top()){
			 	int x=st[j].top();
			 	st[j].pop();
			 	st[i].push(x);
			 	cerr<<i<<" "<<j<<" "<<x<<"\n";
			 	if(rec()==1){
			 		ans1.push_back(j);
			 		ans2.push_back(i);
			 		return 1;
			 	}
			 	st[i].pop();
			 	st[j].push(x);
			}		
		}
	}
	return 0;
} 
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>n;
	for(int i=n;i>=1;--i){
		st[1].push(i);
	}
	rec();
	cout<<ans1.size()<<"\n";
	for(int i=ans1.size()-1;i>=0;--i){
		cout<<ans1[i]<<" "<<ans2[i]<<"\n";	
	}
	return 0;
}