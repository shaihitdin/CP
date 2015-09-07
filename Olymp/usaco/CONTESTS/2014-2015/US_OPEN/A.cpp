#include <bits/stdc++.h>

using namespace std;

bool flag;

typedef vector <short> num;

const short base = 10;

inline num operator + (const num &a, const num &b) {
	num c (max (a.size(), b.size()), 0);
	short carry = 0;
	for (short i = 0; i < c.size () || carry; ++i) {
		if (i == c.size())
			c.push_back (0);
		c[i] = carry + (i < a.size() ? a[i] : 0) + (i < b.size() ? b[i] : 0);
		carry = c[i] / base;
		if (carry)
			c[i] -= base;
	}
	return c;
}

inline num dfs (const string &v) {
	
	cout << v << "\n";
	cout.flush();
	string c1, c2;
	
	cin >> c1 >> c2;
	
	assert (!(c1 == "0" && c2 != "0"));

	if (c1 != "0" && c2 == "0") {
		flag = 1;
		num temp;
		temp.push_back (2);
		return temp;
	}	
	
	if (c1 == "0" && c2 == "0") {
		num temp;
		temp.push_back (1);
		return temp;
	}
	
	num temp = dfs (c1);
	
	if (flag) {
		num temp1 = temp + temp;
		return temp1;
	}
	
	else {
		num temp1;
		temp1.push_back (1);
		return temp + temp + temp1;
	}
}

int main () {
	/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	
	//ios_base :: sync_with_stdio (0);
	
	num temp = dfs ("1");
	
	reverse (temp.begin(), temp.end());
	
	cout << "Answer ";
	
	for (auto it : temp)
		cout << it;
	cout << "\n";
	cout.flush();
	return 0;
}