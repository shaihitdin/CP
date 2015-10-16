#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 100;

int st[N], enq;
int l[N], r[N];
ll a[N];
int n;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i) {
		while (enq && a[st[enq]] < a[i])
			--enq;
		if (enq) {
			l[i] = st[enq] + 1;
		} else {
			l[i] = 1;
		}
		st[++enq] = i;
	}	
	
	enq = 0;
	
	for (int i = n; i >= 1; --i) {
		while (enq && a[st[enq]] <= a[i])
			--enq;
		if (enq) {
			r[i] = st[enq] - 1;
		} else {
			r[i] = n;
		}
		st[++enq] = i;
	}	

	ll sum = 0;

	for (int i = 1; i <= n; ++i)
		sum += a[i] * (r[i] - i + 1) * (i - l[i] + 1);
	
	enq = 0;
		
	for (int i = 1; i <= n; ++i) {
		while (enq && a[st[enq]] > a[i])
			--enq;
		if (enq) {
			l[i] = st[enq] + 1;
		} else {
			l[i] = 1;
		}
		st[++enq] = i;
	}	
	
	enq = 0;
	
	for (int i = n; i >= 1; --i) {
		while (enq && a[st[enq]] >= a[i])
			--enq;
		if (enq) {
			r[i] = st[enq] - 1;
		} else {
			r[i] = n;
		}
		st[++enq] = i;
	}	

	for (int i = 1; i <= n; ++i)
		sum -= a[i] * (r[i] - i + 1) * (i - l[i] + 1);

	cout << sum;
	
	return 0;
}