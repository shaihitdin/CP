#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;                  
#define forn(i, x, n) for(int i = x; i <= n; ++i)
#define for1(i, n, x) for(int i = n; i >= x; --i)
#define file /*"nucleus."*/
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sec second
#define PII pair <int, int>           
 
const int maxn = 128;
const int maxm = 131072;
const int INF = int(2e9) + 7;
                          
ll n, m, cap, cost, sz;
ll d[maxn], s, f;
vector <ll> v[maxn];
ll q[maxn], stq, enq;
ll push, pos[maxn], ans;
 
struct edge {
    ll y, cap, flow;
}e[maxm];
 
ll limit = 1<<30;
 
inline void add_edge(int x, int y, int cap) {
    edge e1 = {y, cap, 0}, e2 = {x, 0, 0};
    e[++sz] = e1;
    v[x].push_back(sz);                         
    e[++sz] = e2;
    v[y].push_back(sz);
}
 
inline bool bfs() {
    q[++enq] = s;
    d[s] = 1;
    while (stq < enq) {
        int x = q[++stq];
        for (int i = 0; i < (int)v[x].size(); ++i) {
            int id = v[x][i], to = e[id].y;
            if (d[to] == 0 && e[id].flow + limit <= e[id].cap)
                d[to] = d[x]+1, q[++enq] = to;
        }
    }                                           
    return d[f] != 0;
}
 
inline ll dfs(ll x, ll flow) {
    if (x == f) return flow;
    if (!flow) return 0;
    for (; pos[x] < (int)v[x].size(); ++pos[x]) {
        int id = v[x][pos[x]], to = e[id].y;
        if(d[to] == d[x] + 1) {     
            ll pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
            if(pushed) {
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
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
            ll push = dfs(s, 1 << 30);
            if(!push) break;
            ans += push;                        
        }                                       
        memset(pos, 0, sizeof(pos));
        memset(d, 0, sizeof(d));
        enq = stq = 0;
    }   
}       
 
int a, b, len, death;                  
int bunks[maxn], people[maxn];         
ll dist[maxn][maxn];
 
void Floyd() {              
    forn(k, 1, n) 
        forn(i, 1, n)
            forn(j, 1, n)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
                   
int main() {
/*   */
    freopen(file"in", "r", stdin);
    freopen(file"out", "w", stdout);
   // freopen(file"err", "w", stderr);                         
     
    for(;;) {                                       
        if (!(cin >> n)) 
            break;
        cin >> m >> death;                  
        s = n + 1, f = n + 2;
        forn(i, 1, n)
            forn(j, 1, n)
                if (i != j) 
                    dist[i][j] = INF;     
        forn(i, 1, m) {
            scanf("%d %d %d", &a, &b, &len);    
            dist[a][b] = len;
            dist[b][a] = len;
        }                 
        Floyd();
        forn(i, 1, n) 
            scanf("%d", &people[i]); 
        forn(i, 1, n) 
            scanf("%d", &bunks[i]);   
        if (n == 1) {
            printf("%d\n", min(bunks[1], people[1]));
            continue;
        }                                        
        forn(i, 1, n) {
            if (people[i] < bunks[i]) 
                add_edge(i, f, bunks[i] - people[i]);  
            else {                        
                add_edge(s, i, people[i] - bunks[i]);
                ans += bunks[i];
                forn(j, 1, n) 
                    if (people[j] < bunks[j] && dist[i][j] < death)
                        add_edge(i, j, INF);    
            }
        }                                               
        for(limit = 1 << 30; limit > 0; limit >>= 1) {
            dinitz();
        }
        printf("%d\n", ans);           
        sz = ans = 0;
        forn(i, 1, n + 2) 
            v[i].clear();  
    }
    return 0;
}
   