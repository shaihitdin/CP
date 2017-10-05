#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

bool banned[N];
bool is_prime[N];

int phi_f (int n) {
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

int powmod (int a, int b, int p) {
	int res = 1;
	while (b)
		if (b & 1)
			res = int (res * 1ll * a % p),  --b;
		else
			a = int (a * 1ll * a % p),  b >>= 1;
	return res;
}
 
int generator (int p) {
	vector<int> fact;
	int phi = phi_f (p-1),  n = phi;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			fact.push_back (i);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		fact.push_back (n);
 
	for (int res=p - 1; res>= 1; --res) {
		if (__gcd (res, p) != 1)
			continue;
		bool ok = true;
		for (size_t i=0; i<fact.size() && ok; ++i)
			ok &= powmod (res, phi / fact[i], p) != 1;
		if (ok)  return res;
	}
	return -1;
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		banned[x] = 1;
	}
	if (m == 1) {
		cout << "1\n1";
		return 0;
	}
	if (m == 2) {
		if (n == 0) {
			cout << "2\n1 0";
		} else if (n == 1) {
			if (banned[0]) {
				cout << "1\n1";
			} else {
				cout << "1\n0";
			}
		}
		return 0;
	}
/*	
	if (m <= 10) {
		
	}
*/	
	int x = generator (m);
	//cerr << x << "\n";
	assert (x != -1);
	vector <int> ans;	
	int now = 1;
	int tmp = 1;
	for (int i = 1; i < m; ++i) {
		now = (now * 1ll * x) % m;
		tmp = (tmp * 1ll * x) % m;
		if (!banned[now]) {
			ans.emplace_back (tmp);
			//cerr << now << " ";
			tmp = 1;
		}
	}

	//cerr << "\n";
	if (!banned[0])
		ans.emplace_back (0);
				
	cout << ans.size () << "\n";
		
	for (auto it : ans)
		cout << it << " ";
	
	/*
	for (int i = 2; i <= m; ++i)
		is_prime[i] = 1;
	
	for (int i = 2; i <= m; ++i) {
		for (int j = i + i; j <= m; j += i)
			is_prime[j] = 0;
	}	
	
	int possible = 1;
	
	for (int i = 2; i <= m; ++i) {
		if (is_prime[i] && m % i == 0)
			possible = i;
	}
	
	vector <int> ans;
	int now = 1;
	int tmp = 1;
	for (int i = 1; i < m; ++i) {
		now = (now * 1ll * i) % m;
		tmp = (tmp * 1ll * i) % m;
		if (!banned[now]) {
			ans.emplace_back (tmp);
			tmp = 1;
		}
	}
	
	if (!banned[0])
		ans.emplace_back (0);
				
	cout << ans.size () << "\n";
		
	for (auto it : ans)
		cout << it << " ";
	*/
	return 0;
}