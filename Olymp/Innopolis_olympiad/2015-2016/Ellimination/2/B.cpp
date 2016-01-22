#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
typedef long double ld;
  
struct fraction {
    ll x, y;
    fraction () {
        x = y = 0;
    }
    fraction (const ll &xx, const ll &yy) {
        x = xx;
        y = yy; 
    }
};
 
inline bool operator < (const fraction &a, const fraction &b) {
    return a.x < b.x;
}

inline bool operator ^ (const fraction &a, const fraction &b) {
    return a.x * b.y < b.x * a.y;
}

inline fraction operator - (const fraction &a, const fraction &b) {
    return fraction (a.x * b.y - b.x * a.y, a.y * b.y);
}
 
inline bool operator == (const fraction &a, const fraction &b) {
	return a.x == b.x && a.y == b.y;
}

inline fraction abs (fraction a) {
    if (a.x < 0)
        a.x = -a.x;
    return a;
}

int main () {
    freopen ("approximate.in", "r", stdin);
    freopen ("approximate.out", "w", stdout);
   
    int a, b, n, sddf;
       
    cin >> a >> b >> n;
    
    sddf = __gcd (a, b);
    a /= sddf;
    b /= sddf;
    
    fraction s = fraction (a, b);
       
    int ans = 0;
       
    fraction pre = fraction (2 * b, b);
       
    ld s_d = ld (a) / b;
    
    n = min (n, b);
    
    for (int i = 1; i <= n; ++i) {
        ld step = 1.0 / i;
        int step_cnt = s_d / step;
        fraction we = fraction (0, i);
        for (int j = max (0, step_cnt - 2); j <= min (i, step_cnt + 2); ++j) {
            if (abs (fraction (j, i) - s) < abs (we - s))
                we = fraction (j, i);
        }
        fraction tmp1 = abs (we - s);
        fraction tmp2 = abs (pre - s);
        tmp1.y /= b;
        tmp2.y /= b;
        //cerr << "(" << ld (tmp1.x) << " / " << tmp1.y << ") (" << ld (tmp2.x) << " / " << tmp2.y << ")\n";
        if (tmp1 ^ tmp2) {
            pre = we;
	        for (int j = max (0, step_cnt - 2); j <= min (i, step_cnt + 2); ++j)
	            if (abs (fraction (j, i) - s) == abs (we - s))
	                ++ans;
    	}
    }
       
    cout << ans;
    return 0;
}