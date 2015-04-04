#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
long long n,i,j,k;
vector<long long> v[11];
struct	long_long_long{
	vector<short> el;
}d[201][11],tmp,ans;
inline long_long_long add(long_long_long x,long_long_long y){
	if(x.el.size() < y.el.size())
		swap(x,y);
	int cur=0;
   	for(int i=0;i<x.el.size();++i){
   		if(y.el.size()>i){
   				x.el[i]+=y.el[i];
   		}
   		x.el[i]+=cur;
   		cur=(x.el[i])/10;
   		x.el[i]=x.el[i]%10;
   	}
   	if(cur!=0){
   		x.el.push_back(1);
   	}
   	return x;
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n;     
	tmp.el.push_back(1);
	v[0].push_back(4);
	v[0].push_back(6);
	v[1].push_back(8);
	v[1].push_back(6);
	v[2].push_back(7);
	v[2].push_back(9);
	v[3].push_back(8);
	v[3].push_back(4);
	v[4].push_back(9);
	v[4].push_back(3);
	v[4].push_back(0);
	v[6].push_back(0);
	v[6].push_back(1);
	v[6].push_back(7);
	v[7].push_back(2);
	v[7].push_back(6);
	v[8].push_back(1);
	v[8].push_back(3);
	v[9].push_back(2);
	v[9].push_back(4);
	for(i=0;i<=9;++i){
		d[1][i]=add(d[1][i],tmp);
	}
	for(i=1;i<=n;++i){
		for(j=0;j<=9;++j){
			for(k=0;k<v[j].size();++k){
				d[i+1][v[j][k]]=add(d[i+1][v[j][k]],d[i][j]);
			}
		}
	}
	for(i=0;i<=9;++i){
		if(i==0 || i==8){
			continue;
		}
		ans=add(ans,d[n][i]);
	}
	for(i=ans.el.size()-1;i>=0;--i){
		cout<<ans.el[i];
	}
	return 0;
}