#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "robot."     
#define F first                       
#define S second 
#define pb push_back   

typedef long long ll; 
typedef pair <int, int> PII;
typedef double ld;
                                                                                          
const int N = 2e6; 
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
   
int n, k;
int a[N];

bool cmp(int a, int b) {
	return abs(a) < abs(b);
}

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);                               

	ios_base :: sync_with_stdio (0);
	cin.tie(0);

	cin >> n >> k;
	forn(i, 1, n)
		cin >> a[i];

	vector <int> v (a + 1, a + 1 + n);	
	sort(v.begin(), v.end());	
	forn(i, 0, k - 1)
		if (v[i] < 0)
			v[i] *= -1;
	ll sum1 = 0;
	forn(i, 0, n - 1) 
		sum1 += v[i];

	vector <int> w (a + 1, a + 1 + n);	
	sort(w.begin(), w.end(), greater <int> ());	
	forn(i, 0, k - 1)
		if (w[i] > 0)
			w[i] *= -1;
	ll sum2 = 0;
	forn(i, 0, n - 1) 
		sum2 += w[i];

	cout << max(sum1, -sum2) << "\n";

	return 0;         	
}                   
