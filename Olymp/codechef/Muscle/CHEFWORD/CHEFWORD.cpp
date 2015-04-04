#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
using namespace std;
int t,n,k;
string s,q;
double x,ans,tmp,sum;
vector <vector <double> > multiply (vector <vector <double> > a, vector <vector <double> > b) {
	vector<vector <double> > c;
	c.resize(27);
	for (int i = 1; i <= 26; ++i) 
		c[i].resize(27);
	
	for (int i = 1; i <= 26; ++i) 
		for (int j = 1; j <= 26; ++j) 
			for (int l = 1; l <= 26; ++l) 
				c[i][j] += (a[i][l] * b[l][j]);
	return c;
}
/*
vector <vector <double> > to_pow (vector <vector <double> > a, int p) {
	if (p == 1) {
		return a;
	}
	else {
		return multiply (a, to_pow (a, p - 1));
	}
}
*/

vector <vector <double> > to_pow (vector <vector <double> > a, int p) {
	vector <vector <double> > res;
	res.resize(27);
	for (int i = 1; i <= 26; ++i) 
		res[i].resize(27);
	if (p == 0) {
		for (int i = 1; i <= 26; ++i)
			res[i][i] = 1;
		return res;
	}
	if (p % 2 == 1) {
		return multiply (to_pow (a, p - 1), a);
	}
	else {
		res = to_pow (a, p / 2);
		return multiply (res, res);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin>>t;
	++t;
	cout.precision(20);
	while(--t) {
		cin>>n>>k;
		cin>>s;
		vector<vector<double> > g, cc;
		g.resize(27);
		for(int i = 1; i <= 26; ++i) {
			g[i].resize(27);
			for(int j = 1; j <= 26; ++j) { 
				cin>>g[i][j];
			}
		}
		cc = to_pow(g, k - 1);
		ans = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> q;
			if (q.size() != s.size())
				continue;
			tmp = 1;
		    for(int j = 0; j < s.size(); ++j) {
		    	sum = 0;
		    	for(int l = 1; l <= 26; ++l) 
		    		sum += (g[s[j] - 'a' + 1][l] * cc[l][q[j] - 'a' + 1]);
		        tmp*=sum;
		    }
		    ans += tmp;
		}
		cout<<ans<<"\n";
	}
	return 0;
}