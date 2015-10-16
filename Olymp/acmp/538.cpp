# include <bits/stdc++.h>
 
using namespace std;
 
typedef long double ld;
typedef long long ll;
 
const ll maxN = ll(8e5);
const ll oo = ll(1e18);
const ll lmaxN = ll(2e6);
const ll MASK = (1LL << 25);
const ll MOD = (1e9);
const ld EPS = ld(1e-9);
 
ll n, x[maxN], y[maxN];
vector<ll>g[1300];
ll c[1300], u[1300];
ll flag = 0;
 
void Dfs(ll v, ll p){
    u[v] = 1;
    for(auto i : g[v]){
        if(i != p){
            if(u[i]){
                flag |= (c[i] == c[v]);
            }
            else{
                c[i] = c[v] ^ 1;
                Dfs(i, v);
            }
        }
    }
}
 
inline ld GetDist(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
 
bool Check(ld val){
    val *= 2.0;
    flag = 0;
    for(ll i = 0; i <= 1299; ++i){
        g[i].clear();
        c[i] = 0, u[i] = 0;
    }
 
    for(ll i = 1; i <= n; ++i){
        for(ll j = i + 1; j <= n; ++j){
            if(GetDist(x[i], y[i], x[j], y[j]) <= val){
                g[j].emplace_back (i);
            }
        }
    }
 
    for (int i = 1; i <= n; ++i)
    	for (int to : g[i])
    		g[to].emplace_back (i);

    for(ll i = 1; i <= n; ++i){
        if(!u[i]){
            Dfs(i, 0);
        }
    }
    return !flag;
}
 
ld Bin(){
    ld lf = 0.0, rg = 1e4;
    for (int cnt = 0; cnt < 40; ++cnt) {
        ld mid = (lf + rg) / 2.0;
        if(Check(mid)){
            lf = mid;
        }
        else{
            rg = mid;
        }
    }
    ld ans;
    if(Check(rg)){
        ans = rg;
    }
    else{
        Check(lf);
        ans = lf;
    }
    return ans;
}
 
int main(){
 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(ll i = 1; i <= n; ++i){
        cin >> x[i] >> y[i];
    }
    cout << setprecision(18) << Bin()  << "\n";
    for(ll i = 1; i <= n; ++i){
        cout << c[i] + 1 << " ";
    }
    return 0;
}