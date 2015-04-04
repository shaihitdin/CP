#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
#define mkp make_pair
#define F first
#define S second
int n,a[2001],b[2001],i,j;
map<pair<int,int>,bool> m;
vector<pair<int,pair<int,int> > simx,simy;
int main(){
    #ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	if(!n){
		printf("4");
	}
	if(n==1){
		printf("3");
	}
	for(i=1;i<=n;++i){
		scanf("%d %d",&a[i],&b[i]);
		m[mkp(a[i],b[i])]=1;
	}
	for(i=1;i<=n;++i){
		for(j=i+1;j<=n;++j){
			if(a[i]==a[j] && b[i]==b[j])	continue;
			if(a[i]==a[j]){
			}
			if(b[j]==b[i]){
				
			}
			
		}
	}
	return 0;
}