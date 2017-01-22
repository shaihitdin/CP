#include <bits/stdc++.h>

using namespace std;

#define sc scanf
#define pr printf
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back

long long t1[300000], a[300000];
pair <long long, int> t2[300000];
int nn,n, m;

void build (int v, int ll, int rr){
	if (ll == rr){
		t1[v] = a[ll];
		t2[v] = mp(a[ll], ll);
	}
	else {
		int mid = (ll + rr) / 2;
		build (v +v, ll, mid);
		build (v +v + 1, mid + 1, rr);
		t1[v] = t1[v + v] + t1[v + v + 1];
		t2[v] = max(t2[v + v], t2[v + v + 1]);
	}
}


void update (int v, int ll, int rr, int pos, int res){
	if (ll == rr){
		t1[v] = res;
		t2[v].f = res;
	}
	else{
		int mid = (ll + rr) / 2;
		if (pos <= mid) update(v + v, ll, mid, pos, res);
		else update(v +v + 1, mid + 1, rr, pos, res);
		t1[v] = t1[v + v] + t1[v +v + 1];
		t2[v] = max(t2[v +v], t2[v+ v+ 1]);
	}
}

pair <long long, int> maxi (int v, int ll, int rr ,int l, int r){
	if (ll > r || rr < l) return mp(-1, -1);
	if (ll >= l && rr <= r) return t2[v];
	int mid = (ll + rr) /2;
	return max (maxi (v + v, ll, mid, l, r), maxi (v + v + 1, mid + 1, rr, l, r));
}

long long sum (int v, int ll, int rr ,int l, int r){
	if (ll > r || rr < l) return 0ll;
	if (ll >= l && rr <= r) return t1[v];
	int mid = (ll + rr) / 2;
	return sum(v + v, ll, mid, l, r) + sum (v + v + 1, mid + 1, rr, l, r);
}

main (){
	int ii = 0;
	while (~sc("%d", &n)){
		++ii;
		pr("Case #%d:\n", ii);
		for (int i = 0; i < n; i++){
			sc("%lld", &a[i]);
		} 
		build (1, 0, n - 1);
		sc("%d", &m);
		for (int i = 0; i < m; i++){
			int x, y, tt;
			sc("%d%d%d", &tt, &x, &y);
			x--;
			y--;
			if (x > y) swap(x, y);
			if (tt){
				pr("%lld\n", sum(1, 0, n - 1, x, y));
			}
			else {
				vector <pair <int, int> > v;
				while (1){
					pair <long long, int > pp = maxi (1, 0, n - 1, x, y);
					if (pp.f <= 1) break;
					pp.f = sqrt(pp.f);
					
					v.eb(pp.f, pp.s);
					update(1, 0, n - 1, pp.s, -1);
				}
				for (int i = 0; i < v.size(); i++){
					pair <int, int> pp1 = v[i];
					//cout << pp1.f << " " << pp1.s << endl;
					update(1, 0, n - 1, pp1.s, pp1.f);
				}
			}
		}
	}
}
