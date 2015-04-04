#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,i,a[11],tmp_max,j;
vector<int> v,tmp;
inline string itos(int x){
	string sd;
	while(x!=0){
		sd+=((x%10)+'0');
		x/=10;
	}
	return sd;
}
inline void rec(int sum,int lvl){
	if(lvl==n+1){
		tmp_max=max(tmp_max,sum);
		return;
	}
	string s=itos(sum+a[lvl]);
	sort(s.begin(),s.end());
	do{
		rec(atoi(s.c_str()),lvl+1);
	}while(next_permutation(s.begin(),s.end()));
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&n);
	string s="001";
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	rec(0,1);
	printf("%d",tmp_max);
	return 0;
}