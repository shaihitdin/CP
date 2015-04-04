#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
const int N=1000000*3;
const unsigned long long p=31/*,mod=1000000007*/;
string s, t, x;
unsigned long long h[N], p_pow[N], i, mid, l, r;
vector<int> ans;
int main(){
	freopen("inexact-matching.in","r",stdin);
	freopen("inexact-matching.out","w",stdout);
	ios_base :: sync_with_stdio(false);
	cin >> s >> t;
	x = s;
	s += ' ';
	s += t;
	p_pow[0] = 1;
	for(i = 1; i < s.size(); ++i){
		p_pow[i] = p_pow[i-1] * p;
	}
	for(i = 0; i<s.size(); ++i){
		h[i] = ((s[i]-32+1)*p_pow[i]);
		if(i > 0) h[i] = (h[i]+h[i-1]);
	}
	for(i = x.size()+1; i+x.size()-1 < s.size(); ++i){
		l = -1,r = x.size()-1;
		while(r-l > 1){
			mid = (r+l)/2;
			if(h[i+mid] - h[i-1] == h[mid]*p_pow[i]) {
				l = mid;
			}
			else	{
				r = mid;
			}
		}                  
		if(h[i+r-1]-h[i-1] == h[max(r-1,0*1ull)]*p_pow[i] ) {
			if(h[i+x.size()-1]-h[i+r] == (h[x.size()-1]-h[r])*p_pow[i]) {
			ans.push_back(i-x.size());
			}
		}
	}
		cout << ans.size() << "\n";
	for(i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
return 0;}