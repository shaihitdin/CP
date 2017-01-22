#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
			}
		}
	int k,l,r;
	k=0;
	l=0;
	r=10000;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(k<a[i][j]){
				k=a[i][j];
				}

			}
		}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(k==a[i][j] & r!=i){
				l=l+1;
				r=i;
				}
			}
		}
	cout<<l;
	return 0;	
}     