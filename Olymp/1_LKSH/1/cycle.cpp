#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stdio.h>
using namespace std;
char u[100001];
int x, y, p[100001], n, m;
vector<int> v[100001], ans;
void dfs(int x, int pr=-1){
	u[x] = 2;
	p[x] = pr;
	for(int i = 0; i < v[x].size(); ++i){
		if(u[v[x][i]] == 2){
			int to = v[x][i], from = x;
			while(from != to){
			ans.push_back(from);
			from = p[from];
			}
			ans.push_back(to);
			printf("YES\n");
			for(int j=ans.size()-1; j>=0; --j){
					printf("%d ", ans[j]);
			}
			exit(0);
		}
		if(u[v[x][i]] == 0){
			dfs(v[x][i],x);
		}
	}
	u[x] = 1;
}
int main(){
	freopen("cycle.in","r",stdin);
	freopen("cycle.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= m; ++i){
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
	}
	for(int i = 0; i <= n; ++i){
		if(u[i] == 0){
			dfs(i);
		}
	}
	printf("NO");
return 0;}