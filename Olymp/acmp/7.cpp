#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
  
using namespace std;
  
typedef long long ll;
typedef vector <ll> bg;
 
vector <ll> primes;
 
const ll base = 1e9;
const ll inf = 1e18;
 
 
inline void bg_short (bg &x) {
    while (x.size () && !x.back ())
        x.pop_back ();
}
 
inline bg operator + (const bg &a, const int &b) {
    bg res = a; 
    if (!res.size ())
        res.push_back (0);
    res.push_back (0);
 
    res[0] += b;
    for (int i = 0; i < a.size (); ++i) {
        res[i + 1] += (res[i] / base);
        res[i] %= base;
    }
    bg_short (res);
    return res;
}
 
inline bool operator < (const bg &a, const bg &b) {
    if (a.size () != b.size ())
        return a.size () < b.size ();
    for (int i = a.size () - 1; i >= 0; --i)
        if (a[i] != b[i])
            return a[i] < b[i];
    return 0;
}
 
inline bool operator > (const bg &a, const bg &b) {
    return b < a;
}
 
inline bg operator + (const bg &a, const bg &b) {
    bg res = a;
    res.resize (max (a.size (), b.size ()) + 10);
    int carry = 0;
     
    for (int i = 0; i < b.size (); ++i) {
        res[i] += b[i] + carry;
        carry = res[i] / base;
    }
 
    for (int i = b.size (); i < res.size () && carry; ++i) {
        res[i] += carry;
        carry = res[i] / base;
    }
 
    bg_short (res);
    
    return res;
}
 
inline void printnum (bg &a) {
    if (!a.size ())
        a.push_back (0);
    reverse (a.begin (), a.end ());
     
    cout << a[0];
    for (int i = 1; i < a.size (); ++i) {
        cout << setfill ('0') << setw (9);
        cout << a[i];
    }   
    reverse (a.begin (), a.end ());
}
 
inline bg to_bg (string &a) {
    bg res;
    reverse (a.begin (), a.end ());
    for (int i = 0; i < a.size (); i += 9) {
        int temp = 0, pp = 1;
        for (int j = 0; j < 9 && i + j < a.size (); ++j, pp *= 10)
            temp += ((a[i + j] - '0') * pp);
        res.push_back (temp);
    }
    reverse (a.begin (), a.end ());
    return res;
}
 
int main () {
 
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
 
     
    string x, y, z;
 
    cin >> x >> y >> z;
 
    bg a[4];
 
    a[1] = to_bg (x);
    a[2] = to_bg (y);
    a[3] = to_bg (z); 
     
    sort (a + 1, a + 3 + 1);
 
    printnum (a[3]);
     
    return 0;
}