#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long col[4], d[1002][200002], i, j; 
int main() {
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>col[1]>>col[2];
	d[0][col[1]]=1;
	d[0][col[2]]=1;

		for(i=0;i<5;++i){
			for(j=7;j>=0;--j){
				//if(!d[i][j])	continue;
				d[i][j]=(d[i][j]+d[i][j+1]);
				if(j-(i+1)>=0)
					d[i+1][j-(i+1)]=(d[i+1][j-(i+1)]+d[i][j]);
				cerr<<d[i][j]<<" ";
			}
			cerr<<"\n";
		}		
	for(i=5;i>=1;--i){
		if(d[i][0]){
			cout<<d[i][0];
			return 0;
		}
	}
	return 0;
}