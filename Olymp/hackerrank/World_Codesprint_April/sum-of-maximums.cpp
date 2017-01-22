#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define pb push_back
typedef long long ll;      
typedef pair <int, char> PII;
 
const int N = 135000 + 1;
const int sqN = 110;
const int INF = 1e9 + 9;                                          
const int B = 1e9 + 7;
 
int n, m, sq;
int a[N];              
 
int sqmx[sqN][N];
ll ans[sqN][N], rans[sqN][N];
int b_id[N], rb_id[N];
int bl[N], b_head[N], b_tail[N];
         
ll st[N];
int pos[N], sz;
 
void precalc() {
    int nxt_head = 1;
    forn(i, 1, n) {
        if (i == nxt_head) {
            bl[i] = bl[i - 1] + 1;     
            b_head[bl[i]] = i;
            b_tail[bl[i]] = min(i + sq - 1, n);
            nxt_head += sq;
        }
        else
            bl[i] = bl[i - 1];
    }
 
    forn(l, 1, n) {
        if (l != b_head[bl[l]]) continue;
        sz = 0, pos[0] = l - 1, st[0] = INF;
        ll cur = 0;
        sqmx[bl[l]][l - 1] = -INF;
        forn(i, l, n) {                    
            while (sz && st[sz] <= a[i]) {
                cur -= st[sz] * (pos[sz] - pos[sz - 1]);
                --sz;
            }                                                  
            st[++sz] = a[i];
            pos[sz] = i;
            cur += st[sz] * (pos[sz] - pos[sz - 1]);
            ans[bl[l]][i] = ans[bl[l]][i - 1] + cur;              
            sqmx[bl[l]][i] = max(sqmx[bl[l]][i - 1], a[i]);
        }          
    }  
    for1(r, n, 1) {
        if (r != b_tail[bl[r]]) continue;
        sz = 0, pos[0] = r + 1, st[0] = INF;
        ll cur = 0;
        for1(i, r, 1) {                    
            while (sz && st[sz] <= a[i]) {
                cur -= st[sz] * (pos[sz - 1] - pos[sz]);
                --sz;
            }                                                  
            st[++sz] = a[i];
            pos[sz] = i;
            cur += st[sz] * (pos[sz - 1] - pos[sz]);
            rans[bl[r]][i] = rans[bl[r]][i + 1] + cur;                
        }                          
    }  
}
         
ll solve(int l, int r) {
    sz = 0, pos[0] = l - 1, st[0] = INF;
    ll res = 0, cur = 0;
    forn(i, l, r) {
        for (; sz && st[sz] <= a[i]; --sz)
            cur -= st[sz] * (pos[sz] - pos[sz - 1]);                
        st[++sz] = a[i];
        pos[sz] = i;
        cur += st[sz] * (pos[sz] - pos[sz - 1]);
        res += cur;                
    }
    return res;
}
 
int c[N];
ll lpos[N], rpos[N];
       
int main() {                                      
#ifdef machine42
    freopen(file"in", "r", stdin);
    freopen(file"out", "w", stdout);
#endif                                                                                          
    ios_base :: sync_with_stdio (0);
    cin.tie(0);
                                                                                   
    cin >> n >> m;                                      
    assert(n < N);  
    forn(i, 1, n)
        cin >> a[i];
    sq = max(1, n / 100);
    precalc();
    forn(q, 1, m) {
        int l, r;
        cin >> l >> r;                        
        if (r - l <= 3 * sq) {
            cout << solve(l, r) << "\n";
            continue;
        }                                      
        int L = b_head[bl[l] + 1], R = b_tail[bl[r] - 1];
        ll res = ans[bl[L]][r] + rans[bl[R]][l] - ans[bl[L]][R];                            
        if (l == L || r == R) {
            cout << res << "\n";
            continue;                  
        }                                      
        ll tans = 0;
        c[L - 1] = a[L - 1];
        tans += c[L - 1];        
        for1(i, L - 2, l) {
            c[i] = max(c[i + 1], a[i]);
            tans += c[i];
        }                            
        int mx = sqmx[bl[L]][R];              
        int ptr = L - 1;        
        forn(i, R + 1, r) {
            int nmx = max(mx, a[i]);
            tans += 1ll * ((L - 1) - ptr) * (nmx - mx);
            mx = max(mx, a[i]);
            while (ptr >= l && mx > c[ptr]) {
                tans += (mx - c[ptr]);
                --ptr;                
            }                    
            res += tans;
        /* 
            int cur = mx;
            for1(j, L - 1, l) {
                cur = max(cur, a[j]);
                res += cur;              
            }                          
        */}
        cout << res << "\n";
    }
   
    return 0;
}