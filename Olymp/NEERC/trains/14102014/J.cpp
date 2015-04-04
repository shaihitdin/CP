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
#define for1(i, n, x) for(int i = n; i >= x; --i)
#define file "jealous."
#define pb push_back
 
typedef long long ll;
                                             
const int maxn = 1024;
const int INF = int(2e9) + 7;
               
ll a, b, p, q;
 
bool lss(ll x, ll y, ll z) {
        if (x * y < 0) return 0;
        return (x * y < z);
}
 
ll solve (ll x) {    cerr<<"-\n";
        if (!x) return 0;
        ll ans = 0;
        ll base1 = 1, base2 = 1;
        for (int i = 1; lss(base1, p, x); ++i) {
                base1 *= p;
                base2 = base1;
                for (int  j = 0; j < i; ++j) {
                        ll need = x / base2;
                        cerr<<p<<" "<<i<<" "<<q<<" "<<j<<" "<<base2<<" "<<(need - need / 2 - need / 3)<<"\n";
                        ans += (need - need / 2 - need / 3 + need / 6);
                        if (!lss(base2, q, x)) break;
                        base2 *= q;    
                }
        }       if (x == a - 1) cerr<<ans<<"\n";                    
        return ans;
}
 
int main() {
        freopen(file"in", "r", stdin);
        freopen(file"out", "w", stdout);
 
        ios_base :: sync_with_stdio(0);
 
        scanf("%I64d %I64d %I64d %I64d", &a, &b, &p, &q);
        printf("%I64d", solve(b) - solve(a - 1));
 
        return 0;      
}