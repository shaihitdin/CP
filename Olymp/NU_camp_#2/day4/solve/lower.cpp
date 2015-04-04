#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;
#define mkp make_pair
#define NAME ""
const int N=5001;
set<int> st;
int n,i;
int main(){
//	freopen(NAME"in","r",stdin);
//	freopen(NAME"out","w",stdout);
		cin>>n;
		for(i=1;i<=n;i+=2)
		  st.insert(i);
		  for(i=2;i<=n;i+=2)
		   cout<<*st.lower_bound(i-1)<<" ";
return 0;}
