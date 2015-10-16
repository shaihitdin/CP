#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "luigi."     
#define F first
#define S second
#define pb push_back   
#define _bits __builtin_popcount

typedef unsigned long long ll;    
typedef pair <int, int> PII;
                                                                               
const int N = 3e5;                                                                                              
const int INF = 2e9 + 9;  
const ll B = (1LL << 32);     
const ll b = (1LL << 31);

int q;         

ll bin_pow(ll x, ll power) {
	ll res = 1;
	while (power) {
		if (power & 1)
			res = (res * x) % B;
		x = (x * x) % B, power >>= 1;
    }
    return res;
}

ll mod_inv(ll x) {
	ll ans = bin_pow(x, b - 1);     
	assert((x * ans) % B == 1);
	return ans;
}

ll bit(ll mask, int pos) {
	return (mask >> pos) & 1;
}

ll rev_xor(ll x, int s) {
	ll res = 0;
	for1(i, 31, 31 - s + 1)
		res |= (bit(x, i) << i); 
	for1(i, 31 - s, 0) {
		ll cur = (bit(x, i) ^ bit(res, i + s));
		res |= (cur << i); 
	}	
	ll mine = (res ^ (res >> s));     
	assert(mine == x);
	return res;
}

ll super_hot_hash(unsigned int hash) {
	hash = hash + (hash << 10);
	hash = hash ^ (hash >> 6);
	hash = hash + (hash << 3);
	hash = hash ^ (hash >> 11);
	hash = hash + (hash << 16);
	return hash;
}

int main () {        
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout); 

	ios_base :: sync_with_stdio (0);                                                                                           
	cin.tie(0); 

	cin >> q;                          
	forn(i, 1, q) {
		ll oh = 0, hash = 0, x = 0;
		cin >> oh;
		hash = oh;
                             
		x = (hash * mod_inv((1 << 16) + 1)) % B;
		hash = x;            

	    hash = rev_xor(hash, 11);

	    x = (hash * mod_inv((1 << 3) + 1)) % B;
	    hash = x;

	    hash = rev_xor(hash, 6);

	    x = (hash * mod_inv((1 << 10) + 1)) % B;
	    cout << x << "\n";
//	    cerr << x << " " << super_hot_hash(x) << "\n";
		assert(oh == super_hot_hash(x));
	}

    return 0;         	
}