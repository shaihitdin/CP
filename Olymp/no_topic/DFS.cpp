#include<iostream>
#include<vector>
using namespace std;
vector<int> a[101];
int u[101],col[101],color_number=1,i,x,y,n,m,f;

void dfs(int v,int paint) {
	u[v] = 1;
	col[v] = paint;
	for(int i = 0; i < a[v].size(); ++i) {
		if(u[a[v][i]] == 0)
			dfs(a[v][i], paint);
	}
}

int main(){
	cin >> n >> m;
	for(i = 1; i <= m; ++i) {
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(i = 1; i <= n; ++i) {
		if(u[i] == 0)
			dfs(i,color_number++);
	}
	cin >> f;
	for(i = 1; i <= f; ++i) {
		cin >> x >> y;
		if(col[x] == col[y]) {
			cout << "In one component";
		}
		else {
			cout << "Not in one component";
		}
	}
	return 0;
}