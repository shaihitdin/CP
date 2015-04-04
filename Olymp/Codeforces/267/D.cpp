#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;
#define root 0
const int N = 100001;
int sz;
struct tree {
	int nx[50], suff;
	int flag;
} t[N*6];
long long endq, stq,tmp,ans1,ans2,m;
long long n, i, j, tmp_pos, x;
long long counter[N],TO_counter[N],sz1[N],u1[N],u[N];
string s[N];
string t1[N],to[N];
vector<int> v[N];
inline void dfs(int x){
	u1[x]=1;
	for(int i=0;i<v[x].size();++i){
		int to=v[x][i];
		dfs(to);
		if(counter[to]<counter[x] || (counter[to]==counter[x] && sz1[to]<sz1[x])){
			counter[x]=counter[to];
			sz1[x]=sz1[to];
		}
	}
}
inline void dfs1(int x,int p){
	u1[x]=1;
	if(p!=-1){
		if(counter[p]<counter[x] || (counter[p]==counter[x] && sz1[p]<sz1[x])){
			counter[x]=counter[p];
			sz1[x]=sz1[p];
		}
	}
	for(int i=0;i<v[x].size();++i){
		if(!u1[v[x][i]] && v[x][i]!=x){
			dfs1(v[x][i],x);
			if(counter[v[x][i]]<counter[x] || (counter[v[x][i]]==counter[x] && sz1[v[x][i]]<sz1[x])){
				counter[x]=counter[v[x][i]];
				sz1[x]=sz1[v[x][i]];
			}
		}
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio(0);
	cin >> m;
	for(i = 1; i <= m; ++i){
		cin >> t1[i];
	}
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> s[i] >> to[i];
		tmp_pos = 0;
		sz1[i]=s[i].size();
		for (j = 0; j < (int)s[i].size(); ++j) {
			s[i][j]=tolower(s[i][j]);
			tmp = int(s[i][j])-'a';
			if(tmp==17)
				++counter[i];
			if (t[tmp_pos].nx[tmp] == 0)
				t[tmp_pos].nx[tmp] = ++sz;	
			tmp_pos = t[tmp_pos].nx[tmp];
		}
		t[tmp_pos].flag = i;
		for(j=0;j<(int)to[i].size();++j){
			to[i][j]=tolower(to[i][j]);
			tmp = int(to[i][j])-'a';
			if(tmp==17)
				++TO_counter[i];			
		}
		if(counter[i]>TO_counter[i] || (counter[i]==TO_counter[i] && to[i].size()<s[i].size())){
			counter[i]=TO_counter[i];
		    sz1[i]=to[i].size();
		}
	}
	bool flag=0;
	for (i = 1; i <= n; ++i) {		
		tmp_pos = 0;
		flag=0;
		for (j = 0; j < (int)to[i].size(); ++j) {
			tmp = int(to[i][j])-'a';
			if(t[tmp_pos].nx[tmp]==0){
				flag=1;
				break;
			}
			tmp_pos = t[tmp_pos].nx[tmp];
		}
		if(flag) continue;
		if(t[tmp_pos].flag != 0){
			tmp = t[tmp_pos].flag;
			v[i].push_back(tmp);
			u[tmp] = 1;
		}
	}
	for(i=1;i<=n;++i){
		if(!u[i])
			dfs(i,-1);	
	}
	for(i=1;i<=n;++i){
		if(u[i] && !u1[i]){
			dfs1(i,-1);
		}
	}
	for (i = 1; i <= m; ++i) {		
		tmp_pos = 0;
		flag=0;
		for (j = 0; j < (int)t1[i].size(); ++j) {
			t1[i][j]=tolower(t1[i][j]);
			tmp = int(t1[i][j])-'a';
			if(t[tmp_pos].nx[tmp]==0){
				for(j=0;j<(int)t1[i].size();++j){
					if(t1[i][j]=='r' || t1[i][j]=='R'){
						++ans1;
					}
				}
				ans2+=t1[i].size();
				flag=1;
				break;	
			}
			tmp_pos = t[tmp_pos].nx[tmp];
		}
		if(flag)	continue;
		if(t[tmp_pos].flag != 0){			
			tmp = t[tmp_pos].flag;
			ans1+=counter[tmp];
			ans2+=sz1[tmp];
		}
		else{
			for(j=0;j<(int)t1[i].size();++j){
				t1[i][j]=tolower(t1[i][j]);
				if(t1[i][j]=='r' || t1[i][j]=='R'){
					++ans1;
				}
			}
			ans2+=t1[i].size();
		}
//		cerr<<ans1<<" "<<ans2<<"\n";
	}
	cout<<ans1<<" "<<ans2;
return 0;
}