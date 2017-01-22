#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a,b,c,h,p;
	cout<<"Enter Your Numbers\n";
	cin>>a>>b>>c>>h;
	p=a+b+c;
	double S;
	S=sqrt(p*(p-a)*(p-b)*(p-c));
	cout<<S<<endl;
	double V;
	V=S*h/2;
	cout<<V<<endl;
	return 0;
	}
