#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int p,sum=0;
	cin>>p;
	for(int i=p+1;i<=1000;++i){
		for(int j=2;j<i;++j)
		if(i%j!=0)
		sum++;
		if(sum==1)
		cout<<i;
	}
	return 0;
}
