#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
int mx,i,j;
string s;
int cnt[256],ans;
char mxc;
vector<int> l[256];
bool u[100001];
int main () {
	freopen ("strings.in", "r", stdin);
	freopen ("strings.out", "w", stdout);
	ios_base :: sync_with_stdio (0);
	cin >> s;
	for(i=0;i<s.size();++i){
		++cnt[char(s[i])];
	}
	for(i=0;i<256;++i){
		mx=max(mx,cnt[i]);
	}
	for(i=0;i<s.size();++i){
		if(cnt[s[i]]==mx){
			l[s[i]].push_back(i);
		}
	}
	for(int i='a';i<='z';++i){
		if(l[i].size()==0)	break;			
		for(int len=0;;++len){
			for(j=0;j<l[i].size();++j){
				if(l[i][j]+len >= s.size() || s[l[i][j]+len]!=s[l[i][0]+len] || u[l[i][j]+len]) {
					ans=max(ans,len);
                    goto here;
				}
			}
			for(j=0;j<l[i].size();++j){
				u[l[i][j]+len]=1;
			}
		}
		memset(u,0,sizeof(u));
		here:;
	}
	cout << ans;
	return 0;
}