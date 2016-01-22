#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 2e5 + 100;

int n, m, damage_enemy, damage_ally, health_ally;
int health_enemy[N];
int a[N], b[N];

inline int div_r (ll x, ll y) {
	return (x + y - 1) / y;
}

int main () {

	freopen ("army.in", "r", stdin);
	freopen ("army.out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	cin >> n >> m >> damage_enemy >> damage_ally >> health_ally;
	health_ally = div_r (health_ally, damage_enemy);
	for (int i = 1; i <= n; ++i) {
		cin >> health_enemy[i];
		health_enemy[i] = div_r (health_enemy[i], damage_ally);
	}

	if (n == 1) {
		int l = 0, r = m + 1;
		while (r - l > 1) {
			int mid = (r + l) >> 1;
			ll sum = (mid * 1ll * (mid + 1)) / 2;
			if ((sum > 1e9 && health_ally > 0) || sum * health_ally >= health_enemy[1])
				r = mid;
			else
				l = mid;
		}
		if (l == m)
			cout << -1;
		else
			cout << r;
		return 0;
	}

	
	sort (health_enemy + 1, health_enemy + n + 1);
	
	
	int l = 0, r = m + 1;

	while (r - l > 1) {
		int mid = (r + l) >> 1;
		for (int i = 1; i <= mid; ++i)
			b[i] = health_ally;
		for (int i = 1; i <= n; ++i)
			a[i] = health_enemy[i];
		int k_ally = 1, k_enemy = 1, pen_hits_on_enemy = 0, pen_hits_on_ally = 0;
		for (; k_ally <= mid && k_enemy <= n;) {
			while (k_enemy <= n && pen_hits_on_enemy >= a[k_enemy])
				pen_hits_on_enemy -= a[k_enemy++];
			while (k_ally <= mid && pen_hits_on_ally >= b[k_ally])
				pen_hits_on_ally -= b[k_ally++];
			if (k_ally > mid || k_enemy > n)
				break;
			a[k_enemy] -= pen_hits_on_enemy;
			pen_hits_on_enemy = 0;
			b[k_ally] -= pen_hits_on_ally;
			pen_hits_on_ally = 0;
			int turns = min (a[k_enemy] / (mid - k_ally + 1), b[k_ally] / (n - k_enemy + 1));
			a[k_enemy] -= turns * (mid - k_ally + 1), b[k_ally] -= turns * (n - k_enemy + 1);
			pen_hits_on_enemy = (mid - k_ally + 1);
			pen_hits_on_ally = (n - k_enemy + 1);
		}
		if (k_enemy > n)
			r = mid;
		else
			l = mid;
	}

	if (l == m)
		cout << -1;
	else
		cout << r;
	return 0;
}