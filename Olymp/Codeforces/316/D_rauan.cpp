#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define pb push_back
const int N = 5e5 + 6;

int n, m, cnt, tin[N], tout[N], timer, x, y, p, mx, d[N];
char a[N];
bool u[N];
vector <int> g[N], ds[N];
vector <int> chin[N][26];

void dfs(int v, int depth){
	u[v] = 1;
	tin[v] = timer++;
	ds[depth].pb(v);
	d[v] = depth;
	mx = max(mx, depth);
	for(int i = 0; i < g[v].size(); ++i){
		int to = g[v][i];
		if(!u[to])
			dfs(to, depth + 1);		
	}		
	tout[v] = timer++;
}

int main(){
	ios_base :: sync_with_stdio(0);
	#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif

    scanf ("%d%d", &n, &m);
    
    for(int i = 2; i <= n; ++i){
    	scanf ("%d", &p);
    	g[p].pb(i);    	
    }
    scanf ("\n");
    for(int i = 1; i <= n; ++i){
    	scanf ("%c", &a[i]);
    }

    dfs(1, 1);
    //cerr << "ok\n";
    for(int i = 1; i <= mx; ++i){
		for(int j = 0; j < 26; ++j){
			chin[i][j].pb(0);			
			if((a[ds[i][0]] - 'a') == j)
				chin[i][j][0]++;	
			for(int k = 1; k < ds[i].size(); ++k){				
				chin[i][j].pb(chin[i][j][k - 1]);
				if((a[ds[i][k]] - 'a') == j){
					chin[i][j][k]++;		
				}
			}				
		}    	
    }
    //cerr << "ok\n";
    for(int i = 1; i <= m; ++i){
    	scanf ("%d%d", &x, &y);
    	if(y < d[x]){
    		puts ("Yes");
    		continue;
    	}    	
    	int l = 0, r = ds[y].size();
    	
    	while(r - l > 1){
    		int mid = (r + l) / 2;
    		if(tin[ds[y][mid]] > tin[x])
    			r = mid;
    		else
    			l = mid;    		    			    		
    	}
    	int lt = l;
    	l = 0, r = ds[y].size();
    	while(r - l > 1){
    		int mid = (r + l) / 2;
    		if(tout[ds[y][mid]] < tout[x])
    			l = mid;
    		else
    			r = mid;    		    			    		
    	}    	
    	
    	int rt = l;
    	
    	for(int j = 0; j < 26; ++j){
    		if((lt == 0 && chin[y][j][rt] % 2 != 0) || (lt > 0 && (chin[y][j][rt] - chin[y][j][lt - 1]) % 2 != 0))
    			++cnt;
    	}

    	if(cnt > 1)
    		puts ("No");
    	else
			puts ("Yes");
    	//cerr << cnt << "\n";
    	cnt = 0;		
    	
    }



	return 0;
}