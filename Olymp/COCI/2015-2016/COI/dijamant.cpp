/// Forever

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

#define pii pair<int, int>
  
#define pb push_back
#define mp make_pair
  
#define f first
#define s second
  
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7, N = 12;

map <string, int> vertex;
bitset <N> p[N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	

	int n;	
	
	cin >> n;

	for (int id = 1; id <= n; ++id) {
		string name;
		cin >> name;
		bool flag = 0;
		if (vertex.count (name)) {
			flag = 1;
		}
		string smth;
		cin >> smth;
		vector <int> pa;
		while (cin >> smth) {
			if (smth == ";")
				break;
			if (!vertex.count (smth)) {
				flag = 1;
				continue;
			}
			pa.emplace_back (vertex[smth]);
		}
		if (flag == 1) {
			cout << "greska\n";
			continue;
		}
		
		sort (pa.begin (), pa.end ());
		reverse (pa.begin (), pa.end ());

		for (int v : pa) {
			if (p[id][v]) {
				//cerr << "BEK1";
				continue;
			}
			if ((p[id] & p[v]) != p[N - 1]) {
				//cerr << "BEK2";
				flag = 1;
			} else {
				//cerr << "BEK3";				
				p[id] |= p[v];
			}
		}
		if (flag) {
			cout << "greska\n";
			continue;
		}

		vertex[name] = id;		
		for (auto v : pa)
			p[id][v] = 1;
		cout << "ok\n";
	}
	return 0;
}