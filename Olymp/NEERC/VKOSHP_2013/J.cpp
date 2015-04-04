#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i)
#define F first
#define S second
#define mkp make_pair
const int N = 501, inf = 100000001;
set < pair <int, pair <int, int> > > st;
pair <int,int> p[N][N];
int d[N][N],n,m,k,pos1,pos2,tmp;
vector<pair<int,int> > tmpp;
char a[N][N];
int main() {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> n >> m >> k;
	forn (i, 1, n) {
		forn (j, 1, n) {
			cin >> a[i][j];
			if (a[i][j] == 'V') {
				st.insert ( mkp (0, mkp(i,j) ) );
			}
			d[i][j] = inf;
		}
	}
	while(st.size()) {
		pos1=st.begin()->S.F;
		pos2=st.begin()->S.S;
		st.erase(st.begin());
		if(pos1 - 1 >= 1) {
			if(d[pos1-1][pos2] > d[pos1][pos2]+1) {
				st.erase(mkp(d[pos1-1][pos2],mkp(pos1-1,pos2)));
				d[pos1-1][pos2] = d[pos1][pos2]+1;
				p[pos1-1][pos2] = mkp(pos1,pos2);
				st.insert(mkp(d[pos1-1][pos2],mkp(pos1-1,pos2)));
			}
		}
		if(pos1 + 1 <= n) {
			if(d[pos1+1][pos2] > d[pos1][pos2]+1) {
				st.erase(mkp(d[pos1+1][pos2],mkp(pos1+1,pos2)));
				d[pos1+1][pos2] = d[pos1][pos2]+1;
				p[pos1+1][pos2] = mkp(pos1,pos2);
				st.insert(mkp(d[pos1+1][pos2],mkp(pos1+1,pos2)));
			}		
		}
		if(pos2 + 1 <= m) {
			if(d[pos1][pos2+1] > d[pos1][pos2]+1) {
				st.erase(mkp(d[pos1][pos2+1],mkp(pos1,pos2+1)));
				d[pos1][pos2+1] = d[pos1][pos2]+1;
				p[pos1][pos2+1] = mkp(pos1,pos2);
				st.insert(mkp(d[pos1][pos2+1],mkp(pos1,pos2+1)));
			}		
		}
		if(pos2 - 1 >= 1) {
			if(d[pos1][pos2-1] > d[pos1][pos2]+1) {
				st.erase(mkp(d[pos1][pos2-1],mkp(pos1,pos2-1)));
				d[pos1][pos2-1] = d[pos1][pos2]+1;
				p[pos1][pos2-1] = mkp(pos1,pos2);
				st.insert(mkp(d[pos1][pos2-1],mkp(pos1,pos2-1)));
			}		
		}
	}
	forn(i, 1, n) {
		forn(j,1,n){
			if(a[i][j]=='T'){
				if(tmp > d[i][j]) {
					tmp = d[i][j];
					pos1 = i;
					pos2 = j;
				}
			}
		}
	}
	v.push_back(pos1,pos2);
	while(d[pos1][pos2]!=0) {
		v.push_back(mkp(p[pos1][pos2]));
		p[pos1][pos2].F = pos1;
		p[pos1][pos2].S = pos2;
	}
	for(i=v.size()-1;i>1;--i){
		pos1=v[i].F;
		pos2=v[i].S;
		pos3=v[i-1].F;
		pos4=v[i-1].S;
		if(pos1-pos3 == -1){
			cout<<"N";
		}
		if(pos1-pos3 == 1){
			cout<<"S";
		}
		if(pos2-pos4 == -1){
			cout<<"E";		
		}		
		if(pos2-pos4 == 1){
			cout<<"W";
		}
	}
	--k;
	if(k==0){
		return 0;
	}
	while(k!=1){
		
	}
	return 0;
}