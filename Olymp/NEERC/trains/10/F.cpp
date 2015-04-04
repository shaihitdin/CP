#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 250, M = 10001*10, INF = 1000000009;
long long n, m, x, y, cap, cost, sz;
long long d[N], s, f, i, j, k;
vector<long long> v[N];
long long q[N], stq, enq;
long long push, pos[N], ans;

struct edge {
	long long y, cap, flow;
}e[M];

long long limit = 1<<30;

inline void add_edge() {
	edge e1 = {y, cap, 0}, e2 = {x, 0, 0};
	v[x].push_back(sz);
	e[sz++] = e1;
	v[y].push_back(sz);
	e[sz++] = e2;
}

inline bool bfs() {
	q[++enq] = s;
	d[s] = 1;
	while (stq < enq) {
		x = q[++stq];
		for (i = 0; i < (int)v[x].size(); ++i) {
			int id = v[x][i], to = e[id].y;
			 if (d[to] == 0 && e[id].flow + limit <= e[id].cap)
			 	d[to] = d[x]+1, q[++enq] = to;
		}
	}
	return d[f] != 0;
}

inline long long dfs(long long x, long long flow) {
	if (x == f) return flow;
	if (!flow) return 0;
	for (; pos[x] < (int)v[x].size(); ++pos[x]) {
		int id = v[x][pos[x]], to = e[id].y;
		if(d[to] == d[x] + 1) { 	
			long long pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
			if(pushed) {
				e[id].flow += pushed;
				e[id^1].flow -= pushed;
				return pushed;
			}
		}
	}
	return 0;
}

inline void dinitz() {
	memset(pos, 0, sizeof(pos));
	memset(d, 0, sizeof(d));
	enq = stq = 0;
	while (bfs()) {
		while (true) {
			long long push = dfs(s, 1 << 30);
			if(!push) break;
			ans += push;
		}
		memset(pos, 0, sizeof(pos));
		memset(d, 0, sizeof(d));
		enq = stq = 0;
	}
}

long long a, b, len, death;                  
long long bunks[N], people[N];         
long long dist[N][N];

void Floyd() {              
	for( k = 1; k <= n; ++k) 
		for( i = 1; i <= n; ++i)
			for( j = 1; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
                  
int main() {
/*   */
	freopen("nucleus.in", "r", stdin);
	freopen("nucleus.out", "w", stdout);
   // freopen(file"err", "w", stderr);                         
    
    for(;;) {                                       
    	//scanf("%d %d %d", &n, &m, &death);  
    	if (!(cin >> n)) 
    		break;
    	cin >> m >> death;	
    	cerr<<n<<" "<<m<<" "<<death<<"\n";
   		s = n + n + 1, f = n + n + 2;
   		for( i = 1; i <= n; ++i)
			for( j = 1; j <= n; ++j)
				dist[i][j] = INF;
		for( i = 1; i <= n; ++i) 
			dist[i][i] = 0;     
    	for( i = 1; i <= m; ++i) {
    		cin >> a >> b >> len;
    		dist[a][b] = min(dist[a][b], len);
        	dist[b][a] = min(dist[b][a], len);
    	}                 
       	Floyd();
    	for( i = 1; i <= n; ++i) {
    		cin >> people[i];
    		x = s;
    		y = i;
    		cap = people[i];
    		add_edge();
    	}
    	for( i = 1; i <= n; ++i) { 
    		cin >> bunks[i];
    		x = i+n;
    		y = f;
    		cap = bunks[i];   
    		add_edge();
    	}
       	for(i = 1; i <= n; ++i) {
    		for(j = 1; j <= n; ++j) {
    			if(dist[i][j]<death){
    				x = i;
    				y = j+n;
    				cap = INF;
    				add_edge();
    			}
    		}
    	}               
   		for(limit = 1 << 30; limit > 0; limit >>= 1) {
			dinitz();
		}
		cout << ans << "\n";
		sz = ans = 0;
		for(i = 1; i <= n+n+2; ++i) 
			v[i].clear();   
	}
    return 0;
}
                      
