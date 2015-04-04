#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
#define root 0
const int N = 100001;
int sz;
struct tree {
	int nx[95], suff;
	bool flag;
} t[N];
int q[N], endq, stq;
short tmp;
int n, i, j, p, m, tmp_pos, x, ans;
string s, t1, cens[11];
char txt[101];
inline bool check() {
	tmp_pos = 0;
	bool flag = 0;
	for(i = 0; i < m; ++i) {
		tmp = int(txt[i])-32;
		tmp_pos = t[tmp_pos].nx[tmp];
		if(t[tmp_pos].flag) {
			return 0;
		}
	}
	return 1;
}
inline void gen(int lvl) {
	if(lvl==m) {
		if(check()) ++ans;
//		cerr<<txt<<"\n";
		return ;
	}
	for(int i = 0; i < t1.size(); ++i) {
		txt[lvl]=t1[i];
		gen(lvl+1);
	}
}
int main() {
	freopen("censored.in", "r", stdin);
	freopen("censored.out", "w", stdout);
	ios_base :: sync_with_stdio(0);
	cin >> n >> m >> p;
	cin >> t1;
	for(i = 0; i < p; ++i)
	cin >> cens[i];
	for(i = 0; i < p; ++i) {
		tmp_pos = 0;
		for(j = 0; j < (int)cens[i].size(); ++j) {
			tmp = int(cens[i][j])-32;
			if(t[tmp_pos].nx[tmp] == 0) {
				t[tmp_pos].nx[tmp] = ++sz;	
			}
			tmp_pos = t[tmp_pos].nx[tmp];
		}
		t[tmp_pos].flag = 1;
	}
	q[endq++] = 0;
	t[0].suff = 0;
	while(stq != endq) {
		x = q[stq++];
		if(x != 0) {
			for(i = 0; i < 95; ++i) {
				if(t[x].nx[i] == 0) {
					t[x].nx[i] = t[t[x].suff].nx[i];
				}    else {
						t[t[x].nx[i]].suff = t[t[x].suff].nx[i];
						q[endq++] = t[x].nx[i];
						if(t[t[t[x].nx[i]].suff].flag == 1) {
							t[t[x].nx[i]].flag = 1;
						}
			          }
			}
		} else {
				for(i = 0; i < 95; ++i) {
					if(t[x].nx[i] == 0) {
						t[x].nx[i] = 0;
					} else {
							t[t[x].nx[i]].suff = 0;
							q[endq++] = t[x].nx[i];
							if(t[t[t[x].nx[i]].suff].flag == 1) {
								t[t[x].nx[i]].flag = 1;
							}
					  }
		  }
	     }
	}
	gen(0);
	cout<<ans;
return 0;}