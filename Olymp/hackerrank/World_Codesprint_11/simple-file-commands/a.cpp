#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

map <string, int> Map;
map <string, set <int> > Set;


inline void del (string x) {
	int val = 0, st = 0;
	if (x.back () == ')') {
		st = x.size () - 2;
		while (isdigit (x[st--]));
		st += 2;
		val = atoi (x.substr (st, x.size () - 2 - st + 1).c_str());
		//cerr << x.substr (st, x.size () - 2 - st + 1).c_str() << " !!!";		
	} else {
		st = x.size () + 1;
	}
	Set[x.substr (0, st - 1)].insert (val);
	//cerr << x.substr (0, st - 1) << " ";
}

inline string to_string_ (int x) {
	stringstream ss;
	ss << x;
	string t;
	ss >> t;
	return t;
}

inline string add (string x) {
	if (Set[x].size ()) {
		int val = *Set[x].begin ();
		Set[x].erase (Set[x].begin ());
		if (val == 0) {
			return x;
		} else {
			return x + "(" + to_string_ (val) + ")";
		}
	}
	Map[x]++;
	if (Map[x] == 1) {
		return x;
	}
	return x + "(" + to_string_ (Map[x] - 1) + ")";
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int q;

	cin >> q;

	while (q--) { 
		string q_type;
		cin >> q_type;
		if (q_type == "crt") {
			string a;
			cin >> a;
			cout << "+ " << add (a) << "\n";
		} else if (q_type == "del") {
			string a;
			cin >> a;
			del (a);		
			cout << "- " << a << "\n";
		} else {
			string a, b;
			cin >> a >> b;
			del (a);
			cout << "r " << a << " -> " << add (b) << "\n";
		}
	
	}
	
	return 0;
}