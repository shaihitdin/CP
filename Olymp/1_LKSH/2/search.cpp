#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
const int N=100001*2;
int old_n, z[N], i, l, r;
string a, b;
vector<int> ans;
int main(){
	freopen("search.in","r",stdin);
	freopen("search.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin >> b >> a;
	old_n = a.size();
	a += '#';
	a += b;
	for(i=1, l=0, r=0; i<a.size(); ++i){
		if(i < r){
			z[i] = min(r-i+1,z[i-l]);
		}
		while(i+z[i] < a.size() && a[z[i]] == a[i+z[i]]) ++z[i];
		if(i+z[i]-1 > r){
			l = i, r = i+z[i]-1;
		}
	}
	for(i = old_n+1; i<a.size(); ++i)
		if(z[i] == old_n) ans.push_back(i-old_n);
	cout << ans.size() << "\n";
	for(i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
return 0;}