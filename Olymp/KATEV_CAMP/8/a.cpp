#include<iostream>
#include<stdio.h>
#include<string>
#include<assert.h>
#include<vector>
#include<algorithm>
#include<set>
#define mkp make_pair
#define F first
#define S second
using namespace std;
const int inf=100000001;
string s[6][100002],st,fn;
int pref[6][100002][11],i,n[6],j,k,d[6][100002],l,l_bin,r_bin,mid,ans,p[6][100002],prev[6][100002];
vector<pair<int, pair<int,int> > > v[6][100002];
bool cmp(const pair<int, pair<int, int> > &lhs, const pair<int, pair<int, int> > &rhs){
	return lhs.S.S<rhs.S.S;
}
set<pair<int,int> > set1;
vector<string> res;
int main(){
	freopen("sms.in","r",stdin);
	freopen("sms.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>st;
	cin>>fn;
	for(i=1;i<=5;++i){
		cin>>n[i];
		for(j=1;j<=n[i];++j){
			cin>>s[i][j];
		}
	}
	++n[1];
	s[1][n[1]]=st;
	++n[5];
	s[5][n[5]]=fn;
	for(i=1;i<=5;++i)
		sort(s[i]+1,s[i]+(n[i])+1);
	for(i=1;i<=5;++i)
		for(j=1;j<=n[i];++j)
			d[i][j]=inf;
	for(i=1;i<=n[1];++i)
		if(s[1][i]==st)	d[1][i]=0;
	for(i=1;i<=5;++i){
		pref[i][1][0]=1;
		for(j=2;j<=n[i];++j){
			if(s[i][j][0]==s[i][j-1][0])
				pref[i][j][0]=pref[i][j-1][0];
			else
				pref[i][j][0]=j;
		}
		for(k=1;k<10;++k){
			pref[i][1][k]=1;
			for(j=2;j<=n[i];++j){
				if(s[i][j][k]==s[i][j-1][k] && pref[i][j][k-1]<=j-1)
					pref[i][j][k]=pref[i][j-1][k];
				else
					pref[i][j][k]=j;
			}
		}
	}
	for(i=1;i<=5;++i){
			l=1;	
			for(j=1;j<=n[i];++j){
				v[i][1].push_back(mkp(d[i][j]+10,mkp(j,0)));
				v[i][n[i]].push_back(mkp(d[i][j]+10,mkp(j,1)));			
				for(k=0;k<10;++k){
					while(l<=n[i] && (s[i][l][k]<s[i][j][k] ))	++l;
					if(l>n[i])	break;
					if(s[i][l][k]!=s[i][j][k])	break;
					l_bin=l;
					r_bin=n[i]+1;
					while(r_bin-l_bin>1){
						mid=(r_bin+l_bin)/2;
						if(pref[i][mid][k]==pref[i][l][k]){
							l_bin=mid;					
						}
						else{
							r_bin=mid;
						}
					}
					v[i][l].push_back(mkp(d[i][j]+(10-(k+1)),mkp(j,0)));
					v[i][l_bin].push_back(mkp(d[i][j]+(10-(k+1)),mkp(j,1)));
			    }
			}
		for(j=1;j<=n[i];++j){
			sort(v[i][j].begin(),v[i][j].end(),cmp);
			for(k=0;k<v[i][j].size() && v[i][j][k].S.S==0;++k)
				set1.insert(mkp(v[i][j][k].F,v[i][j][k].S.F));
			if(set1.begin()!=set1.end()){
				if(d[i][j]>set1.begin()->F){
					p[i][j]=(set1.begin()->S);
					d[i][j]=set1.begin()->F;
					prev[i][j]=0;
				}
			}
			for(;k<v[i][j].size() && v[i][j][k].S.S==1;++k)
				set1.erase(mkp(v[i][j][k].F,v[i][j][k].S.F));
		}
		set1.clear();
		if(i==5)	break;
		l=1;
			for(j=1;j<=n[i];++j){
					v[i+1][1].push_back(mkp(d[i][j]+10,mkp(j,0)));
					v[i+1][n[i+1]].push_back(mkp(d[i][j]+10,mkp(j,1)));			
					for(k=0;k<10;++k){
						while(l<=n[i+1] && (s[i+1][l][k]<s[i][j][k] ))	++l;
						if(l>n[i+1])	break;
						if(s[i+1][l][k]!=s[i][j][k])	break;
						l_bin=l;
						r_bin=n[i+1]+1;
						while(r_bin-l_bin>1){
							mid=(r_bin+l_bin)/2;
							if(pref[i+1][mid][k]==pref[i+1][l][k]){
								l_bin=mid;					
							}
							else{
								r_bin=mid;
							}
						}
						v[i+1][l].push_back(mkp(d[i][j]+(10-(k+1)),mkp(j,0)));
						v[i+1][l_bin].push_back(mkp(d[i][j]+(10-(k+1)),mkp(j,1)));
					}
			}
		for(j=1;j<=n[i+1];++j){
			sort(v[i+1][j].begin(),v[i+1][j].end(),cmp);
			for(k=0;k<v[i+1][j].size() && v[i+1][j][k].S.S==0;++k)
				set1.insert(mkp(v[i+1][j][k].F,v[i+1][j][k].S.F));
			if(set1.begin()!=set1.end()){
				if(d[i+1][j]>set1.begin()->F){
					p[i+1][j]=(set1.begin()->S);
					d[i+1][j]=set1.begin()->F;
					prev[i+1][j]=1;
				}
			}
			for(;k<v[i+1][j].size() && v[i+1][j][k].S.S==1;++k)
				set1.erase(mkp(v[i+1][j][k].F,v[i+1][j][k].S.F));
		}		
		set1.clear();
	}
	for(i=1;i<=5;++i){
		for(j=1;j<=n[i];++j){
			cerr<<s[i][j]<<" "<<d[i][j]<<"\n";
		}
		cerr<<"\n\n";
	}
	for(i=1;i<=n[5];++i){
		if(s[5][i]==fn){
			cout<<d[5][i]<<" ";
			int pos=i;
			int posx=5;
			while(d[posx][pos]!=0){
				res.push_back(s[posx][pos]);
				if(prev[posx][pos]){
					pos=p[posx][pos];
					--posx;					
				}
				else{
					pos=p[posx][pos];
				}
			}
			res.push_back(st);
			cout<<res.size()<<"\n";
			reverse(res.begin(),res.end());
			for(i=0;i<res.size();++i){
				cout<<res[i]<<"\n";
			}
			return 0;
		}
	}
	return 0;
}