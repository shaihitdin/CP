/*                                                                       
nikto ne smeet obijat' malen'kogo begemotika
  _ _ _ _
 /.  _  .\
|   /_\   |
|_ _ _ _ _|
   NIKTO                                                             
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <cassert>
#include <math.h>
#include <vector>
#include <time.h>
using namespace std;           
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)    
#define file ""
#ifdef _WIN32
	#define lld "%I64d" 
#else
	#define lld "%lld"
#endif
                       
typedef pair <int, int> PII;
                                             
const int maxn = 300100; 
const int INF = int(2e9) + 7;
const int maxcall = 5;

int n, m;      
vector <int> g[maxn];
int s, f, r;
int d[maxn][maxcall], call;

int que[maxn], head, last;
void BFS(int x) {
	++call;
	last = head = 0;
	que[++head] = x;
	//d[x][call] = 1;   
	while (last < head) { 
		int v = que[++last]; 
		//forn(i, 0, g[v].size() - 1) {
		for(int i = 0; i < g[v].size(); ++i) {   
			int to = g[v][i];  
			if (!d[to][call] && to != x) {
				d[to][call] = d[v][call] + 1;
				que[++head] = to;
			}	
		}
	}
}
///Calls
///1 - from R
///2 - from S

bool u[maxn];
int dfs(int x, int cur) {
	if (u[x] || x == s) return cur; 
	//if (x == s) return cur;   
	u[x] = 1;
	int ans = 0;           
	//forn(i, 0, g[x].size() - 1) { 
	for(int i = 0; i < g[x].size(); ++i) {
		int to = g[x][i];
		if (d[to][2] < d[x][2])	{
			int way = dfs(to, min(cur, d[x][1]));
			ans = max(ans, way);	
			//if (x == 2) cerr<<to<<" "<<cur<<"\n";
		}
	}	
	return ans;
}                     

int ans;                               

int a, b; 	     
int main() {                   
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);   

	scanf("%d %d", &n, &m);
	forn(i, 1, m) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	scanf("%d %d %d", &s, &f, &r);
	       
	BFS(r); 
    BFS(s);         
    ans = dfs(f, d[f][1]);

    printf("%d", ans);

    return 0; 	
}
                          