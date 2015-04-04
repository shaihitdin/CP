#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
const int N=1001;
bool u[N][N];
int a[N],n,i,j,k,last;
vector<int> ans;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=a[i];++j){
			if(!u[i][j]){
				for(k=i+1;k<=n && j<=a[k];++k){
					u[k][j]=1;
				}
				ans.push_back(i);
				ans.push_back(j);
				break;
			}
		}
	}
	printf("%d\n",ans.size()/2);
	for(i=0;i<ans.size();i+=2){
		printf("%d %d\n",ans[i],ans[i+1]);
	}
	return 0;
}